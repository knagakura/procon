#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

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
	int N,M;
	cin>>N>>M;
	vector<int> a(M),b(M);
	rep(i,M){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
	}
	int ans = 0;
	rep(i,M){
		UnionFind tree(N);
		rep(j,M){
			if(i!=j){
				if(!(tree.same(a[j],b[j]))){
					tree.unite(a[j],b[j]);
				}
			}
		}
		if(!(tree.same(a[i],b[i])))ans++;
	}
	cout<<ans<<endl;
}