#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

int main() {
    int N;
    cin>>N;
    vector<ll> a(N),b(N);
    ll suma = 0, sumb = 0;
    rep(i,N){
        cin>>a[i];
        suma += a[i];
    }
    rep(i,N){
        cin>>b[i];
        sumb += b[i];
    }
    if(a!=b&&suma>=sumb){
        cout<<"No"<<endl;
        return 0;
    }
    ll cnta = 0;
    ll cntb = 0;
    rep(i,N){
        if(a[i]==b[i])continue;
        else if(a[i]<b[i]){
            if(b[i]-a[i]%2 == 0){
                cnta += (b[i]-a[i])/2;
            }
            else{
                cnta += (b[i]-a[i])/2 + 1;
                cntb += 1;
            }
        }
        else{
            cntb += a[i]-b[i];
        }
    }
    if(cnta-cntb<0){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}