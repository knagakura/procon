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

    ll N,A,B;
    cin>>N>>A>>B;
    ll ans[] = {INFLL,INFLL};
    ll a,b;
    if((B - A) % 2 == 0){
        ans[0] = (B - A) / 2;
    }
    else{
        {
            a = A;
            b = B;
            ans[0]  = 0;
            ans[0] += A-1;
            a -= A-1;
            b -= A-1;

            a -= 0;
            b -= 1;
            ans[0] += 1;

            ans[0] += (b - a) / 2;
        }
        {
            a = A;
            b = B;
            ans[1] = 0;
            ans[1] +=  N - B;
            a += N-B;
            b += N-B;

            a += 1;
            b += 0;
            ans[1] += 1;

            ans[1] += (b - a)/2;
        }
    }
    //cerr<<ans[0]<<" "<<ans[1]<<endl;
    cout<<min(ans[0], ans[1])<<endl;
}