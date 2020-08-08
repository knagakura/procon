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
bool isprime(ll v) {
    if (v == 1) return false;
    if (v == 2) return true;
    for (ll i = 2; i*i <= v; i++){
        if (v % i == 0)return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    if(N == 1){
        cout << "Not Prime" << endl;
        return 0;
    }
    if(isprime(N)){
        cout << "Prime" << endl;
        return 0;
    }
    auto ketawa = [&](ll X) -> ll{
        ll res = 0;
        while(X){
            res += X % 10;
            X /= 10;
        }
        return res;
    };
    // 合成数
    if((N%10)%2 != 0 && N % 10 != 5 && ketawa(N)%3 != 0){
        cout << "Prime" << endl;
    }
    else{
        cout << "Not Prime" << endl;
    }

}
