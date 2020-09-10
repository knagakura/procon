#include <bits/stdc++.h>
#include <atcoder/dsu.hpp>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {os << "{" <<p.first << ", " << p.second << "}";return os;}
struct fast_ios{ fast_ios(){cin.tie(0);ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#ifdef DEBUG
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#else
#define dump(x)
#define print(v)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


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


int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    ll G = A[0];
    rep(i,N)G = gcd(G, A[i]);
    vector<int> cnt(1010101, 0);
    bool ok = true;
    rep(i,N){
        auto v = factorize(A[i]);
        for(auto p: v){
            cnt[p.first]++;
            if(cnt[p.first] >= 2){
                ok = false;
                i = N+1;
                break;
            }
        }
    }
    if(ok)cout << "pairwise coprime" << endl;
    else if(G == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}
