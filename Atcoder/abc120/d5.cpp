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

int main() {
	ll N,M;
	cin>>N>>M;
	vector<P> v(M);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		v[i] = {a,b};
	}
	vector<ll> ans(M);
	ans[M-1] = N*(N-1)/2;
	UnionFind uni(N);
	for (int i = M-1; i >= 1; --i){
		int x = v[i].first;
		int y = v[i].second;
		ll linked_N = 0;
		if(uni.same(x,y)){
			ans[i-1] = ans[i] - linked_N;
			continue;
		}else{
			linked_N = uni.size(x) * uni.size(y);
			uni.unite(x,y);
			ans[i-1] = ans[i] - linked_N;
		}
	}
	rep(i,M)cout<<ans[i]<<endl;
}