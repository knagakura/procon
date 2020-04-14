#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/
 
const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n == 0) return 1;

    ll res = modpow(x, n/2);
    if(n%2 == 0) return res*res%mod;
    else return res*res%mod*x%mod;
}

ll power(ll x, ll n){
    if(n == 0) return 1;

    ll res = power(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

typedef tuple<ll, ll, ll> T;


vector<ll> a(55), p(55);

ll solve(ll n, ll x){
    cerr<<n<<" "<<x<<endl;
    if(n == 0) return 1; // !!!!!
    else if(x <= 1) return 0;
    else if(x <= 1+a[n-1]) return solve(n-1, x-1);
    else if(x == 2+a[n-1]) return 1+p[n-1];
    else if(x <= 2+2*a[n-1]) return 1+p[n-1]+solve(n-1, x-2-a[n-1]);
    else return p[n];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, x; cin >> n >> x;
    a[0] = p[0] = 1;
    for(int i=1; i<=n; ++i){
        a[i] = 2*a[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }

    cout << solve(n, x) << endl;
    
	return 0;
}
