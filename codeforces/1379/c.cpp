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
void solve(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    vector<l_l> v;
    rep(i,M){
        cin >> a[i] >> b[i];
        v.emplace_back(b[i], a[i]);
    }
    // aの大きい順に並んでいる
    sort(all(a), greater<>());
    sort(all(v), greater<>());
    ll ans = 0;
    // baseライン
    if(N <= M)rep(i,N)ans += a[i];
    ll sum = 0;
    int idx = 0;//尺取りのindex
    // iのbで残り全部埋めて、b[i] < a[i]花は取る
    rep(i,M){
        // b < aを取る
        ll bb = v[i].first;
        while(idx < M && bb < a[idx]){
            sum += a[idx];
            idx++;
        }
        ll cnt = idx; // 追加個数
        ll tmp = sum;
        ll aa = v[i].second;
        // 尺取りで入っていないので足す
        if(aa <= bb){
            tmp += aa;
            cnt++;
        }
        // 残りは全てbb
        if(N - cnt < 0)continue;
        tmp += (N - cnt) * bb;
        chmax(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    while(t--)solve();    
}