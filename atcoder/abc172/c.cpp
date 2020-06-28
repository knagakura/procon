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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    vector<ll> B(M);
    rep(i, M)cin >> B[i];
    vector<ll> cumA(N+1,0);
    vector<ll> cumB(M+1,0);
    rep(i,N)cumA[i+1] = cumA[i] + A[i];
    rep(i,M)cumB[i+1] = cumB[i] + B[i];
    //X冊読むとしたときにK分以内にできるか(O(N+M));
    auto check = [&](ll X){
        ll minn = INFLL;
        rep(i,N+1){
            ll j = X - i;
            if(j > M)continue;
            if(j < 0)continue;
            chmin(minn, cumA[i] + cumB[j]);
        }
        return minn <= K;
    };
    ll ok = 0;
    ll ng = N+M+1;
    while(ng - ok > 1){
        ll mid = (ok + ng) >> 1;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}