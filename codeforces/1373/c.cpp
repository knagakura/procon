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
    string S;
    cin >> S;
    int N = S.size();
    vector<int> cum(N+1,0);
    rep(i,N){
        cum[i+1] += cum[i] + (S[i] == '+' ? 1:-1);
    }

    //最初に-iになるまでのindexの位置
    vector<int> idx(N+1,-1);
    rep1(i,N+1){
        if(cum[i] >= 0)continue;
        //cum[i] < 0
        if(idx[-cum[i]] >= 0)continue;
        idx[-cum[i]] = i;
    }
    //
    int minn = INF;
    rep1(i,N+1){
        chmin(minn, cum[i]);
    }
    ll ans = N;
    if(minn >= 0){
        cout << ans << endl;        
        return;
    }
    for(int i = 1; i <= abs(minn); i++){
        ans += idx[i];
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