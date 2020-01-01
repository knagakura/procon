#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main() {
    
    ll N,M,V,P;
    cin>>N>>M>>V>>P;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A), greater<ll>());
    //xは0-indexed
    auto check = [&](ll x){
        //0 ~ P-1はOK
        if(x < P){
            return true;
        }
        if(A[x] + M < A[P-1]){
            return false;
        }
        ll sum = 0;
        rep(i,N){
            if(i < P-1 || x <= i)sum+= M;
            else{
                sum += A[x] + M - A[i];
            }
        }
        return M * V <= sum;
    };
    ll ok = -1;
    ll ng = N;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok + 1<<endl;
}