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
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M, S;
    cin >> N >> M >> S;
    vector<ll> u(M), v(M), a(M), b(M);
    vector<ll> c(N), d(N);
    vvec<l_l> g(N);
    for (int i = 0; i < M; ++i) {
        cin >> u[i] >> v[i] >> a[i] >> b[i];
        u[i]--, v[i]--;
        g[u[i]].push_back({v[i], i});
        g[v[i]].push_back({u[i], i});
    }
    for (int i = 0; i < N; ++i) {
        cin >> c[i] >> d[i];
    }
    //(i, j): index iの頂点に jだけお金を持って移動する最小値
    auto p2i = [](ll x, ll y) -> ll {
        return 4000 * x + y;
    };
    vvec<l_l> G(55 * 4000);
    //頂点i内で両替するときの辺を張る
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3000; j++) {
            int to = j + c[i];
            if (to > 3000)continue;
            G[p2i(i, j)].push_back({p2i(i, to), d[i]});
        }
    }
    //頂点間の移動を考える。
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3000; ++j) {
            for (auto e: g[i]) {
                int to = e.first;
                int edge_idx = e.second;
                if (j < a[edge_idx])continue;
                G[p2i(i, j)].push_back({p2i(to, j - a[edge_idx]), b[edge_idx]});
            }
        }
    }
    vector<ll> dist(55 * 4000, INFLL);
    S = min(S, 2999LL);
    dump(S);
    dist[p2i(0, S)] = 0;
    priority_queue<l_l,
            vector<l_l>,
            greater<>> pq;
    pq.push({0, p2i(0, S)});
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        int from  = tmp.second;
        ll d_ = tmp.first;
        //if(d_ > dist[from])continue;
        for(auto e: G[from]){
            int to = e.first;
            ll cost = e.second;
            if(dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    for(int i = 1; i < N; i++){
        ll ans = INFLL;
        for (int j = 0; j < 3000; ++j) {
            chmin(ans, dist[p2i(i, j)]);
        }
        cout << ans << endl;
    }
}