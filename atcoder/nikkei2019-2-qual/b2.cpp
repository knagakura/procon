#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll MOD = 998244353;

ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin>>N;
    vector<ll> D(N);
    ll maxd = 0;
    map<int, int> map;
    rep(i,N){
        cin>>D[i];
        map[D[i]]++;
        chmax(maxd, D[i]);
    }
    if(D[0] != 0||map[0]>1){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 1;
    rep(i,maxd){
        ans *= modpow(map[i],map[i+1],MOD);
        ans %= MOD;
    }
    cout<<ans<<endl;
}