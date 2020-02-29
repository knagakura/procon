#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
/*------------------------------------*/
ll l, r;
ll m;
vector<ll> n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>l>>r>>m;
    n.resize(m);
    rep(i,m)cin>>n[i];
    sort(all(n));
    if(n[0] == 1){
        cout<< 0 <<endl;
        return 0;
    }
    if (m == 1){
        if(r <= (ll)1e5){
            ll ans = r - l + 1;
            for (int i = l; i <=r; i++){
                if(i % n[0] == 0){
                    ans--;
                }
            }
            cout<<ans<<endl;
            return 0;
        }
    }
    else if(m > 1){
        if(r <= (ll)1e5){
            ll ans = r - l + 1;
            for (int i = l; i <= r;i++){
                rep(j,m){
                    if(i % n[j] == 0){
                        ans--;
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
}