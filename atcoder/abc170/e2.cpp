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

int MAXX = 200005;
int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N), B(N), C(Q), D(Q);
    vector<set<pair<int, int>>> vm(MAXX);
    rep(i,N){
        cin >> A[i] >> B[i];
        B[i]--;
        vm[B[i]].insert(make_pair(A[i], i));
    }
    set<pair<int, int>> st;
    rep(i,MAXX){
        if(not vm[i].empty()){
            int maxx = (*vm[i].rbegin()).first;
            st.insert(make_pair(maxx, i));
        }
    }
    rep(i,Q){
        cin >> C[i] >> D[i];
        C[i]--, D[i]--;
    }
    rep(i,Q){
        int from = B[C[i]];
        int to = D[i];
        // fromから削除して最大値を取り直す
        {
            int pre_max = (*vm[from].rbegin()).first;
            st.erase(make_pair(pre_max, from));
            vm[from].erase(make_pair(A[C[i]], C[i]));
            // dump(pre_max);
            if(vm[from].size() > 0){
                int nxt_max = (*vm[from].rbegin()).first;
                st.insert(make_pair(nxt_max, from));
            }
        }
        // toに追加して最大値を取り直す
        {
            if(vm[to].size() > 0){
                int pre_max = (*vm[to].rbegin()).first;
                st.erase(make_pair(pre_max, to));
            }
            vm[to].insert(make_pair(A[C[i]], C[i]));
            int nxt_max = (*vm[to].rbegin()).first;

            st.insert(make_pair(nxt_max, to));
        }
        B[C[i]] = to;
        cout << (*st.begin()).first << endl;
    }
}
