#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int M;
vector<int> d;
vector<ll> c;
/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>M;
    d.resize(M);
    c.resize(M);
    ll sumc = 0;
    rep(i,M){
        cin>>d[i]>>c[i];
        sumc += c[i];
    }
    ll yuyo = 0;
    rep(i,M){
        if(4 <= d[i]&&d[i]<=6){
            yuyo += (c[i]-1)*1;
        }
        if(7 <= d[i]&&d[i]<=9){
            yuyo += (c[i]-1)*2;
        }
    }
    rep(i,M-1){
        if(d[i] + d[i+1] >10 && (d[i] + d[i+1]) % 10 + d[i+1] >= 10){
            yuyo += 1;
        }
    }
    //cerr<<"猶予: "<<yuyo<<endl;
    ll ans = sumc + yuyo - 1;
    cout<<ans<<endl;
}