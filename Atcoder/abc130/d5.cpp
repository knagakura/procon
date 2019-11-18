#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
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

    ll ans = 0;

    for(int l = 0; l < N; l++){
        int r = lower_bound(all(cum), cum[l] + K) - cum.begin();
        ans += N - r + 1;
    }
    cout<<ans<<endl;
}