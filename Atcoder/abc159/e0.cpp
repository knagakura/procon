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
int H, W, K;
vector<string> S;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W >> K;
    S.resize(H);
    rep(i,H)cin >> S[i];
    ll ans = INFLL;
    //境界の状態を全探索
    rep(k,bit(H-1)){
        // l個目の境界が分かれているか
        vector<int> v;
        v.push_back(0); 
        ll cnt = 0; // 境界の本数
        rep(l, H-1){                    
            if(k & bit(l)){
                v.push_back(l+1);
                cnt++;
            }
        }
        v.push_back(H);
        vector<int> counts(int(v.size()-1),0);
        bool ok = true;
        map<int, int> map;
        rep(j,W){
            map[j]++;
            if(!ok)break;
            vector<int> nxt((int)v.size()-1, 0);
            int maxx = 0;
            rep(m, v.size()-1){
                int l = v[m];
                int r = v[m+1];
                //[l,r)行ごとに分ける
                nxt[m] = counts[m];
                //j行目の、[l,r)の足し算
                for(int i = l;i < r;i++){
                    nxt[m] += S[i][j] - '0';
                }
                chmax(maxx, nxt[m]);
            }
            if(maxx <= K){
                swap(counts,nxt);
            }
            else{
                if(map[j] >= 2)ok = false;
                j--;
                counts.assign((int)v.size()-1,0);
                cnt++;
                continue;
            }
        }
        if(ok)chmin(ans, cnt);
    }
    cout << ans << endl;
}
