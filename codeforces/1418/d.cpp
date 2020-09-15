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
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) {
    os << "(";
    for(auto itr = st.begin(); itr != st.end(); itr++){
        os << *itr << ", ";
    }
    os << ")";
    return os;
}

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
    int N, Q;
    cin >> N >> Q;
    vector<ll> p(N);
    cin >> p;
    sort(all(p));
    ll len = p[N-1] - p[0];
    multiset<ll> mset; // 距離が入ってる
    set<ll> st; // 座標が入ってる
    rep(i,N)st.insert(p[i]);
    rep(i,N-1)mset.insert(p[i+1]-p[i]);
    if(st.size() >= 2){
        cout << len - *mset.rbegin() << endl;
    }
    else{
        cout << 0 << endl;
    }
    rep(i,Q){
        ll type, x;
        cin >> type >> x;
        
        // 1: 追加
        if(type){
            if(st.size() == 0){
                st.insert(x);
                len = 0;
                cout << 0 << endl;
                continue;
            }
            if(st.size() == 1){
                st.insert(x);
                len = *st.rbegin() - *st.begin();
                mset.insert(len);
                cout << 0 << endl;
                continue;
            }
            auto l_itr = st.lower_bound(x);
            auto r_itr = st.upper_bound(x);
            ll l, r;
            // xが最小
            if(l_itr == st.begin()){
                r = *r_itr;
                len += r-x;
                mset.insert(r-x);
            }
            // xが最大
            else if(r_itr == st.end()){
                l_itr--;
                l = *l_itr;
                len += x-l;
                mset.insert(x-l);
            }
            // 間に入る
            else{
                l_itr--;
                l = *l_itr;
                r = *r_itr;
                mset.erase(mset.lower_bound(r-l));
                mset.insert(x-l);
                mset.insert(r-x);
            }
            st.insert(x);
            auto max_itr = mset.rbegin();
            cout << len - *max_itr << endl;
        }
        // 0: 削除
        else{
            if(st.size() == 1){
                st.erase(x);
                len = 0;
                cout << 0 << endl;
                continue;
            }
            if(st.size() == 2){
                mset.erase(len);
                st.erase(x);
                len = 0;
                cout << 0 << endl;
                continue;
            }
            auto l_itr = st.lower_bound(x);
            auto r_itr = st.upper_bound(x);
            ll l, r;
            // xが最小
            if(l_itr == st.begin()){
                r = *r_itr;
                len -= r-x;
                mset.erase(mset.lower_bound(r-x));
            }
            // xが最大
            else if(r_itr == st.end()){
                l_itr--;
                l = *l_itr;
                len -= x-l;
                mset.erase(mset.lower_bound(x-l));
            }
            // 間から抜ける
            else{
                l_itr--;
                l = *l_itr;
                r = *r_itr;
                mset.erase(mset.lower_bound(x-l));
                mset.erase(mset.lower_bound(r-x));
                mset.insert(r-l);
            }
            // st.insert(x);
            st.erase(x);
            auto max_itr = mset.rbegin();
            cout << len - *max_itr << endl;
        }
    }
}