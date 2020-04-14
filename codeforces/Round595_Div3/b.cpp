#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
struct UnionFind{
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int n):Parent(n),sizes(n,1){ rep(i,n)Parent[i]=i; }
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
/Users/knaga/procon/Atcoder/abc120
UnionFind木は繋がりを断つことはできないが、
構成することはできるので、逆からやるやつ。
②D-Equals
https://beta.atcoder.jp/contests/abc097
/Users/knaga/procon/Atcoder/abc097
swapすればそれらは行き来可能になるので、実質パイプ。
③B-Union Find
https://beta.atcoder.jp/contests/atc001
/Users/knaga/procon/Atcoder/atc001
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
④B-道路工事
https://beta.atcoder.jp/contests/arc032/
/Users/knaga/procon/Atcoder/arc032
すべての点に対して根を考えることで、
グループが幾つに分かれているかを知ることができる
⑤D-連結
https://beta.atcoder.jp/contests/abc049
/Users/knaga/procon/Atcoder/abc049
二つのUnionFind木を管理して、
同時に繋がっていることを根のPairを持って
mapで管理すると良い
[解説]http://drken1215.hatenablog.com/entry/2019/06/29/182300
*/
/*------------------------------------*/
void solve(){
    int N;cin>>N;
    vector<ll> p(N);
    UnionFind uni(N);
    rep(i,N){
        cin>>p[i];
        p[i]--;
        uni.unite(i,p[i]);
    }
    rep(i,N){
        cout<<uni.size(i);
        if(i == N-1)cout<<endl;
        else cout<<" ";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;cin>>q;while(q--)solve();
}