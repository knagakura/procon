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

int t, w;
bool solve(){

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t >> w;
    while(t--){
        ll D[7] = {};
        //interact w times
        for(int i = 1; i <= w; i++){
            cout << i << endl;
            cin >> D[i];
        }
        int a[][8] = {
            {0,   0,   0,   0,  0,  0,  0,   0},
            {0,   4,  -4,  -2,  0,  0,  1,  40},
            {0, -24,  24,   2,  0,  0, -1,  20},
            {0,  -4,  -6,  12,  0,  0, -1,  10},
            {0,  16, -16,  -8, 10,  0, -1,  10},
            {0,  -8,   8,   4, -5,  5, -2,   5},
            {0,  12,  -2,  -6,  0, -5,  3,   5},
        };
        //calc
        ll ans[7] = {};
        for(int i = 1; i <= 6;i++){
            for(int j = 1; j <= 7;j++) {
                cerr << a[i][j] << " ";
            }
            cerr << endl;
        }
        for(int i = 1; i <= 6;i++){
            for(int j = 1; j <= 6;j++) ans[i] += a[i][j] * D[j];
            ans[i] /= a[i][7];
        }
        //output
        for(int i = 1; i <= 6; i++){
            cout << ans[i];
            if(i == 6)cout << endl;
            else cout << " ";
        }
        //last input
        int valid;
        cin >> valid;
        if(valid == -1)return 0;
    }
}