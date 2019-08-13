#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }


typedef long long ll;
using P = pair<ll, ll>;		//P.first, P.second
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
        if(x>y) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
};


ll a,b;
int main() {
	ll N,M;
	cin>>N>>M;
	vector<P> ba;
	rep(i,N){
		cin>>a>>b;
		ba.push_back({b,-a});
	}
	sort(all(ba),greater<P>());
	printpair(ba);
	UnionFind uni(M);
	vector<ll> ansv(M);
	rep(i,N){
		a = -ba[i].second;
		b = ba[i].first;
		cerr<<a<<" "<<b<<endl;
		cerr<<M-a<<endl;
		if(M-a<0){
			continue;
		}
		ll umeru = uni.root(M-a);
		if(ansv[umeru]==0){

			ansv[umeru] = b;

			if(umeru-1>=0){
				uni.unite(umeru,umeru-1);
			}

		}
	}

	ll ans = 0;
	print(ansv);
	rep(i,M){
		ans+=ansv[i];
	}
	
	cout<<ans<<endl;
}