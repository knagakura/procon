#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i,H)cin >> S[i];

    
    int ans = INF;
    for(int k = 0; k < bit(H-1);k++){
        int tmp = 0; //新たに入れた仕切りの数
        vector<int> div;
        div.push_back(0);
        for(int l = 0; l < H-1;l++){
            if(k & bit(l)){
                div.push_back(l+1);
                tmp++;
            }
        }
        div.push_back(H);
        //ある区切りが達成可能かどうかをcheckする
        auto check = [&](vector<int>& v){
            int m = v.size()-1;
            //ある列について
            rep(j,W){
                vector<int> divsum(m, 0);
                rep(a, m){
                    int u = v[a];
                    int d = v[a+1];
                    for(int i = u;i < d;i++){
                        divsum[a] += S[i][j] - '0';
                    }
                    if(divsum[a] > K)return false;
                }
            }
            return true;
        };//
        if(!check(div))continue;
        auto mini = [&](vector<int>& v){
            int res = tmp;
            int m = v.size() - 1;
            vector<int> sum(m, 0);
            rep(j,W){
                vector<int> nxt(m, 0);
                int maxx = 0;
                rep(a, m){
                    int u = v[a];
                    int d = v[a+1];
                    nxt[a] += sum[a];
                    for(int i = u;i < d;i++){
                        nxt[a] += S[i][j] - '0';
                    }
                    chmax(maxx, nxt[a]);
                }
                /*
                dump(j);
                print(nxt);
                dump(maxx);
                cerr << maxx << endl;
                */
                if(maxx <= K){
                    swap(sum, nxt);
                }
                else{
                    j--;
                    sum.assign(m, 0);
                    res++;
                }
            }
            return res;
        };
        /*
        cerr << endl;
        print(div);
        int res = mini(div);
        dump(tmp);
        dump(res);
        */
        chmin(ans, mini(div));
    }
    cout << ans << endl;
}