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
    とすることで、それらが同じかどうかをtrue/falseで返す
    ②あるNode x が含まれる集合の大きさを知りたいとき
    uni.size(x)
    ③二つのNode xとyを同じ集合に属させたいとき
    uni.unite(x, y)
*/
/*~UnionFind木が出題された問題~
①D-Decayed Bridges
https://beta.atcoder.jp/contests/abc120
/Users/knaga/procon/Atcoder/abc120
UnionFind木は繋がりを断つことはできないが、
構成することはできるので、逆からやるやつ。
②D - Equals
https://beta.atcoder.jp/contests/abc097
/Users/knaga/procon/Atcoder/abc097
swapすればそれらは行き来可能になるので、実質パイプ。
③B - Union Find
https://beta.atcoder.jp/contests/atc001
/Users/knaga/procon/Atcoder/atc001
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
*/

int main() {
	int N,Q;
	cin>>N>>Q;
	UnionFind uni(N);
	rep(i,Q){
		int p,a,b;
		cin>>p>>a>>b;
		if(p){
			if(uni.same(a,b)){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}
		else{
			uni.unite(a,b);
		}
	}
}