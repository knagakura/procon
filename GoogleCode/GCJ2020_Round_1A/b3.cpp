#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define bit(k) (1LL<<(k))

void solve(){
    int N;
    cin >> N;
    if(N < 30){
        rep1(i,N+1){
            cout << i << " " << 1 << endl;
        }
        return;
    }
    N -= 30;
    int isleft = 1;
    int cnt = 0;
    for(int r = 1; r <= 30;r++){
        if(N & bit(r-1)){
            cnt++;
            if(isleft){
                for(int col = 1; col <= r;col++){
                    cout << r << " " << col << endl;
                }
            }
            else{
                for(int col = r; col >= 1;col--){
                    cout << r << " " << col << endl;
                }
            }
            isleft ^= 1;
        }
        else{
            cout << r << " " << (isleft ? 1: r) << endl;
        }
    }
    for(int k = 1; k <= cnt;k++){
        cout << 30 + k << " " << (isleft ? 1: 30 + k) << endl;
    }
}
int main() {
    int t;
    cin >> t;
    rep1(i, t+1){
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}