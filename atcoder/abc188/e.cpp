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
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
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

int N, M;
vector<ll> A;
int main() {
    cin >> N >> M;
    A.resize(N);
    cin >> A;
    vvec<int> G(N), G2(N);
    vector<int> x(M), y(M);
    rep(i,M){
        cin >> x[i]  >> y[i];
        x[i]--, y[i]--;
        G[x[i]].push_back(y[i]);
        G2[y[i]].push_back(x[i]);
    }
    vector<ll> Min(N, INF*10), Max(N, -INF);
    {   
        queue<int> q;
        rep(i,N){
            if(G2[i].size() == 0){
                q.push(i);
                Min[i] = A[i];
            }
        }
        vector<int> visitCnt(N, 0);
        while(not q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto nxt: G[cur]){
                chmin(Min[nxt], min(Min[cur], A[nxt]));
                visitCnt[nxt]++;
                if(visitCnt[nxt] == G2[nxt].size()){
                    q.push(nxt);
                }
            }
        }
    }
    {   
        queue<int> q;
        rep(i,N){
            if(G[i].size() == 0){
                q.push(i);
                Max[i] = A[i];
            }
        }
        vector<int> visitCnt(N, 0);
        while(not q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto nxt: G2[cur]){
                chmax(Max[nxt], max(Max[cur], A[nxt]));
                visitCnt[nxt]++;
                if(visitCnt[nxt] == G[nxt].size()){
                    q.push(nxt);
                }
            }
        }
    }
    dump(Min);
    dump(Max);
    ll ans = -INF * 2;
    rep(i,M){
        chmax(ans, Max[y[i]] - Min[x[i]]);
    }
    cout << ans << endl;
}
