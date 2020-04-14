#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll XOR_cum(ll X){
    ll res = X;
    if(X % 4 == 0)res = X;
    if(X % 4 == 1)res = 1;
    if(X % 4 == 2)res = X + 1;
    if(X % 4 == 3)res = 0;
    return res;
}
    
int main() {
    ll A,B;
    cin>>A>>B;
    ll ans = XOR_cum(B)^XOR_cum(max(0LL,A-1));
    cout<<ans<<endl;
}
