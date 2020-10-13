#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define print2(x,y) cout << (x) << " " << (y) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    ll W;
    cin >> T >> W;
    rep(t,0,T){
        ll R[7] = {};
        ll D[7] = {};
        rep(i,0,W){
            cout << i+1 << endl;
            ll res;
            cin >> res;
            D[i] = res;

        }
        R[0] = 100*D[0] - 100*D[1] - 50*D[2] +0 * D[3] + 0 * D[4] + 25 * D[5];
        R[1] = -1200*D[0] + 1200*D[1] + 100*D[2] +0 * D[3] + 0 * D[4] - 50 * D[5];
        R[2] = -400*D[0] - 600*D[1] + 1200*D[2] +0 * D[3] + 0 * D[4] - 100 * D[5];
        R[3] = 1600*D[0] - 1600*D[1] - 800*D[2] +1000 * D[3] + 0 * D[4] - 100 * D[5];
        R[4] = -1600*D[0] + 1600*D[1] + 800*D[2] -1000 * D[3] + 1000 * D[4] - 400 * D[5];
        R[5] = 2400*D[0] - 400*D[1] - 1200*D[2] +0 * D[3] - 1000 * D[4] + 600 * D[5];
        rep(i,0,6){
            R[i] /= 1000;
            if(i == 5){
                cout << R[i] << endl;
            }else{
                cout << R[i] << " ";
            }
        }
        ll is_valid;
        cin >> is_valid;
        if(is_valid == -1){
            return 0;
        }

    }
    
}