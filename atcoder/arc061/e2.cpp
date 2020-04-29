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

    int N, M;
    cin >> N >> M;
    vector<int> p(M), q(M), c(M);
    //頂点を拡張する
    //(i, c)を1頂点とみなす
    //(i, -1)を改札としてみる
    vector<l_l> vrx;
    for (int i = 0; i < N; ++i) vrx.emplace_back(i, -1);
    for (int i = 0; i < M; ++i) {
        cin >> p[i] >> q[i] >> c[i];
        p[i]--, q[i]--;
        vrx.emplace_back(p[i], c[i]);
        vrx.emplace_back(q[i], c[i]);
    }
    // 頂点にidxをつける
    //頂点からidxを復元できるようにする
    sort(all(vrx));
    vrx.erase(unique(vrx.begin(), vrx.end()), vrx.end());
    int sz = vrx.size();
    map<l_l, int> p2i;
    for (int i = 0; i < sz; ++i) p2i[vrx[i]] = i;

    //この拡張されたグラフ上に辺を貼っていく
    //駅内の辺
    vvec<l_l> G(sz);
    for (int i = 0; i < sz; ++i) {
        if (vrx[i].second == -1) continue;
        int home = p2i[vrx[i]];
        int cent = p2i[{vrx[i].first, -1}];
        G[home].emplace_back(cent, 0);
        G[cent].emplace_back(home, 1);
    }
    //駅間の辺
    for (int i = 0; i < M; ++i) {
        l_l v1 = {p[i], c[i]};
        l_l v2 = {q[i], c[i]};
        G[p2i[v1]].emplace_back(p2i[v2], 0);
        G[p2i[v2]].emplace_back(p2i[v1], 0);
    }
    vector<ll> dist(sz, INFLL);
    ll s_idx = p2i[{0, -1}];
    ll g_idx = p2i[{N - 1, -1}];
    dist[s_idx] = 0;
    priority_queue<l_l, vector<l_l>, greater<>> pq;
    pq.push({0, s_idx});

    // calc
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        ll d = tmp.first;
        ll from = tmp.second;
        for (auto e: G[from]) {
            int to = e.first;
            int cost = e.second;
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    cout << ((dist[g_idx] == INFLL) ? -1 : dist[g_idx]) << endl;
}
