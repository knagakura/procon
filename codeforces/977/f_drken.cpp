#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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

int N;
vector<long long> a;
 
void solve() {
    cin >> N;
    a.resize(N);
    rep(i,N)cin>>a[i];
    vector<long long> vs;
    map<long long, vector<int>> pl;
    for (int i = 0; i < a.size(); ++i) {
        vs.push_back(a[i]);
        pl[a[i]].push_back(i);
    }
    sort(vs.begin(), vs.end());
    vs.erase(unique(vs.begin(), vs.end()), vs.end());
    print(vs);
    int s = vs.size();
    vector<long long> dp(s+1, 0);
    for (int i = 0; i < N; ++i) {
        int it = lower_bound(vs.begin(), vs.end(), a[i]) - vs.begin();
        if (it == 0 || a[i] != vs[it-1] + 1) dp[it] = 1;
        else chmax(dp[it], dp[it-1] + 1);
    }
 
    long long res = 0;
    long long val = -1;
    for (int i = 0; i <= s; ++i) if (chmax(res, dp[i])) val = vs[i];
 
    vector<int> ans;
    int end = N;
    for (int i = 0; i < res; ++i) {
        int it = lower_bound(pl[val].begin(), pl[val].end(), end) - pl[val].begin();
        --it;
        ans.push_back(pl[val][it]);
 
        /*
        COUT("---------------"); COUT(i);
        COUT(pl[val]);
        cout << i << ": " << val << ", " << end << " -> " << it << "(" << pl[val][it] << ")" << endl;
        */
 
        end = pl[val][it];
        --val;
    }
    reverse(ans.begin(), ans.end());
    
    cout << res << endl;
    for (int i = 0; i < res; ++i) {
        if (i) cout << " ";
        cout << ans[i]+1;
    }
    cout << endl;
}
 
int main() {
    solve();
}