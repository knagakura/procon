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
    ll N;
    cin >> N;
    // good permutation
    // for all pair i, j{
        // p[i] | p[i+1] | ... | p[j] >= j - i + 1
    //}
    vector<ll> ans(N);
    ll cnt = 1;
    for(int i = 0; i < N; i+=2){
        ans[i] = cnt++;
    }
    cnt = N;
    for(int i = 1; i < N; i+=2){
        ans[i] = cnt--;
    }
    // bool ok = true;
    // rep(i,N)rep(j,N){
    //     if(i > j)continue;
    //     ll tmp = 0;
    //     for(int k = i; k <= j; k++){
    //         tmp |= ans[k];
    //     }
    //     if(tmp < j - i + 1)ok = false;
    // }
    // if(not ok)return;
    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
