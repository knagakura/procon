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
    int N, K;
    cin >> N >> K;
    vec<int> A(N), B(N);
    rep(i, N) {
        cin >> A[i];
        if (A[i] < K) B[i] = 0;
        if (A[i] == K)B[i] = 1;
        if (A[i] > K) B[i] = 2;
    }
    bool exist = false;
    rep(i, N)if (B[i] == 1)exist = true;
    //一個もKがなかったらダメ
    if (not exist) {
        cout << "no" << endl;
        return;
    }
    bool ok = false;
    if (N == 1)ok = true;
    rep(i, N) {
        for (int j = i + 1; j < N and j - i <= 2; j++) {
            if (B[i] and B[j])ok = true;
        }
    }
    //1個以上はある状態
    cout << (ok ? "yes" : "no") << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    while (t--) solve();
}