#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int INF = (ll)1e9;

int main() {

    // input
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i,H)cin >> S[i];

    // 区切りのbit表現から縦の領域を表すvectorに変換する
    auto bit2vec = [&](int k){
        vector<int> res;
        res.push_back(0);
        for(int l = 0; l < H-1;l++){
            if(k & bit(l)){
                res.push_back(l+1);
            }
        }
        res.push_back(H);
        return res;
    };
    // ある縦の区切り方のbit表現から区切りの最小値を出力する
    auto mini = [&](int k){
        auto div = bit2vec(k);
        int res = div.size() - 2;
        int m = div.size() - 1;
        int len = 0;
        vector<int> sum(m, 0);
        rep(j,W){
            vector<int> nxt(m, 0);
            int maxx = 0;
            rep(a, m){
                int u = div[a];
                int d = div[a+1];
                nxt[a] += sum[a];
                for(int i = u;i < d;i++){
                    nxt[a] += S[i][j] - '0';
                }
                chmax(maxx, nxt[a]);
            }
            if(maxx <= K){
                len++;
                swap(sum, nxt);
            }
            else{
                if(len == 0)return INF;
                j--;
                sum.assign(m, 0);
                res++;
                len = 0;
            }
        }
        return res;
    };
    
    // 実際の処理
    int ans = INF;
    for(int k = 0; k < bit(H-1);k++){
        chmin(ans, mini(k));
    }

    cout << ans << endl;
}