#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N/2),B(N/2);
    rep(i,N/2)cin>>A[i];
    rep(i,N/2)cin>>B[i];
    reverse(all(B));
    vector<ll> imos(2 * K+5, 0);
    int mxl = 0;
    int minr = INF;
    rep(i,N/2){
        int l = min(A[i], B[i]) + 1;
        int r = max(A[i], B[i]) + K;
        //cerr << l << " " << r << endl;
        //[0~l) +2
        imos[0]+=2;
        imos[l]-=2;
        //[l,r+1) +1
        imos[l]++;
        imos[r+1]--;
        //[r+1, ∞) +2
        imos[r+1]+=2;
        //[a+b,a+b+1) -1
        imos[A[i]+B[i]]--;
        imos[A[i]+B[i]+1]++;
        chmax(mxl, l);
        chmin(minr, r);
    }
    rep(i,2*K+1)imos[i+1]+=imos[i];
    /*
    print(A);
    print(B);
    print(imos);
    */
    ll ans = INFLL;
    for(int i = 2; i <= 2*K; i++){
        chmin(ans, imos[i]);
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}