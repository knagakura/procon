#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

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
	vector<int> p(N);
	rep(i,N){
		cin>>p[i];
		p[i]--;
	}
	vector<ll> x(M),y(M);
	rep(i,M){
		cin>>x[i]>>y[i];
		x[i]--;y[i]--;
	}
	UnionFind uni(N);
	rep(i,M){
		if(!(uni.same(x[i],y[i]))){
			uni.unite(x[i],y[i]);
		}
	}
	int ans =0;
	rep(i,N){
		if(uni.same(p[i],i))ans++;
	}
	cout<<ans<<endl;
}
