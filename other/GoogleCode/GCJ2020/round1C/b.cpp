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
void Case(int i) {
    cout << "Case #" << i << ": ";
}

int U;//桁数の上限 ex) U = 2 -> 00 ~ 99
int MX = 10000;
vector<string> Q(MX);
vector<string> M(MX);
vector<string> R(MX);

void input() {
    cin >> U;
    rep(i, MX)cin >> M[i] >> R[i];
}

void solve_u2() {
    vector<char> ans(10, '*');
    //すでにその数字が出たか確認
    map<char, int> map;
    rep1(d, 10) {
        rep(i, MX) {
            // 最上位桁がdで、長さが同じとき
            if (M[i][0] - '0' == d) {
                if (M[i].size() == R[i].size()) {
                    if (map[R[i][0]] > 0)continue;
                    ans[d] = R[i][0];
                    map[R[i][0]]++;
                }
            }
        }
    }
    rep(i, MX)
        rep(j, R[i].size()) {
            if (map[R[i][j]] == 0) {
                ans[0] = R[i][j];
                break;
            }
        }
    rep(i, 10) {
        cout << ans[i];
    }
    cout << endl;
}

void solve_u16() {

}

void solve() {
    input();
    if (U == 2)solve_u2();
    else solve_u16();
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    rep(i, t) {
        Case(i + 1);
        solve();
    }
}