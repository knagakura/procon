#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
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

ll dp[2020][2020];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<ll> A(N);
    vector<l_l> v;
    rep(i, N) {
        cin >> A[i];
        v.emplace_back(A[i], i);
    }
    sort(v.rbegin(), v.rend());
    rep(i, N+1)rep(j, N+1)dp[i][j] = -INFLL;
    dp[0][0] = 0;
    //dp[i][l] := i個目までみて、左にj個入れてるときの最大値
    rep(i, N) {
        rep(l, N) {
            if (i < l)continue;
            ll a = v[i].first;
            ll idx = v[i].second;
            ll r = i - l;
            chmax(dp[i + 1][l + 1], dp[i][l] + a * abs(idx - l));
            chmax(dp[i + 1][l], dp[i][l] + a * abs(idx - (N  - r - 1)));
        }
    }
    ll ans = -INFLL;
    rep(i, N + 1)chmax(ans, dp[N][i]);
    cout << ans << endl;
}

/*
貪欲は無理
ある程度の貪欲性が必要な処理かな？
O(N^2)はかけてよい。
1 3 4 2

1 -> 3 -> 1
2 -> 4 -> 2
*/