#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
typedef long long ll;


void solve(){
ll X, Y;
    cin >> X >> Y;
    ll wa = abs(X)+abs(Y);
    if(wa % 2 == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    //長さを決め打って貪欲
    for(int len = 1;len <= 33;len++){
        string ans = "";
        ll u = X + Y;
        ll v = X - Y;
        ll nx = 0;
        ll ny = 0;
        for(int j = len-1; j >= 0;j--){
            //目的地まで+にしたい
            if(nx <= u){
                nx += bit(j);
                if(ny <= v){
                    ny += bit(j);
                    ans.push_back('E');
                }
                else{
                    ny -= bit(j);
                    ans.push_back('N');
                }
            }
            else{
                nx -= bit(j);
                if(ny <= v){
                    ny += bit(j);
                    ans.push_back('S');
                }
                else{
                    ny -= bit(j);
                    ans.push_back('W');
                }
            }
        }
        reverse(all(ans));
        if(nx == X+Y && ny == X-Y){
            cout << ans << endl;
            return;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout <<"Case #" <<i<<": ";
        solve();
    }
}
