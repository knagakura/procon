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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll H, W, M;
    cin >> H >> W >> M;
    vec<int> cntx(H,0), cnty(W,0);
    map<l_l, int> mp;
    vector<l_l> cnt_x;
    vector<l_l> cnt_y(1, {-1,-1});
    rep(i,M){
        int h, w;
        cin >> h >> w;
        h--; w--;
        cntx[h]++;
        cnty[w]++;
        mp[{h,w}]++;
    }
    rep(i,H)cnt_x.emplace_back(cntx[i], i);
    rep(j,W)cnt_y.emplace_back(cnty[j], j);
    sort(all(cnt_x), greater<>());
    sort(all(cnt_y));
    vector<int> kouho_y;
    for(int i = W; i >= 0; i--){
        kouho_y.emplace_back(cnt_y[i].second);
        if(cnt_y[i].first != cnt_y[i-1].first)break;
    }
    ll maxxy = cnt_y.back().first;
    ll ans = 0;
    rep(i,H){
        int idx = cnt_x[i].second;
        ll tmp = cnt_x[i].first;
        if(ans >= tmp + maxxy)break;
        for(auto y: kouho_y){
            chmax(ans, tmp + maxxy - (mp[{idx,y}] > 0));
            if(ans >= tmp + maxxy)break;
        }
    }
    cout << ans << endl;
}