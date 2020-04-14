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
	vector<ll> A(M),B(M);
	rep(i,M){
		cin>>A[i]>>B[i];
		A[i]--;B[i]--;
	}
	vector<ll> ans(M);
	ans[M-1] = N*(N-1)/2;
	UnionFind uni(N);
	for (int i = M-1; i >=1; --i){
		if(uni.same(A[i],B[i])){
			ans[i-1] = ans[i]; 
		}
		else{
			ans[i-1] = ans[i]-uni.size(A[i])*uni.size(B[i]);
			uni.unite(A[i],B[i]);
		}
	}
	rep(i,M){
		cout<<ans[i]<<endl;
	}
}
