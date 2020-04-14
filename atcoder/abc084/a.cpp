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
ll binary_search(ll time, ll f){
    ll l = 0;ll r = 1e9;
    ll mid = (l+r)/2;
    while(r>l){
        if(time <= f * r){
           l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> C(N-1), S(N-1), F(N-1);
    rep(i,N-1){
        cin>>C[i]>>S[i]>>F[i];
    }
    rep(i,N-1){
        ll ans = S[i] + C[i];
        for(int j = i+1; j < N; ++j){
            ans += binary_search(ans, F[j]) + C[j];
        }
        cout<<ans<<endl;
    }
    return 0;
}