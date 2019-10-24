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
    ll ok = 1e9;
    ll ng = -1;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng)/2;
        if(time <= f * mid){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return f * ok;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> C(N,0), S(N,0), F(N,0);
    rep(i,N-1){
        cin>>C[i]>>S[i]>>F[i];
    }
    rep(i,N){
        ll ans = S[i] + C[i];
        for(int j = i+1; j < N-1; ++j){
            //cerr<<i<<" "<<j<<" "<<binary_search(ans, F[j])<<endl;;
            if(ans < S[j]){
                ans = S[j]+C[j];
            }
            else{
                ans += binary_search(ans, F[j])-ans + C[j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}