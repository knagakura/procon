#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

ll N,K;
vector<int> a;

bool check(ll x){
    ll cnt = 1;
    ll change = 0;
    rep(i,N-1){
        if(cnt ==x+1){
            change++;
            cnt = 1;
            continue;
        }
        if(a[i]==a[i+1])cnt++;
        else{
            cnt = 1;
        }
    }
    if(cnt == x+1)change++;
    return change<=K;   
}

int main() {
    cin>>N>>K;
    a.resize(N);
    rep(i,N)cin>>a[i];

    //答え決め打ち二分探索
    ll ok = 1e9,ng = 0;
    while(ok-ng>1){
        ll mid = (ok + ng)/2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}