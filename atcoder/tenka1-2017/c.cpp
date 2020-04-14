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
int main() {
    ll N;
    cin>>N;
    ll h, n, w;
    rep1(i,3501)rep1(j,3501){
        h = ll(i);
        n = ll(j);
        ll ue = 4*h*n-N*n-h*N;
        ll shita = N*h*n;
        if(ue<=0)continue;
        //cerr<<ue<<"/"<<shita<<endl;
        //cerr<<shita%ue<<endl;
        if(shita%ue == 0){
            w =  shita/ue;
            cout<<h<<" "<<n<<" "<<w<<endl;
            return 0;
        }
    }
}