#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;
int t, w;

ll R[7];
ll V;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t >> w;
    while(t--){
        //calc
        // V[1]を使う
        cout << 191 << endl;
        cin >> V;
        R[6] = (V >> (191 / 6)) % 128;
        R[5] = (V >> (191 / 5)) % 128;
        R[4] = (V >> (191 / 4)) % 128;
        // V[2]を使う
        cout << 48 << endl;
        cin >> V;
        V -= (R[4]<<(48/4));
        V -= (R[5]<<(48/5));
        V -= (R[6]<<(48/6));
        R[3] = (V >> (48 / 3)) % 128;
        R[2] = (V >> (48 / 2)) % 128;
        R[1] = (V >> (48 / 1)) % 128;
        //output
        for(int i = 1; i <= 6; i++){
            cout << R[i];
            if(i == 6)cout << endl;
            else cout << " ";
        }
        //last input
        int valid;
        cin >> valid;
        if(valid == -1)return 0;
    }
}