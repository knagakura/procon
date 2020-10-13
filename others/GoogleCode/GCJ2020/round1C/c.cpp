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

int N, D;
vector<ll> A;

void input() {
    //N個のカット、D人
    cin >> N >> D;
    A.clear();
    A.resize(N);
    rep(i, N) {
        cin >> A[i];
    }
    sort(all(A));
}

void solve_d2() {
    if (N == 1) {
        cout << 1 << endl;
        return;
    }
    // N >= D
    map<ll, ll> map;
    rep(i, N)map[A[i]]++;
    for (auto p: map) {
        if (p.second >= D) {
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

void solve_d3() {
    if (N == 1) {
        cout << 2 << endl;
        return;
    }
    if (N == 2) {
        if (2 * A[0] == A[1]) {
            cout << 1 << endl;
            return;
        }
        cout << 2 << endl;
        return;
    }
    //N>=3
    map<ll, ll> map;
    rep(i, N)map[A[i]]++;
    ll maxcnt = 0;
    ll maxa = A[0];
    for (auto p: map) {
        if (chmax(maxcnt, p.second)) {
            maxa = p.first;
        }
    }
    if (maxcnt >= 3) {
        cout << 0 << endl;
        return;
    }
    if (maxcnt == 2) {
        rep(i, N) {
            rep(j, N) {
                if (2 * A[i] == A[j]) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
        if (maxa == A.back()) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    }
    if (maxcnt == 1) {
        rep(i, N) {
            rep(j, N) {
                if (2 * A[i] == A[j]) {
                    cout << 1 << endl;
                    return;
                }
            }
        }
        cout << 2 << endl;
    }
}

void solve_small() {
    ll ans = INFLL;
    map<ll, ll> map;
    rep(i, N)map[A[i]]++;
    rep(i,N){
        ll tmpD = D;
        //すでにできてる分を引く
        tmpD -= map[A[i]];
        if(tmpD <= 0){
            chmin(ans, 0LL);
            continue;
        }
        if(N >= D && N-1-i < D)break;
        ll X = A[i];
        ll res = 0;
        for(ll j = 1; X*bit(j) <= A.back(); j++){
            //これ以上省略しても意味がないとき
            if(tmpD < bit(j))break;
            //if(map[X*bit(j)] == 0)continue;
            ll cnt = min(map[X*bit(j)], tmpD / bit(j));
            res += (bit(j) - 1) * cnt;
            tmpD -= cnt * bit(j);
        }
        res += tmpD;
        chmin(ans, res);
    }
    cout << ans << endl;
}

void solve_large() {
    cout << 0 << endl;
}

void solve() {
    input();
    //if (D == 2)solve_d2();
    //else if (D == 3)solve_d3();
    //else
        solve_small();
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