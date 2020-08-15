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
const ll MOD = 1'000'000'007;
// const ll MOD = 998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

// パスカルの三角形
vector<vector<long long>> CombTable(int N){
    vector<vector<long long>> res(N+1, vector<long long>(N+1,0));
    for(int i = 0; i <= N; i++)for(int j = 0; j <= i; j++){
        if(j == 0 or j == i){
            res[i][j] = 1;
            continue;
        }
        res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i,N)cin >> v[i];
    sort(all(v), greater<>());
    long double ans = 0;
    rep(i,A)ans += v[i];
    ans /= A;
    auto C = CombTable(N);

    ll cnt = 0;
    // 全部同じ
    if(v[0] == v[A-1]){
        ll tmp = 0;
        rep(i,N)tmp += v[i] == v[0];
        for(int k = A; k <= min(B, tmp); k++){
            cnt += C[tmp][k];
        }
    }
    else{
        ll X = 0, Y = 0;
        rep(i,A){
            Y += v[i] == v[A-1]; //[0,A)にv[A-1]がいくつあるか
        }
        rep(i,N){
            X += v[i] == v[A-1];
        }
        cnt += C[X][Y];
    }

    cout << ans << endl;
    cout << cnt << endl;
}

