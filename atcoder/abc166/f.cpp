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

ll dp[200010][2][3];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<string> S(N);
    rep(i, N)cin >> S[i];
    rep(i, N + 1)
        rep(j, 2)
            rep(k, 3) {
                dp[i][j][k] = -INFLL;
            }
    dp[0][0][0] = A;
    dp[0][0][1] = B;
    dp[0][0][2] = C;
    rep(i, N)
        rep(j, 2) {
            if (S[i] == "AB") {
                if (dp[i][j][0] < 0 || dp[i][j][1] < 0)continue;
                chmax(dp[i + 1][0][0], dp[i][j][0] + 1);
                chmax(dp[i + 1][0][1], dp[i][j][1] - 1);
                chmax(dp[i + 1][1][0], dp[i][j][0] - 1);
                chmax(dp[i + 1][1][1], dp[i][j][1] + 1);
                chmax(dp[i + 1][0][2], dp[i][j][2]);
                chmax(dp[i + 1][1][2], dp[i][j][2]);
            }
            if (S[i] == "BC") {
                if (dp[i][j][1] < 0 || dp[i][j][2] < 0)continue;
                chmax(dp[i + 1][0][1], dp[i][j][1] + 1);
                chmax(dp[i + 1][0][2], dp[i][j][2] - 1);
                chmax(dp[i + 1][1][1], dp[i][j][1] - 1);
                chmax(dp[i + 1][1][2], dp[i][j][2] + 1);
                chmax(dp[i + 1][0][0], dp[i][j][0]);
                chmax(dp[i + 1][1][0], dp[i][j][0]);
            }

            if (S[i] == "AC") {
                if (dp[i][j][0] < 0 || dp[i][j][2] < 0)continue;
                chmax(dp[i + 1][0][0], dp[i][j][0] + 1);
                chmax(dp[i + 1][0][2], dp[i][j][2] - 1);
                chmax(dp[i + 1][1][0], dp[i][j][0] - 1);
                chmax(dp[i + 1][1][2], dp[i][j][2] + 1);
                chmax(dp[i + 1][0][1], dp[i][j][1]);
                chmax(dp[i + 1][1][1], dp[i][j][1]);
            }
        }

    bool a = true;
    rep(j, 2) {
        bool ok = true;
        if(!a)continue;
        rep(k, 3) {
            if (dp[N][j][k] < 0)ok = false;
        }
        if(ok){
            cout << "Yes" << endl;
            a = false;
        }
    }
    if(a){
        cout << "No" << endl;
    }
}