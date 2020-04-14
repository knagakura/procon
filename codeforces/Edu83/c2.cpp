#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define YES "YES"
#define NO "NO"
typedef long long ll;

void solve(){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<int> beki(60);
    bool ok = true;
    //k進数に変換する
    rep(i,N){
        cin>>A[i];
        int cnt = 0;
        while(A[i] > 0){
            if(A[i] % K > 1){
                ok = false;
            }
            if(A[i] % K == 1){
                beki[cnt]++;
            }
            A[i] /= K;
            cnt++;
        }
    }
    rep(i,60){
        if(beki[i] > 1){
            ok = false;
        }
    }
    cout<<(ok ? YES : NO)<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;

    cin>>q;
    while(q--){
        solve();
    }
}