#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


ll a,m;

void solve(){
    cin >> a >> m;
    ll g = gcd(a,m);
    ll a_d = a / g;
    ll m_d = m / g;
    cerr<<"(g ,a', m'): "<<g<<" "<<a_d<<" "<<m_d<<endl;

    map<ll, int> mm = factorize(m_d);
    ll ans = m_d+1;
    ll tmp = 1;
    for(auto p:mm){
        tmp *= (p.second+1);
    }
    ans -= tmp;
    cout<<ans<<endl;
    // 0 <= c < m_d
    // && m_dと互いに素
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin>> Q;
    while(Q--){
        solve();
    }
}