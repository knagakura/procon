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

void solve(){
    int N;
    cin >> N;
    vec<string> S(N);
    rep(i,N)cin >> S[i];
    vvec<bool> ok(N,vec<bool>(N,true));
    vvec<bool> ok2(N,vec<bool>(N,true));
    //行方向
    for(int i = N-2;i >= 0; i--){
        rep(j,N){
            if(S[i][j] == '1' && S[i+1][j] == '0'){
                ok[i][j] = false;
            }
        }
    }

    for(int j = N-2;j >= 0; j--){
        rep(i,N){
            if(S[i][j] == '1' && S[i][j+1] == '0'){
                ok2[i][j] = false;
            }
        }
    }
    bool ans = true;
    rep(i,N)rep(j,N){
        if(!ok[i][j] && !ok2[i][j])ans = false;
    }
    cout << (ans ? "YES": "NO") << endl;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    while(t--) solve();

}