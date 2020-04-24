#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(int i = 0; i < N;i++)cin >> X[i] >> Y[i];
    int wa = abs(X[0])+abs(Y[0]);
    for(int i = 0; i < N;i++){
        if(wa%2 != (abs(X[i])+abs(Y[i]))%2){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<ll> d;
    for(int s = 32;s >= 0;s--){
        d.push_back(bit(s));
    }
    if((X[0]+Y[0])%2 == 0){
        d.push_back(1);
    }
    cout << d.size() << endl;
    rep(i,d.size()){
        cout << d[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        string ans = "";
        ll u = X[i] + Y[i];
        ll v = X[i] - Y[i];
        ll nx = 0;
        ll ny = 0;
        for(int j = 0; j < d.size();j++){
            //目的地まで+にしたい
            if(nx <= u){
                nx += d[j];
                if(ny <= v){
                    ny += d[j];
                    ans.push_back('R');
                }
                else{
                    ny -= d[j];
                    ans.push_back('U');
                }
            }
            else{
                nx -= d[j];
                if(ny <= v){
                    ny += d[j];
                    ans.push_back('D');
                }
                else{
                    ny -= d[j];
                    ans.push_back('L');
                }
            }
        }
        cout << ans << endl;
    }
}