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
ll N, M, B;
string S; // S.size() = N
vector<string> A; 
vec<ll> V; // 10^9

vec<ll> dp;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    // input part
    cin >> N >> M >> B >> S;
    A.resize(M);V.resize(M);
    rep(i,M){
        cin >> A[i] >> V[i];
    }

    //memo part
    map<string, ll> mp;
    map<string, int> mpcnt;
    rep(j,M){
        int sz = A[j].size();
        for(int k = 1; k < bit(10);k++){
            string tmp = "";
            int cnt = 0;
            rep(l, sz){
                if(bit(l) & k){
                    tmp.push_back(A[j][l]);
                    cnt++;
                }
            }
            if(mpcnt[tmp] == 0)mp[tmp] = V[j] - (sz - cnt) * B;
            else chmax(mp[tmp], V[j] - (sz - cnt) * B);
            mpcnt[tmp]++;
        }
    }
    /*
    for(auto p:mp){
        cerr << p.first << " " << p.second << endl;
    }
    */
    // dp part
    dp.assign(N+5, -INFLL);
    dp[0] = 0;
    rep(i,N){
        string tmp = "";
        rep(j, 10){
            if(i + j > N)continue;
            tmp.push_back(S[i + j]);
            if(mpcnt[tmp]>0)chmax(dp[i+j+1], dp[i] + mp[tmp]);
        }
    }
    cout << dp[N] << endl;
}