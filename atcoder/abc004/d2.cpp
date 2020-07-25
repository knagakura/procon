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

    ll R,G,B;
    cin >> R >> G >> B;
    auto f = [&](ll x){
        return x * (x+1) / 2;
    };
    auto g = [&](ll l, ll r, ll x, ll cnt){
        ll res = 0;
        if(l <= x && x <= r){
            res += f(abs(x-l));
            res += f(abs(r-x));
        }
        else if(r < x){
            res += cnt * abs(x - r);
            res += f(cnt - 1);
        }
        else{
            res += cnt * abs(x - l);
            res += f(cnt-1);
        }
        return res;
    };
    ll ans = INFLL;

    // 左にi個、右にG-1-i個
    for(ll i = 0; i <= G-1; i++){
        ll sum1 = 0;
        sum1 += f(i);
        sum1 += f(G-1-i);
        // 左について
        if(i > 99){
            ll sum2 = sum1;
            sum2 += (i-99)*R;
            sum2 += f(R-1);
            // 右について
            ll k = G-1-i;
            if(k > 99){
                ll sum3 = sum2;
                sum3 += (k-99)*B;
                sum3 += f(B-1);
                chmin(ans, sum3);
            }
            else{
                ll l = 99 - k;
                for(ll m = 0; m <= min(l,B-1); m++){
                    ll sum3 = sum2;
                    sum3 += f(m);
                    sum3 += f(B-1-m);
                    chmin(ans, sum3);
                }
            }
        }
        else{
            ll r = 99 - i;
            for(ll j = 0; j <= min(r,R-1); j++){
                ll sum2 = sum1;
                sum2 += f(j);
                sum2 += f(R-1-j);
                // 右について
                ll k = G-1-i;
                if(k > 99){
                    ll sum3 = sum2;
                    sum3 += (k-99)*B;
                    sum3 += f(B-1);
                    chmin(ans, sum3);
                }
                else{
                    ll l = 99 - k;
                    for(ll m = 0; m <= min(l,B-1); m++){
                        ll sum3 = sum2;
                        sum3 += f(m);
                        sum3 += f(B-1-m);
                        chmin(ans, sum3);
                    }
                }
            }
        }
    }
    
    for(ll i = -3000; i <= 3000; i++){
        ll tmp = 0;
        ll l = i;
        ll r = l + R - 1;
        tmp += g(l,r,-100,R);
        
        l = r+1;
        r = l+G-1;
        tmp += g(l,r,0,G);

        l = r+1;
        r = l+B-1;
        tmp += g(l,r,100,B);
        chmin(ans, tmp);
    }
    cout << ans << endl;
}
