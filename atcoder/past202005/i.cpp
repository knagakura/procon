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

    int N,Q;
    cin >> N >> Q;
    /*
    vvec<int> A(N,vec<int>(N));
    rep(i,N)rep(j,N){
        A[i][j] = N*i+j;
    }*/
    vec<ll> gyo(N);
    vec<ll> retu(N);
    rep(i,N){
        gyo[i] = i;
        retu[i] = i;
    }
    int cnt = 0;
    while(Q--){
        int ord,a,b;
        cin >> ord;
        if(ord == 1){
            cin >> a >> b;
            a--,b--;
            if(cnt&1){
                swap(retu[a],retu[b]);
            }
            else{
                swap(gyo[a],gyo[b]);
            }
        }
        if(ord == 2){
            cin >> a >> b;
            a--,b--;
            if(cnt&1){
                swap(gyo[a],gyo[b]);
            }
            else{
                swap(retu[a],retu[b]);
            }
        }
        if(ord == 3){
            /*転置*/
            cnt++;
        }
        if(ord == 4){
            cin >> a >> b;
            a--,b--;
            if(cnt&1){
                cout << gyo[b] * N + retu[a] << endl;
            }
            else {
                cout << gyo[a] * N + retu[b] << endl;
            }
        }
    }
}