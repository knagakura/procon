#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

int main() {
    int N;cin>>N;
    vector<ll> a(N),b(N);
    rep(i,N)cin>>a[i];
    rep(i,N)cin>>b[i];
    ll cnt = 0;
    rep(i,N){
        //包容力が貯まる
        if(a[i]<=b[i]){
            if((b[i]-a[i])%2 == 0){
                cnt += (b[i]-a[i])/2;
            }
            else{
                cnt += (b[i]-a[i]-1)/2;
            }
        }
        //包容力が使われる
        else{
            cnt-=a[i]-b[i];
        }
    }
    cerr<<cnt<<endl;
    bool flag = (cnt>=0);
    cout<<(flag? "Yes": "No")<<endl;
}