#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {os << "{" <<p.first << ", " << p.second << "}";return os;}
struct fast_ios{ fast_ios(){cin.tie(0);ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#ifdef DEBUG
#define dump(x) cerr<<#x<<": "<<x<<endl;
#else
#define dump(x)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    ll ans = INFLL;
    for(int i = 0; i < N; i++){
        // if(i + M > N)continue;
        string tmp = S.substr(i, M);
        if(tmp.size() < M)continue;
        dump(tmp);
        ll cnt = 0;
        rep(j,M)cnt += T[j] != tmp[j];
        chmin(ans, cnt);
    }
    cout << ans << endl;
}
