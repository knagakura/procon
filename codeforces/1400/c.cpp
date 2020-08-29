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
const ll MOD = 1'000'000'007;
// const ll MOD = 998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

void solve(){
    string S;
    cin >> S;
    ll N = S.size();
    int x;
    cin >> x;
    string ans;
    rep(i,N)ans.push_back('1');
    rep(i,N){
        int l = i - x;
        if(0 <= l){
            if(S[i] == '0')ans[l] = '0';
        }
        int r = i + x;
        if(r < N){
            if(S[i] == '0')ans[r] = '0';
        }
    }
    bool ok = true;
    rep(i,N){
        int l = i - x;
        int r = i + x;
        if(0 <= l && r < N){
            if(S[i] == '1'){
                if(ans[l] == '0' and ans[r] == '0')ok = false;
            }
        }
        if(0 <= l && r >= N){
            if(S[i] == '1'){
                if(ans[l] == '0')ok = false;
            }
        }
        if(l < 0 && r < N){
            if(S[i] == '1'){
                if(ans[r] == '0')ok = false;
            }
        }
        // 両方存在しないのに1
        if(l < 0 && N <= r){
            if(S[i] == '1')ok = false;
        }
    }
    // dump(ans);
    if(not ok)cout << -1 << endl;
    else cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
