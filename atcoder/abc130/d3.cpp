#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    rep(i,v.size()){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    auto cum = cumulative_sum(a);

    ll ans = N*(N+1)/2;

    for(int l = 0; l < N; l++){
        int ok = -1;
        int ng = N;
        while(ng-ok > 1){
            ll mid = (ng + ok)/2;
            if(cum[mid+1]-cum[l] < K){
                ok = mid;
            }
            else{
                ng = mid;
            }
        }
        ans -= ok - l + 1;
    }
    
    cout<<ans<<endl;
}