#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

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
    uni.same(x, y)
    などとすることで、それらが同じかどうかをtrue/falseで返す
    ②あるNode x が含まれる集合の大きさを知りたいとき
    uni.size(x)
    ③二つのNode xとyを同じ集合に属させたいとき
    uni.unite(x, y)
*/
/*~UnionFind木が出題された問題~
①
https://beta.atcoder.jp/contests/abc120
/Users/knaga/procon/Atcoder/abc120
*/


int main() {
	ll N,M;
	cin>>N>>M;
	vector<int> p(N);
	rep(i,N){
		cin>>p[i];
		p[i]--;
	}
    UnionFind uni(N);
	rep(i,M){
		int x,y;
		cin>>x>>y;
		x--;y--;
        uni.unite(x,y);
	}
    ll ans = 0;
    rep(i,N){
        if(uni.same(i, p[i])){
            ans++;
        }
    }	
	cout<<ans<<endl;
}