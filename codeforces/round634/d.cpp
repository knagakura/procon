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

void solve(){
    vector<string> a(9);
    rep(i,9)cin >> a[i];
    pair<int, int> p[] = {
        {0,0},
        {1,4},
        {2,8},
        {3,6},
        {4,1},
        {5,5},
        {6,3},
        {7,7},
        {8,2}
    };
    rep(i,9){
        rep(j,9){
            bool ch = false;
            rep(k,9){
                if(i == p[k].first && j == p[k].second){
                    ch = true;
                    break;

                }
            }
            if(ch){
                    int d = a[i][j] - '0';
                    d++;
                    if(d == 10)d = 1;
                    cout << d;
            }
            else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
/*
154 873 396
336 592 714
729 645 835

863 725 145
979 314 628
412 958 357

631 457 992
998 236 471
247 789 563

*/