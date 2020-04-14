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
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    print(a);
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            if(a[i]&a[j]!=0){
                cerr<<a[i]<<" "<<a[j]<<endl;
                cnt++;
            }
        }
    }
    cerr<<cnt<<endl;
    int ans;
    
    cout<<ans<<endl;

}