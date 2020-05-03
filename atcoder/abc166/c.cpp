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
int N, M;
vector<int> H;
vvec<int> G;
vector<bool> used;

vector<int> dfs(int cur, int pre, vector<int> &v) {
    if (used[cur])return v;
    used[cur] = true;
    v.push_back(cur);
    for (auto nv: G[cur]) {
        if (nv == pre)continue;
        dfs(nv, cur, v);
    }
    return v;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    H.resize(N);
    rep(i, N)cin >> H[i];
    G.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    used.assign(N, false);
    int ans = 0;
    /*
    rep(i, N) {
        if (used[i])continue;
        vector<int> x;
        dfs(i, -1, x);
        print(x);
        int mx = 0;
        for (auto idx: x) {
            chmax(mx, H[idx]);
        }
        int cnt = 0;
        for (auto idx: x) {
            if (mx == H[idx])cnt++;
        }
        if(cnt == 1)ans++;
    }
     */
    rep(i,N){
        if(used[i])continue;
        bool ok = true;
        for(auto nv: G[i]){
            if(H[i] < H[nv]){
                ok = false;
            }
            else if(H[i] == H[nv]){
                ok = false;
                used[nv] = true;
            }
            else{
                used[nv] = true;
            }
        }
        if(ok)ans++;
    }
    cout << ans << endl;
}