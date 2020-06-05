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
typedef pair <ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair <T1, T2> &p) {
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

struct pnt {
    ll x;
    ll p;
    ll type;
    ll id;

    pnt(ll x_, ll p_, ll type_, ll id_) {
        x = x_;
        p = p_;
        type = type_;
        id = id_;
    }

    bool operator<(const pnt &b) const {
        return x < b.x;
    }

    friend std::ostream &operator<<(std::ostream &os, const pnt &a) {
        os << "{" << a.x << "," << a.p << "," << a.type << "}";
        return os;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, W, C;
    cin >> N >> W >> C;
    vec<pnt> v;
    v.emplace_back(0, 0, 1, -1);
    rep(i, N) {
        int l, r, p;
        cin >> l >> r >> p;
        v.emplace_back(l, p, 0, i);
        v.emplace_back(r, p, 1, i);
    }
    v.emplace_back(W, 0, 0, -1);
    sort(all(v));
    ll sz = v.size();
    ll r = 1;
    ll len;
    ll cost = 0;
    ll ans = INFLL;
    vec<bool> used(N, false);
    for (ll l = 0; l < sz; l++) {
        if (v[l].type == 1 && v[l].id >= 0)cost -= v[l].p;
        len = v[r].x - v[l].x;
        while (r + 1 < sz && len < C) {
            if (v[r - 1].type == 0 && v[r - 1].id >= 0 && not used[v[r-1].id]) {
                cost += v[r - 1].p;
                used[v[r-1].id] = true;
            }
            len += v[r + 1].x - v[r].x;
            r++;
        }
        if (v[r - 1].type == 0 && v[r - 1].id >= 0 && not used[v[r-1].id]) {
            cost += v[r - 1].p;
            used[v[r-1].id] = true;
        }
        if (len >= C)chmin(ans, cost);
    }
    cout << ans << endl;
}