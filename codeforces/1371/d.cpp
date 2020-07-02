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
ll N, K;
char ans[333][333];
void debug(){
    rep(i,N){
        rep(j,N){
            cerr << ans[i][j];
        }
        cerr << endl;
    }
    cerr << endl;
}
pair<ll,ll> X(ll y){
    return {y / N,y % N};
}
void solve(){
    cin >> N >> K;
    rep(i,N)rep(j,N){
        ans[i][j] = '0';
    }
    if(K == 0){
        rep(i,N){
            rep(j,N){
                cout << ans[i];
            }
            cout << endl;
        }
        return;
    }
    if(N%2 == 1){
        ans[N/2][N/2] = '1';
        K--;
    }
    if(K % 2 == 1){
        ans[0][0] = '1';
    }
    ll idx = 0;
    //debug();
    rep(i,K/2){
        int nx = idx / N;
        int ny = idx % N;
        //debug();
        while(1){
            nx = idx / N;
            ny = idx % N;
            if(ans[nx][ny] != '1' && ans[N-nx-1][N-1-ny] != '1'){
                if(N-nx-1 == nx && N-ny-1 == ny){
                    idx++;
                    continue;
                }
                break;
            }
            idx++;
        }
        ans[nx][ny] = '1';
        ans[N-1-nx][N-1-ny] = '1';
    }
    ll val = 0;
    ll minn = INFLL;
    ll maxx = 0;
    rep(i,N){
        ll sum = 0;
        rep(j,N){
            sum += ans[i][j] == '1';
        }
        chmin(minn, sum);
        chmax(maxx, sum);
    }
    val += (maxx - minn) * (maxx - minn);

    minn = INFLL;
    maxx = 0;
    rep(j,N){
        ll sum = 0;
        rep(i,N){
            sum += ans[i][j] == '1';
        }
        chmin(minn, sum);
        chmax(maxx, sum);
    }
    val += (maxx - minn) * (maxx - minn);
    cout << val << endl;
    rep(i,N){
        rep(j,N){
            cout << ans[i][j];
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
