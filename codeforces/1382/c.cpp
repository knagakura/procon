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
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    vector<int> x(N), y(N);
    rep(i,N){
        x[i] = a[i] - '0';
        y[i] = b[i] - '0';
    }
    int l = 0;
    int r = N-1;
    int cnt_all = 0;
    vector<int> cnt(N,0);
    vector<int> ans;
    for(int i = N-1; i >= 0; i--){
        int xr = x[r] + cnt_all + cnt[r];
        int xl = x[l] + cnt_all + cnt[l];
        xr %= 2;
        xl %= 2;
        if(xr == y[i]){
            if(l < r)r--;
            else r++;
            continue;
        }
        if(xl != xr){
            xl ^= 1;
            cnt[l]++;
            ans.push_back(1);
        }
        swap(l,r);
        ans.push_back(i+1);
        cnt_all++;
        if(l < r)r--;
        else r++;
    }
    cout << ans.size() << " ";
    for(auto v: ans){
        cout << v << " ";
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
