#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

ll R,B;
ll x,y;

bool check(ll X){
    if(R-X<0||B-X<0){
        return false;
    }
    ll cnt = (R-X)/(x-1) + (B-X)/(y-1);
    return cnt>=X;
}

int main() {
    cin>>R>>B>>x>>y;
    ll ok = 0, ng = 1e18;
    while(ng-ok > 1){
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