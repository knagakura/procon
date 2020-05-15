#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {

    ll N,M,X;
    cin >> N >> M >> X;
    vector<ll> C(N);
    vvec<ll> A(N,vec<ll>(M));
    rep(i,N){
        cin >> C[i];
        rep(j,M){
            cin >> A[i][j];
        }
    }
    ll ans = INFLL;
    for(int s = 0; s < bit(N);s++){
        ll tmp = 0;
        vector<ll> sum(M,0);
        rep(i,N){
            if(s & bit(i)){
                tmp += C[i];
                rep(j,M){
                    sum[j] += A[i][j];
                }
            }
        }
        bool ok = true;
        rep(j,M){
            if(sum[j] < X)ok = false;
        }
        if(ok){
            chmin(ans, tmp);
        }
    }
    if(ans == INFLL){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}