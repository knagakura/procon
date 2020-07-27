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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<ll> X(N),Y(N);
    vector<char> U(N);
    ll maxx = -INF;
    ll minn = INF;
    rep(i,N){
        cin >> X[i] >> Y[i] >> U[i];
        chmin(minn, X[i]-Y[i]);
        chmax(maxx, X[i]-Y[i]);
    }
    map<char,int> mp;
    mp['U'] = 0;
    mp['R'] = 1;
    mp['D'] = 2;
    mp['L'] = 3;
    ll len = maxx - minn + 1;
    dump(len);
    dump(maxx);
    dump(minn);
    vvec<pair<ll,ll>> v[4];
    rep(i,4)v[i].resize(len);
    rep(i,N){
        v[ mp[U[i]] ][ X[i]-Y[i]-minn ].push_back({X[i],Y[i]});
    }
    rep(i,4)rep(j,len)sort(all(v[i][j]));
    rep(i,4)rep(j,len){
        if(not v[i][j].empty()){
            dump(i);
            dump(j);
            print(v[i][j]);
        }
    }
    ll ans = INFLL;
}
