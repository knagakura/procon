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

struct SuffixArray{
    string S;
    int N;
    vector<int> p; // suffix array
    vector<int> c; // equivalance class
    vector<int> lcp;
    SuffixArray(){}
    SuffixArray(string &S_):S(S_), N(S.size()+1), p(N, 0), c(N,0){ build(); };
    void build(){
        S.push_back('$');
        S += S;
        {
            // k = 0 part O(NlogN)
            vector<pair<char,int>> v(N);
            rep(i,N)v[i] = make_pair(S[i], i);
            sort(all(v));
            rep(i,N)p[i] = v[i].second;
            c[p[0]] = 0;
            rep1(i,N){
                if(v[i].first == v[i-1].first)c[p[i]] = c[p[i-1]];
                else c[p[i]] = c[p[i-1]] + 1;
            }
        }
        int k = 0;
        vector<pair<pair<int, int>, int>> v(N);
        while((1 << k) < N){
            // second halfでソートされた形にできる
            rep(i,N)p[i] = (((p[i] - (1 << k)) % N) + N) % N;
            count_sort();
            vector<int> c_new(N);
            c_new[p[0]] = 0;
            rep1(i,N){
                pair<int, int> prev = make_pair(c[p[i-1]], c[(p[i-1]+(1<<k))%N]);
                pair<int, int> now = make_pair(c[p[i]], c[(p[i]+(1<<k))%N]);
                if(prev == now)c_new[p[i]] = c_new[p[i-1]];
                else c_new[p[i]] = c_new[p[i-1]] + 1;
            }
            swap(c, c_new);
            k++;
        }
    }
    void build_lcp(){
        lcp.resize(N);
        int k = 0;
        rep(i,N-1){
            int pi = c[i];
            int j = p[pi-1];
            // lcp[i] = lcp(s[i...], s[j..])
            while(S[i+k] == S[j+k])k++;
            lcp[pi] = k;
            k = max(k-1, 0);
        }
    }
    void count_sort(){
        // int N = p.size();
        // backet's size
        vector<int> cnt(N);
        rep(i,N)cnt[c[i]]++;
        // first position of each backet
        vector<int> pos(N);
        pos[0] = 0;
        rep1(i,N)pos[i] = pos[i-1] + cnt[i-1];
        // sorted by first new suffix array
        vector<int> p_new(N);
        rep(i,N){
            int backet_idx = c[p[i]];
            p_new[pos[backet_idx]++] = p[i];
        }
        swap(p, p_new);
    }
    bool substr_search(const string &t){
        int M = t.size();
        int ok = -1;
        int ng = N;
        bool res = false;
        while(ng - ok > 1){
            int mid = (ok + ng) >> 1;
            string tmp = S.substr(p[mid], M);
            if(tmp == t)res = true;
            if(tmp < t){
                ok = mid;
            }
            else ng = mid;
        }
        return res;
    }
    int substr_count(const string &t){
        int M = t.size();
        int ok = -1;
        int ng = N;
        while(ng - ok > 1){
            int mid = (ok + ng) >> 1;
            string tmp = S.substr(p[mid], M);
            if(tmp < t){
                ok = mid;
            }
            else ng = mid;
        }
        int ok2 = -1;
        int ng2 = N;
        while(ng2 - ok2 > 1){
            int mid = (ok2 + ng2) >> 1;
            string tmp = S.substr(p[mid], M);
            if(tmp <= t){
                ok2 = mid;
            }
            else ng2 = mid;
        }
        return ok2 - ok;
    }
};
int main() {
    string S;
    cin >> S;
    ll N = S.size();
    SuffixArray sa(S);
    sa.build_lcp();
    ll ans = N * (N+1) / 2 - SUM(sa.lcp);
    cout << ans << endl;
}
