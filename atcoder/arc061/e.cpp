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

ll N, M;
int p, q;
vector<ll> c;
vvec<l_l> G;


struct UnionFind {
    int n;
    vector<int> Parent;
    vector<int> sizes;

    UnionFind(int _n) : n(_n), Parent(_n), sizes(_n, 1) { rep(i, n)Parent[i] = i; }

    //find the root of x
    int root(int x) {
        if (x != Parent[x]) {
            Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }

    //merge x and y
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(int x, int y) { return root(x) == root(y); }

    int size(int x) { return sizes[root(x)]; }

    int group_num() {
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(root(i));
        }
        return int(s.size());
    }
};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    G.resize(N);
    c.resize(M);
    //vector<UnionFind> uni(1e6+1, UnionFind(N));
    for (int i = 0; i < M; ++i) {
        cin >> p >> q >> c[i];
        p--, q--;
        //uni[c[i]].unite(p, q);
        G[p].push_back({q, i});
        G[q].push_back({p, i});
    }
    /*
    for(int i = 0; i <= 1e6; i++){
        if(uni[i].same(0, N-1)){
            cout << 1 << endl;
            return 0;
        }
    }*/
    ll ans[2] = {};
    rep(j, 2) {
        vector<ll> dist(N, INFLL);
        priority_queue<pair<ll, l_l>,
                vector<pair<ll, l_l>>,
                greater<> > pq;
        ll s = (j ? N - 1 : 0);
        ll g = (j ? 0 : N - 1);
        dist[s] = 0;
        pq.push({dist[s], {s, -1}});
        while (!pq.empty()) {
            auto tmp = pq.top();
            //dump(tmp);
            pq.pop();
            ll d = tmp.first;
            ll from = tmp.second.first;
            ll pre_c = tmp.second.second;
            //if (d > dist[from])continue;
            for (auto e: G[from]) {
                int to = e.first;
                int edge_idx = e.second;
                int cost = 0;
                if (c[edge_idx] != pre_c)cost++;
                if (dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                    //cerr << from << " " << to << " " << dist[to] << endl;
                    pq.push({dist[to], {to, c[edge_idx]}});
                }
            }
        }
        ans[j] = ((dist[g] == INFLL) ? -1 : dist[g]);
    }
    cout << min(ans[0], ans[1]) << endl;
}