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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    vector<ll> C(N);
    ll minc = INFLL;
    ll minc1 = INFLL;
    ll cumsum = 0;
    ll cumsum1 = 0;
    rep(i,N){
        cin>>C[i];
        chmin(minc,C[i]);
        if(i % 2 == 0)chmin(minc1, C[i]);
    }
    int Q;
    cin>>Q;
    ll ans = 0;
    rep(i,Q){
        int c;
        cin>>c;
        if(c == 1){
            ll x,a;
            cin>>x>>a;
            x--;
            if(x % 2 == 0){
                if(C[x] - cumsum1 - cumsum - a >= 0){
                    C[x] -= a;
                    chmin(minc1, C[x]-cumsum-cumsum1);
                }
            }
            else{
                if(C[x] - cumsum - a >= 0){
                    C[x] -= a;
                    chmin(minc, C[x] - cumsum);
                    chmin(minc1,C[x] - cumsum);
                }
            }
            /*
            if(C[x] - a >= 0){
                C[x] -= a;
                ans += a;
                if(x % 2 == 0){
                    chmin(minc1,C[x]);
                }
                chmin(minc, C[x]);
            }*/
        }
        if(c == 2){
            ll a;
            cin>>a;
            if(minc1 - a >= 0){
                minc1 -= a;
                cumsum1 += a;
                ans += a * (N + 1) / 2;
                chmin(minc, minc1);
            }
        }
        if(c == 3){
            ll a;
            cin>>a;
            if(minc - a >= 0){
                cumsum += a;
                minc -= a;
                minc1 -= a;
                ans += a * N;
            }
        }
        cerr<<minc<<" "<<minc1<<endl;
        print(C);
    }
    cout<<ans<<endl;
}