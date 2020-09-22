#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
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

/*~使い方講座~
まず、main関数内で 
    UnionFind uni(N);
と呼び出します（これでUnionFind木のuniちゃんが呼び出されます）。
uniちゃんの中には、NodeがN個あり、
それぞれの親とそれが属する集合の数（size）が定義されています。
    ①二つのNode xとy が同じ集合に属するか確認するとき
    uni.same(x, y);
    とすることで、それらが同じかどうかをtrue/falseで返す
    ②あるNode x が含まれる集合の大きさを知りたいとき
    uni.size(x);
    ③二つのNode xとyを同じ集合に属させたいとき
    uni.unite(x, y);
    ④あるNode xの根を知りたいとき
    uni.root(x);
*/
/*~UnionFind木が出題された問題~
①D-Decayed Bridges
https://beta.atcoder.jp/contests/abc120
UnionFind木は繋がりを断つことはできないが、
構成することはできるので、逆からやるやつ。
②D-Equals
https://beta.atcoder.jp/contests/abc097
swapすればそれらは行き来可能になるので、実質パイプ。
③B-Union Find
https://beta.atcoder.jp/contests/atc001
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
④B-道路工事
https://beta.atcoder.jp/contests/arc032/
すべての点に対して根を考えることで、
グループが幾つに分かれているかを知ることができる
⑤D-連結
https://beta.atcoder.jp/contests/abc049
二つのUnionFind木を管理して、
同時に繋がっていることを根のPairを持って
mapで管理すると良い
[解説]http://drken1215.hatenablog.com/entry/2019/06/29/182300
⑥D - Friend Suggestions
[問題]https://atcoder.jp/contests/abc157/tasks/abc157_d
[提出]https://atcoder.jp/contests/abc157/submissions/10460043
友達関係のグルーピングに使う
sizeも用いた
⑦E - 1 or 2
[問題]https://atcoder.jp/contests/abc126/tasks/abc126_e
[提出]https://atcoder.jp/contests/abc126/submissions/10649376
集合の数を管理するgroup_numを実装した
*/

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N+1, 0);
    };
    
    // a is 1-indexed
    void add(int a, T w){
        for(int x = a; x <= N; x += x & -x)data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a){
        T res = 0;
        for(int x = a; x > 0; x -= x & -x)res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r){return sum(r) - sum(l-1);}

    // 0-indexed add
    void add0(int a, T w){add(a + 1, w);}
    // 0-indexed sum
    T sum0(int a){return sum(a + 1);}
    // 0-indexed sum of range
    T sum0(int l, int r){return sum0(r) - sum0(l-1);}
    // show the value
    void debug(){print(data);}
    // k-th number (k is 1 - indexed)
    T get(int k){
        T res = 0;
        int sz = 1;
        while(sz < (int)data.size()) sz <<= 1;
        for(int i = sz / 2; i > 0; i >>= 1){
            if(res + i <= N && data[res + i] < k){
                k -= data[res + i];
                res += i;
            }
        }
        return res + 1;
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

/*~使い方講座~
まず、main関数内で 
    UnionFind uni(N);
と呼び出します（これでUnionFind木のuniちゃんが呼び出されます）。
uniちゃんの中には、NodeがN個あり、
それぞれの親とそれが属する集合の数（size）が定義されています。
    ①二つのNode xとy が同じ集合に属するか確認するとき
    uni.same(x, y);
    とすることで、それらが同じかどうかをtrue/falseで返す
    ②あるNode x が含まれる集合の大きさを知りたいとき
    uni.size(x);
    ③二つのNode xとyを同じ集合に属させたいとき
    uni.unite(x, y);
    ④あるNode xの根を知りたいとき
    uni.root(x);
*/
/*~UnionFind木が出題された問題~
①D-Decayed Bridges
https://beta.atcoder.jp/contests/abc120
UnionFind木は繋がりを断つことはできないが、
構成することはできるので、逆からやるやつ。
②D-Equals
https://beta.atcoder.jp/contests/abc097
swapすればそれらは行き来可能になるので、実質パイプ。
③B-Union Find
https://beta.atcoder.jp/contests/atc001
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
④B-道路工事
https://beta.atcoder.jp/contests/arc032/
すべての点に対して根を考えることで、
グループが幾つに分かれているかを知ることができる
⑤D-連結
https://beta.atcoder.jp/contests/abc049
二つのUnionFind木を管理して、
同時に繋がっていることを根のPairを持って
mapで管理すると良い
[解説]http://drken1215.hatenablog.com/entry/2019/06/29/182300
⑥D - Friend Suggestions
[問題]https://atcoder.jp/contests/abc157/tasks/abc157_d
[提出]https://atcoder.jp/contests/abc157/submissions/10460043
友達関係のグルーピングに使う
sizeも用いた
⑦E - 1 or 2
[問題]https://atcoder.jp/contests/abc126/tasks/abc126_e
[提出]https://atcoder.jp/contests/abc126/submissions/10649376
集合の数を管理するgroup_numを実装した
*/
int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    BIT<ll> T(N);
    UnionFind Uni(N);
    vector<pair<i_i, int>> xyi;
    vector<pair<i_i, int>> xyi2;
    rep(i,N){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        xyi.push_back({{x[i], y[i]}, i});
        xyi2.push_back({{N-1-x[i], N-1-y[i]}, i});
    }
    sort(all(xyi));
    sort(all(xyi2));
    dump(xyi);
    vector<int> ans(N, 1);
    rep(i,N){
        auto piii = xyi[i];
        auto [p, idx] = piii;
        auto [a, b] = p;
        dump(a, b, idx);
        ans[idx] += T.sum0(b-1); // 今入ってる座標は全てx座標が自分未満なので、y座標が自分未満のやつを探せば良い
        T.add0(b, 1);
    }
    dump(ans);
    dump(xyi2);
    BIT<ll> T2(N);
    rep(i,N){
        auto piii = xyi2[i];
        auto [p, idx] = piii;
        auto [a, b] = p;
        dump(a, b, idx);
        ans[idx] += T2.sum0(b-1); // 今入ってる座標は全てx座標が自分未満なので、y座標が自分未満のやつを探せば良い
        T2.add0(b, 1);
    }
    dump(ans);
}