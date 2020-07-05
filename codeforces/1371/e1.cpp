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

    ll N, p; // p is prime number
    cin >> N >> p;
    vector<ll> a(N);
    rep(i, N)cin >> a[i];
    sort(all(a));
    // f(x): xから始まって全部に勝てる順列の数 -> できそう
    // f(x) is good if f(x) is not divisible by p.
    // その順列は前から候補を決めていく
    vector<ll> ans;
    // ansの候補を試す
    for(ll xx = 1; xx <= a[N-1]; xx++){
        ll x = xx;
        //dump(xx);
        bool ok = true;
        int l = 0;
        int r = 0;
        for(int i = 0; i < N; i++){
            while(r < N && a[r] <= x){
                r++;
            }
            //cerr << x << " " << "[" << l << ", " << r << ")" << endl;
            if((r - l) <= 0)ok = false;
            if((r - l) % p == 0)ok = false;
            l++;
            x++;
        }
        if(ok)ans.push_back(xx);
    }
    cout << ans.size() << endl;
    for(auto &val: ans){
        cout << val << " ";
    }
    cout << endl;
}
