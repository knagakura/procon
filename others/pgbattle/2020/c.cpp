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

#include<atcoder/modint>
using mint = atcoder::modint1000000007;
int main() {
    ll N;
    int M;
    ll D;
    cin >> N >> M >> D;
    vector<ll> A(M);
    vector<pair<ll, ll>> v;
    rep(i,M){
        cin >> A[i];
        pair<ll, ll> p = {A[i]%D, A[i]/D};
        v.push_back(p);
    }
    sort(all(A));
    sort(all(v));
    dump(v);

    mint ans = 0;
    ll modd = N % D;
    ll kake = N / D;
    v.emplace_back(-1, -1);
    vector<int> tmp;
    rep(i,M){
        tmp.push_back(v[i].second);
        if(v[i].first != v[i+1].first){
            int sz = tmp.size();
            ll maxx = kake * D;
            if(maxx + v[i].first <= N)maxx += v[i].first;
            else {
                maxx -= (D - v[i].first);
            }
            dump(maxx);
            ll cnt = (maxx - v[i].first+D-1) / D;
            dump(cnt);
            tmp.push_back(maxx/D);
            ans += mint(cnt) * mint(cnt+1) / 2;
            dump(ans.val());
            rep(j,sz){
                mint sub = (tmp[j+1] - tmp[j] + (j == sz-1)) * tmp[j];
                dump(sub.val());
                ans -= sub;
            }
            dump(tmp);
            tmp.clear();
        }
    }
    cout << ans.val() << endl;
}
