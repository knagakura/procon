#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

struct UnionFind{
    vector<int> par;
    vector<int> sizes;
    UnionFind(int n):par(n),sizes(n,1){ rep(i,n)par[i]=i; }
    //find root of x
    int find(int x){
        if(x!=par[x]) par[x] = find(par[x]);
        return par[x];
    }
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return find(x) == find(y); }
    int size(int x){ return sizes[find(x)]; }
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
