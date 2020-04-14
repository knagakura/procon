#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

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
	int N,Q;
	cin>>N>>Q;
	vector<int> P(Q),A(Q),B(Q);
	rep(i,Q){
		cin>>P[i]>>A[i]>>B[i];
	}
	UnionFind uni(N);
	rep(i,Q){
		if(P[i]==0){
			if(!(uni.same(A[i],B[i]))) uni.unite(A[i],B[i]);
		}
		else{
			if(uni.same(A[i],B[i]))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}