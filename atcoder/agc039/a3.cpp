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
string S;
int N;
ll solve(){
    ll res = 0;
    int cnt = 1;
    rep(i,N-1){
        if(S[i] == S[i+1]){
            cnt++;
        }
        else{
            if(cnt>1){
                res+= cnt/2;
            }
            cnt = 1;
        }
    }
    res += cnt;
    cerr<<res<<endl;

    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin>>S>>K;
    N = S.size();
    bool AllSame = true;
    rep(i,N-1){
        if(S[i]==S[i+1])continue;
        else AllSame = false;
    }
    if(AllSame){
        ll ans = (ll)N * K / 2;
        cout<<ans<<endl;
        return 0;
    }
    if(S[0] == S[N-1]){
        int cnt0 = 1;
        int cntN = 1;
        rep(i,N){
            if(S[i] == S[i+1])cnt0++;
            else break;
        }
        for (int i = N-1; i >= 0; --i){
            if(S[i-1] == S[i])cntN++;
            else break;
        }
        cerr<<cnt0<<" "<<cntN<<endl;
        ll ans = solve();

        if((cnt0 + cntN) % 2 == 0){
            ans = ans * K + K-1;
        }
        else ans *= K;
        cout<<ans<<endl;
        return 0;
    }
    else{
        ll ans = solve() * K;
        cout<<ans<<endl;
        return 0;
    }
}