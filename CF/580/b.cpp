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
    vector<int> a(N);;
    ll cnt =  0;
    bool iszero = false;
    rep(i,N){
        cin>>a[i];
        if(a[i]<0){
            cnt++;
        }
        if(a[i] == 0){
            iszero = true;
        }

    }
    sort(all(a));
    print(a);
    ll ans = 0;
    rep(i,N){
        ans += min(abs(a[i]+1),abs(a[i]-1));
    }
    if(cnt%2 == 1){
        if(!(iszero))ans += 2;
    }
    cout<<ans<<endl;

}