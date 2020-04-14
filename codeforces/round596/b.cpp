#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
void solve(){
    int N,K,d;
    cin>>N>>K>>d;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    //print(a);
    map<int, int> map;
    rep(i,d){
        map[a[i]]++;
    }
    int ans = map.size();
    int pre = ans;
    for(int i = d; i < N; ++i){
        //cerr<<pre<<endl;
        if(a[i] != a[i-d]){
            if(map[a[i]] == 0){
            pre++;
            }
            if(map[a[i-d]] == 1){
            pre--;
            }
        }
        
        map[a[i-d]]--;
        map[a[i]]++;
        ans = min(ans, pre);
    }
    cout<<ans<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}