#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define bit(k) (1LL<<k)
typedef long long ll;

void Case(int t){
    cout << "Case #" << t << ": ";
}

void solve(){
    ll x, y;
    cin >> x >> y;
    ll ax = abs(x);
    ll ay = abs(y);
    if((ax & 1) == (ay & 1)){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    string dx = "WE";
    string dy = "SN";
    string ans = "";
    int idx = 0;
    while(1){
        if(ax & 1){
            ax += (pm[idx] ? -1: 1);
            pm[idx] ^= (x < 0);
            ans.push_back(dx[pm[idx]]);
        }
        else{
            ay += (pm[idx] ? -1: 1);
            pm[idx] ^= (y < 0);
            ans.push_back(dy[pm[idx]]);
        }
        ax >>= 1;
        ay >>= 1;
        idx++;
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        Case(i);
        solve();
    }
}