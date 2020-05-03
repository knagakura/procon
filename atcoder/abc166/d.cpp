#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
template<typename T, typename U>
T _pow(T a, U n) {
    T res = 1;
    rep(i, n)res *= a;
    return res;
}
template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X;
    cin >> X;
    auto v = divisor(X);
    //print(v);
    int sz = v.size();
    rep(i,sz){
        //a-b = v[i]とする
        //a = b + v[i]
        for(ll b = -1000; b <= 1000;b++){
            ll a = b + v[i];
            ll sl  = _pow(a,5) - _pow(b,5);
            if(sl == X){
                cout << a << " " << b << endl;
                return 0;
            }
            a = b - v[i];
            sl  = _pow(a,5) - _pow(b,5);
            if(sl == X){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}