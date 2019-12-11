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
void solve(){
    int N;cin>>N;
    vector<ll> a,b;
    a.push_back(0);
    b.push_back(0);
    rep(i,N){
        int aa,bb;
        cin>>aa>>bb;
        a.push_back(aa);
        b.push_back(bb);
    }
    a.push_back(0);
    b.push_back(0);
    ll ans = 0;
    ll sum0 = 0;
    ll sum1 = 0;
    rep1(i,N+1){
        if(a[i] == a[i+1]){
            ll y = 1;
            if(a[i-1]==a[i]+1){
                y = 2;
            }
            if(i%2 == 0){
                sum0 += y*b[i];
            }
            else{
                sum1 += y*b[i];
            }
        }
        //違ったらその数字について考慮するの終わり
        else{
            ll x = 1;
            if(a[i+1]-a[i] == 1||a[i-1]-a[i] == 1){
                x = 2;
            }
            if(i % 2 == 0){
                sum0 += x * b[i];
            }else{
                sum1 += x * b[i];
            }
            ans+=min(sum0,sum1);
            sum0 = 0;
            sum1 = 0;
        }
    }
    cout<<ans<<endl;
    return;
}
int main() {
    int q;cin>>q;
    rep(i,q)solve();
}