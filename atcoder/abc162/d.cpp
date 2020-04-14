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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    string cs = {'R', 'G', 'B'};
    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    cin >> N >> S;
    vvec<ll> r(3, vec<ll>(N+1,0));
    for(int i = 0;i < N;i++){
        rep(j,3)
        r[j][i+1] += r[j][i] + (S[i] == cs[j]);
    }
    ll ans = 0;
    rep(i,N)rep(j,N){
        if(i >= j)continue;
        if(S[i] == S[j])continue;
        int hoka = 3 - mp[S[i]] - mp[S[j]];
        //[i+1,j)の他の数››
        ans += r[hoka][j] - r[hoka][i+1];
        if((j - i) % 2 == 0){
            int mid = (j-i)/2 + i;
            ans -= (S[mid] == cs[hoka]);
        }
    }
    cout << ans << endl;
}