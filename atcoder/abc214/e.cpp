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
// Description: 区間をsetで管理するデータ構造(なお実装はmap)．各クエリO(log区間数)．
 
// #### attention! : [l, r] ( include r, not [l, r) )
class SegmentMap : public std::map<signed, signed> {
private:
    bool flagToMergeAdjacentSegment;
public:
    // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true
    SegmentMap(bool flagToMergeAdjacentSegment) :
        flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
    // __exist -> iterator pair(l, r) (contain p)
    // noexist -> map.end()
    auto get(signed p) const {
        auto it = upper_bound(p);
        if (it == begin() || (--it)->second < p) return end();
        return it;
    }
    // insert segment [l, r]
    void insert(signed l, signed r) {
        auto itl = upper_bound(l), itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = std::min(l, itl->first);
            r = std::max(r, std::prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }
    // remove segment [l, r]
    void remove(signed l, signed r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    // Is p and q in same segment?
    bool same(signed p, signed q) const {
        const auto&& it = get(p);
        return it != end() && it->first <= q && q <= it->second;
    }
};

struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
    int group_num(){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());
    }
};

void solve(){
    SegmentMap mp(false);
    int N;
    cin >> N;
    vector<pair<pair<ll,ll>,int>> lr;
    rep(i,N){
        ll l, r;
        cin >> l >> r;
        lr.push_back({{l, r},i});
    }
    rep(i,N){
        auto [l, r] = lr[i].first;
        mp.insert(l,r);
    }
    rep(i,N){
        auto[l1, r1] = lr[i].first;
        auto itr1 = mp.get(l1);
        auto [lb1, rb1] = (*itr1);
        lr.push_back({{lb1,rb1},-i});
    }
    sort(all(lr));
    UnionFind T(N);
    int sz = lr.size();
    dump(lr);
    rep(i,sz-1){
        auto[l1, r1] = lr[i].first;
        auto itr1 = mp.get(l1);
        auto [lb1, rb1] = (*itr1);

        auto[l2, r2] = lr[i+1].first;
        auto itr2 = mp.get(l2);
        auto [lb2, rb2] = (*itr2);

        if(mp.same(lb1, lb2) || mp.same(lb1,rb2) || mp.same(rb1, lb2) || mp.same(rb1, rb2)){
            T.unite(abs(lr[i].second),abs(lr[i+1].second));
        }
    }
    rep(i,sz){
        dump(i);
        auto [l, r] = lr[i].first;
        if(lr[i].second < 0)continue;
        int cnt = T.size(lr[i].second);
        auto itr = mp.get(l);
        auto [lb, rb] = (*itr);
        dump(i, lb, rb);
        int length = rb - lb + 1;
        dump(length, cnt);
        if(length < cnt){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    dump("");
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
