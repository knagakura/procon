#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
vector<vector<pair<int,ll>>> G;
int main() {
    int N,M;
    cin>>N>>M;
    G.resize(N);
    rep(i,M){
        int L,R,D;
        cin>>L>>R>>D;
        L--;R--;
        G[L].push_back({R,D});
        G[R].push_back({L,-D});
    }
    int ans = 0;
    cout<<ans<<endl;
}