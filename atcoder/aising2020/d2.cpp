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
// cnt + 1, cnt - 1
ll beki[2][200010];
ll ans[200010];
ll f(ll X, int cnt = 1){
    if(X == 0)return cnt;
    ll M = __builtin_popcount(X);
    return f(X%M, cnt+1);
}
int main() {

    ll N;
    string X;
    cin >> N >> X;
    reverse(all(X));
    int cnt = 0;
    rep(i,N)cnt += X[i] == '1';
    ll tmp = 1;
    rep(i,N){
        beki[0][i] = tmp % (cnt+1);
        tmp *= 2;
        tmp %= (cnt+1);
    }
    tmp = 1;
    rep(i,N){
        if(cnt - 1 == 0){
            beki[1][i] = -1;
            continue;
        }
        beki[1][i] = tmp % (cnt - 1);
        tmp *= 2;
        tmp %= (cnt - 1);
    }
    ll X0[2] = {0,0};
    rep(j,2){
        ll M = cnt;
        if(j == 0)M++;
        else M--;
        rep(i,N){
            if(M == 0)break;
            if(X[i] == '1')X0[j] += beki[j][i];
            X0[j] %= M;
        }
    }
    rep(i,N){
        ll M = cnt;
        ll tmpX;
        if(X[i] == '1'){
            M--;
            if(M == 0){
                ans[i] = 0;
                continue;
            }
            tmpX = X0[1];
            tmpX -= beki[1][i];
            tmpX += M;
            tmpX %= M;
        }
        else{
            M++;
            tmpX = X0[0];
            tmpX += beki[0][i];
            tmpX %= M;
        }
        ans[i] = f(tmpX);
    }
    rep(i,N){
        cout << ans[N-1-i] << endl;
    }
}

