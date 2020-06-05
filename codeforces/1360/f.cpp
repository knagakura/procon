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
void solve() {
    int N, M;
    cin >> N >> M;
    vec<string> a(N);
    rep(i, N)cin >> a[i];
    if (M == 1) {
        cout << 'a' << endl;
        return;
    }
    auto check = [&](string &x, string &y) {
        int res = 0;
        rep(i, M) {
            if (x[i] != y[i])res++;
        }
        return res;
    };
    vvec<int> diff(N, vec<int>(N, 0));
    int maxd = 0;
    rep(i, N)
        rep(j, N) {
            diff[i][j] = check(a[i], a[j]);
            chmax(maxd, diff[i][j]);
        }
    //rep(i,N)print(diff[i]);
    if (M == 2) {
        if (maxd <= 1) {
            cout << a[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if (maxd > 2) {
        cout << -1 << endl;
        return;
    }
    if (maxd <= 1) {
        cout << a[0] << endl;
        return;
    }
    if (maxd == 2) {
        rep(i, N)
            rep(j, N) {
                if (diff[i][j] == 2) {
                    string ans;
                    int cnt = 0;
                    rep(k, M) {
                        if (a[i][k] != a[j][k]) {
                            if (cnt)ans.push_back(a[i][k]);
                            else ans.push_back(a[j][k]);
                            cnt++;
                        } else {
                            ans.push_back(a[i][k]);
                        }
                    }
                    cout << ans << endl;
                    return;
                }
            }
        //cout << maxd << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while (t--) solve();
}