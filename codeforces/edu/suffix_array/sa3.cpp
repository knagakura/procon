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

/*
まずsecondでソートされるようにsecondバケットに突っ込んでいく
そのバケットからfirst バケットに前から入れていくと自然とソートできる、すごい
O(N)
-> 定数倍重くてTLEした・・・二次元配列はカス
*/
void my_radix_sort(vector<pair<pair<int, int>, int>> &v){
    int N = v.size();
    vvec<pair<pair<int, int>, int>> backet_fi(N), backet_se(N);
    rep(i,N)backet_se[v[i].first.second].emplace_back(v[i]);
    rep(i,N){
        for(auto &val: backet_se[i]){
            backet_fi[val.first.first].emplace_back(val);
        }
    }
    int idx = 0;
    rep(i,N){
        for(auto &val: backet_fi[i]){
            v[idx++] = val;
        }
    }
}

// 教材にあったやつ。cntを管理して、posの先頭を管理する頭いい方法
void radix_sort(vector<pair<pair<int, int>, int>> &v){
    int N = v.size();
    {   
        vector<int> cnt(N, 0);
        rep(i,N)cnt[v[i].first.second]++;
        vector<int> pos(N);
        pos[0] = 0;
        rep1(i,N){
            pos[i] = pos[i-1] + cnt[i-1];
        }
        vector<pair<pair<int, int>, int>> v_new(N);
        for(auto &val: v){
            int idx = val.first.second;
            v_new[pos[idx]++] = val;
        }
        swap(v, v_new);
    }
    {   
        vector<int> cnt(N, 0);
        rep(i,N)cnt[v[i].first.first]++;
        vector<int> pos(N);
        pos[0] = 0;
        rep1(i,N){
            pos[i] = pos[i-1] + cnt[i-1];
        }
        vector<pair<pair<int, int>, int>> v_new(N);
        for(auto &val: v){
            int idx = val.first.first;
            v_new[pos[idx]++] = val;
        }
        swap(v, v_new);
    }
}

// 教材の最後。1回目のradixソートは、実はサボれるお話し
void count_sort(vector<int> &p, vector<int> &c){
    int N = p.size();
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
int main() {
    string S;
    cin >> S;
    S.push_back('$');
    int N = S.size();

    vector<int> p(N); // suffix array
    vector<int> c(N); // equivalance class

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
        count_sort(p, c);
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
    rep(i,N){
        cout << p[i] << (i == N-1 ? "\n": " ");
    }
}
