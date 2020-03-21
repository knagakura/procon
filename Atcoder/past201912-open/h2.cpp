#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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
ll N;
vector<ll> C;
ll Q;
ll x, a;
ll minuss;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    C.resize(N);
    ll odd_min = INFLL;
    ll all_min = INFLL;
    rep(i,N){
        cin >> C[i];
        if(i % 2 == 0){
            chmin(odd_min, C[i]);
        }
        chmin(all_min, C[i]);
    }
    cin >> Q;
    ll all_sum = 0;
    ll odd_sum = 0;
    vector<ll> sums(N, 0);
    ll ans = 0;
    while(Q--){
        ll op;
        cin >> op;
        if(op == 1){
            cin >> x >> a;
            x--;
            minuss = a + sums[x] + all_sum;
            if(x % 2 == 0)minuss += odd_sum;
            if(C[x] - minuss < 0)continue;
            sums[x] += a;
            ans += a;
            if(x % 2 == 0)chmin(odd_min, C[x] - minuss);
            chmin(all_min, C[x] - minuss);
        }
        if(op == 2){
            cin >> a;
            minuss = (N + 1) / 2  * a;
            if(odd_min < a)continue;
            chmin(odd_min, odd_min-a);
            chmin(all_min, odd_min);
            odd_sum += a;
            ans += minuss; 
        }
        if(op == 3){
            cin >> a;
            minuss = N * a;
            if(all_min < a)continue;
            chmin(all_min, all_min-a);
            chmin(odd_min, odd_min-a);
            all_sum += a;
            ans += minuss;
        }
        /*
        cerr<< op << " " << (op == 1 ? to_string(x):"") <<  " " << a << endl;
        dump(odd_min);
        dump(all_min);
        dump(all_sum);
        dump(odd_sum);
        dump(ans)
        print(C);cerr<<endl;
        */
    }
    cout << ans << endl;
}