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
    int M,D;
    cin>>M>>D;
    int ans = 0;
    rep1(m,M+1){
        rep1(d,D+1){
            int d1 = d%10;
            int d10 = d/10;
            //cerr<<d1<<" "<<d10<<endl;
            if(d1>=2&&d10>=2&&d1*d10 == m){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}