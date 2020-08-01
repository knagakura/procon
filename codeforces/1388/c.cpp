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
ll N, M;
vvec<int> G;
vec<ll> p;; // p[i]: iがホームの人の人数, sum(p) = M;
vec<ll> h; // 幸福度指数(間違ってるかもしれん)
vec<ll> cnt;
vec<l_l> cnt_pair;
bool ok;

ll dfs_cnt(int cur = 0, int pre = -1){
    ll res = p[cur];
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        res += dfs_cnt(nxt, cur);
    }
    return cnt[cur] = res;
}
l_l dfs(int cur = 0, int pre = -1){
    // if((cnt[cur]+h[cur]) % 2 == 1)ok = false;
    // if(cnt[cur]+h[cur] < 0)ok = false;
    ll pls = (cnt[cur]+h[cur]) / 2; // 必ず偶数で、正
    ll mns = cnt[cur] - pls;
    if(mns < 0)ok = false;
    // 下に潜ると、plsとmnsがわかって、
    ll pls_sum = 0;
    ll mns_sum = 0;
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        auto nxt_sum = dfs(nxt, cur);
        pls_sum += nxt_sum.first;
        mns_sum += nxt_sum.second;
    }
    ll rem = pls + mns - pls_sum - mns_sum; // 残る人
    if(rem != p[cur])ok = false; //残る人の人数がそこがホームの人の数に一致しない
    if(pls < pls_sum)ok = false; // +が増えてる
    return cnt_pair[cur] = make_pair(pls, mns);
}

void solve(){
    cin >> N >> M; // N都市、M人(M < 1e9);
    p.resize(N);
    h.resize(N);
    rep(i,N)cin >> p[i];
    rep(i,N)cin >> h[i];
    G.resize(N);
    // 木 0(capital)からhomeへ最短距離で帰る (=> 根つき木)
    rep(i,N-1){
        int f, t;
        cin >> f >> t;
        f--, t--;
        G[f].emplace_back(t);
        G[t].emplace_back(f);
    }
    // 頂点iの部分木にいる人数 cntをdfsで計算
    cnt.assign(N,0);
    dfs_cnt();
    // 判定
    ok = true;
    // 奇数人のときは奇数の差しか生まれない（偶数もまた然り）
    rep(i,N){
        if(abs(cnt[i]) % 2 != abs(h[i]) % 2)ok = false;
        if(abs(h[i]) > abs(cnt[i]))ok = false;
    }
    // 偶奇は一致しているしオーバーすることもないから基本的に数えられるけど
    // プラスの人数に着目して、増えてたら問題あり（意地、減るのは問題なし）
    cnt_pair.resize(N);
    dfs();
    // print(cnt);
    // print(cnt_pair);
    cout << (ok ? "YES" : "NO") << endl;
    G.clear();
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
