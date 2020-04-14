#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    REP(i,N) cin >> a[i];
    REP(i,N) cin >> b[i];
    ll ans = 0;
    for(int d=29;d>=0;d--){
        ll high = 1 << (d+1), low = 1 << d;
        REP(i,N) a[i] %= high, b[i] %= high;
        sort(b.begin(), b.end());
        ll sum = 0;
        REP(i,N){
            int tmp = 0;
            if(low - a[i] >= 0) tmp += lower_bound(b.begin(), b.end(), high-a[i]) - lower_bound(b.begin(), b.end(), low-a[i]);
            else{
                tmp += lower_bound(b.begin(), b.end(), high-a[i]) - b.begin();
                tmp += lower_bound(b.begin(), b.end(), high) - lower_bound(b.begin(), b.end(), high + low-a[i]);
            }
            sum += tmp;
        }
        cerr << sum << endl;;
        if(sum & 1) ans += low;
    }
    cout << ans << endl;
}
