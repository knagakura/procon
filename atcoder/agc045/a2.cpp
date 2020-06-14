#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)

void solve(){
    int N;
    string S;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    cin >> S;
    if(S.back() == '1'){
        cout << 1 << endl;
        return;
    }
    else{
        cout << 0 << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}