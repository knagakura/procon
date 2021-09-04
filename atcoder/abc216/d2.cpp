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
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

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


int main() {
    int N, M;
    cin >> N >> M;
    vector<deque<int>> dqs(M);
    vector<vector<int>> topCnt(N);
    rep(i,M){
        int K;
        cin >> K;
        rep(k,K){
            int a;
            cin >> a;
            a--;
            dqs[i].push_back(a);
            if(k == 0){
                topCnt[a].push_back(i);
            }
        }
    }
    deque<int> q;
    rep(i,N){
        if(topCnt[i].size() == 2){
            q.push_back(i);
        }
    }

    while(!q.empty()){
        int a = q.front();
        q.pop_front();
        dump(dqs);
        dump(q);
        int l = topCnt[a][0];
        int r = topCnt[a][1];
        assert(dqs[l].front() == a);
        assert(dqs[r].front() == a);
        dqs[l].pop_front();
        dqs[r].pop_front();
        if(!dqs[l].empty()){
            int na = dqs[l].front();
            topCnt[na].push_back(l);
            if(topCnt[na].size() == 2){
                q.push_back(na);
            }
        }
        if(!dqs[r].empty()){
            int na = dqs[r].front();
            topCnt[na].push_back(r);
            if(topCnt[na].size() == 2){
                q.push_back(na);
            }
        }
    }
    for(auto dq: dqs){
        if(!dq.empty()){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
