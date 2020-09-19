#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
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
    int N,M;
    ll L;
    cin >> N >> M >> L;
    
    // dist
    vector dist(N, vector<ll>(N, INFLL));
    rep(i,N)dist[i][i] = 0;
    rep(i,M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = c;
    }
    rep(k,N)rep(i,N)rep(j,N)chmin(dist[i][j], dist[i][k]+dist[k][j]);

    // dist2
    vector dist2(N, vector<ll>(N, INFLL));
    rep(i,N)dist2[i][i] = 0;
    rep(i,N)rep(j,N){
        if(i == j)dist2[i][j] = 0;
        else if(dist[i][j] <= L)dist2[i][j] = 1;
    }
    rep(k,N)rep(i,N)rep(j,N)chmin(dist2[i][j], dist2[i][k]+dist2[k][j]);

    auto solve = [&](int s, int t) -> ll{
        ll res = dist2[s][t] - 1;
        return (res == INFLL-1 ? -1: res);
    };
    int Q;
    cin >> Q;
    while(Q--){
        int s, t;
        cin >> s >> t;
        s--, t--;
        cout << solve(s, t) << endl;
    }
    rep(i,N){
        dump(dist[i]);
    }
    rep(i,N){
        dump(dist2[i]);
    }
}

/*
O(N^3)が通る =>

Q = N^2
クエリあたりO(N)ならOK.

まず全点間距離を出して（ワーシャルフロイド）
その距離を使ってもう一回ワーシャルフロイドしたらいいのでは？
L未満なら0、L以上なら1回

*/