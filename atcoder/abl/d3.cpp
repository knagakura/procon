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
#include <atcoder/segtree>
template<typename T>
T op(T a, T b){
    return min(a, b);
}
template<typename T>
T e(){
    return INF;
}

template<typename T>
T op2(T a, T b){
    return max(a, b);
}
template<typename T>
T e2(){
    return -1;
}
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    vector<bool> used(N, false);
    ll ans = 0;
    atcoder::segtree<ll, op, e> S(N);
    atcoder::segtree<ll, op2, e2> S2(N);
    rep(i,N){
        S.set(i, A[i]);
        S2.set(i, A[i]);
    }
    rep(i,N){
        if(used[i])continue;
        ll tmp = 1;
        int idx = i;
        dump(i);
        while(true){
            /*
            右側を二分探索
            idx ~ N
            最初に値がA[i]-K ~ A[i]+Kに治るidxを探す
            */
            dump(idx);
            used[i] = true;
            int ok = i;
            int ng = N;
            while(ng - ok > 1){
                int mid = (ok + ng) >> 1;
                int prod = S.prod(idx, mid+1);
                int prod2 = S.prod(idx, mid+1);
                if(A[idx]-K > prod || prod2 > A[idx] + K)ok = mid;
                else ng = mid;
            }
            dump(ok, ng);
            if(ok == N)break;
            if(used[ok])break;
            idx = ok;
            used[idx] = true;
            tmp++;
        }
        chmax(ans, tmp+1);
    }
    cout << ans << endl;
}
