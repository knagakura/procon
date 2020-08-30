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

template<typename T>
vector<T> smallest_prime_factors(T n) {
    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;
    for (T i = 2; i * i <= n; i++) {
        // 素数だったら
        if (spf[i] == i) {
            for (T j = i * i; j <= n; j += i) {
                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

template<typename T>
map<T, int> factolization(T x, vector<T> &spf) {
    map<T, int> mp;
    while (x != 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}
int main(){
    constexpr ll MAX = 1000000;
    auto spf = smallest_prime_factors(MAX);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    vector<int> v(MAX, 0);
    ll G = 0;
    rep(i,N) {
        G = gcd(G, A[i]);
        auto result = factolization(A[i], spf);
        for(auto p: result)v[p.first]++;
    }
    bool ok = true;
    rep(i,MAX)if(v[i] >= 2)ok = false;
    if(ok){
        cout << "pairwise coprime" <<endl;
    }
    else if(G == 1){
        cout << "setwise coprime" << endl;
    }
    else{
        cout << "not coprime" << endl;
    }
    return 0;
}
