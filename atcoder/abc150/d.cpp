#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,M;
    cin>>N>>M;
    vector<ll> a(N);
    vector<ll> mod2(N);
    rep(i,N){
        cin>>a[i];
        mod2[i] = (a[i]/2) % 2;
    }
    sort(all(mod2));
    rep(i,N-1){
        if(mod2[i] != mod2[i+1]){
            cout<<0<<endl;
            return 0;
        }
    }
    ll l = a[0]/2;
    rep(i,N){
        a[i] /= 2;
        l = lcm(l,a[i]);
    }
    //cerr<<l<<endl;
    rep(i,N){
        if(l > a[i] && l / a[i] % 2 == 0){
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans = 0;
    if((M/l) % 2 == 1){
        ans = M / l / 2 + 1;
    }
    else{
        ans = M / l / 2;
    }
    cout<<ans<<endl;
}