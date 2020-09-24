#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";


struct PrimalDual {
	struct edge {
		int to;
		ll cap;
		ll cost;
		int rev;
		bool isrev;

		edge(int _to, ll _cap, ll _cost, int _rev, bool _isrev) :to(_to), cap(_cap), cost(_cost), rev(_rev), isrev(_isrev) {}

	};
	vector<vector<edge>> graph;
	vector<ll> potential, min_cost;
	vector<int> prevv, preve;
	PrimalDual(int V) :graph(V) {}

	void add_edge(int from, int to, ll cap, ll cost) {
		graph[from].emplace_back(to, cap, cost, graph[to].size(), false);
		graph[to].emplace_back(from, 0, -cost, graph[from].size() - 1, true);
	}

	ll min_cost_flow(int s, int t, ll f) {
		int V = graph.size();
		ll res = 0;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
		potential.assign(V, 0);
		preve.assign(V, -1);
		prevv.assign(V, -1);

		while (f > 0) {
			min_cost.assign(V, INF);
			pq.emplace(0, s);
			min_cost[s] = 0;
			while (!pq.empty()) {
				auto cur = pq.top();
				pq.pop();
				if (min_cost[cur.second] < cur.first) continue;
				for (int i = 0; i < graph[cur.second].size(); i++) {
					edge& e = graph[cur.second][i];
					ll nextCost = min_cost[cur.second] + e.cost + potential[cur.second] - potential[e.to];
					if (e.cap > 0 and min_cost[e.to] > nextCost) {
						min_cost[e.to] = nextCost;
						prevv[e.to] = cur.second;
						preve[e.to] = i;
						pq.emplace(min_cost[e.to], e.to);
					}

				}
			}
			if (min_cost[t] == INF) return -1;
			for (int v = 0; v < V; v++) potential[v] += min_cost[v];
			ll add_flow = f;
			for (int v = t; v != s; v = prevv[v]) {
				chmin(add_flow, graph[prevv[v]][preve[v]].cap);
			}
			f -= add_flow;
			res += add_flow * potential[t];
			for (int v = t; v != s; v = prevv[v]) {
				edge& e = graph[prevv[v]][preve[v]];
				e.cap -= add_flow;
				graph[v][e.rev].cap += add_flow;
			}
		}
		return res;
	}
};
const ll inf = 1LL << 30;
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    auto f = [&](int h, int w)->int {
		return h * W + w;
	};
    // PrimalDual g(H * W + 2);
    atcoder::mcf_graph<ll,ll> G(H*W+2);
    int s = H * W;
    int t = H * W + 1;
    int cnt = 0;
    rep(i,H)rep(j,W){
        if(S[i][j] == '#')continue;
        if(S[i][j] == 'o'){
            cnt++;
            // g.add_edge(s, f(i, j), 1, (i + j));
            G.add_edge(s, f(i, j), 1, (i + j));
        }
        if(i + 1 < H and S[i + 1][j] != '#'){
            // g.add_edge(f(i, j), f(i + 1, j), inf, 0);
            G.add_edge(f(i, j), f(i + 1, j), inf, 0);
        }
        if (j + 1 < W and S[i][j + 1] != '#') {
            // g.add_edge(f(i, j), f(i, j + 1), inf, 0);
            G.add_edge(f(i, j), f(i, j + 1), inf, 0);
        }
        // g.add_edge(f(i, j), t, 1, -(i + j));
        G.add_edge(f(i, j), t, 1, inf-(i + j));
    }
    // ll res = -g.min_cost_flow(s, t, cnt);
    auto [p, q] = G.flow(s, t, cnt);
    ll res = cnt * inf - q;
    cout << res << endl;
}
