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
    vector<ll> p(N), h(N);
    rep(i,N)cin >> p[i];
    rep(i,N)cin >> h[i];
    vvec<int> G(N);
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> cnt(N,0),happy(N,0),unhappy(N,0);
    bool ok = true;
    auto dfs = [&](auto && self, int cur = 0, int pre = -1) -> pair<ll,ll>{
        cnt[cur] += p[cur];
        ll happy_sum = 0;
        ll unhappy_sum = 0;
        for(int nxt: G[cur]){
            if(nxt == pre)continue;
            auto nxt_p = self(self, nxt, cur);
            happy_sum += nxt_p.first;
            unhappy_sum += nxt_p.second;
            cnt[cur] += cnt[nxt];
        }
        ll tmp = h[cur] + cnt[cur];
        if(tmp < 0)ok = false;
        if(tmp % 2 == 1)ok = false;
        happy[cur] = tmp / 2;
        unhappy[cur] = cnt[cur] - happy[cur];
        if(happy[cur] < 0)ok = false;
        if(unhappy[cur] < 0)ok = false;
        if(happy[cur] < happy_sum)ok = false;
        return make_pair(happy[cur], unhappy[cur]);
    };

    dfs(dfs, 0, -1);
    cout << (ok ? "YES": "NO") << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
