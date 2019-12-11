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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,K;
    cin>>N>>K;
    vector<ll> a(N);
    map <int, int> map;
    rep(i,N){
        cin>>a[i];
        map[a[i]]++;
    }
    sort(all(a));
    if(K == 2){
        int ans = 0;
        int cnt = 1;
        rep(i,N-1){
            if(a[i] == a[i+1]){
                cnt++;
            }
            else{
                ans += cnt*(cnt-1)/2;
                cnt = 1;
            }
        }
        ans += cnt*(cnt-1)/2;
        cout<<ans<<endl;
        return 0;
    }
    vector<ll> power_k;
    ll x = 0;
    while(pow(x,K)<1e5){
        x++;
        power_k.push_back(pow(x,K));
    }
    //print(power_k);
    ll ans = 0;
    rep(i,N){
        rep(j,(int)power_k.size()){
            if(power_k[j]%a[i]==0){
                ll y = power_k[j]/a[i];
                if(map[y]){
                    if(y == a[i]){
                        ans+= map[y]-1;
                    }
                    else{
                        ans+= map[y];
                    }
                }
            }
        }
    }
    cout<<ans/2<<endl;
}