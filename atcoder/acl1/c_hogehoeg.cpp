#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <utility>
#include <fstream>

using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { a = abs(a), b = abs(b); while (b > 0) { tie(a, b) = make_pair(b, a % b); } return a; }
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
//constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353;
constexpr int MAX = 5000000;


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

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    auto f = [&](int h, int w)->int {
		return h * W + w;
	};
    PrimalDual g(H * W + 2);
    int s = H * W;
    int t = H * W + 1;
    int cnt = 0;
    rep(i,H)rep(j,W){
        if(S[i][j] == '#')continue;
        if(S[i][j] == 'o'){
            cnt++;
            g.add_edge(s, f(i, j), 1, (i + j));
        }
        if(i + 1 < H and S[i + 1][j] != '#'){
            g.add_edge(f(i, j), f(i + 1, j), inf, 0);
        }
        if (j + 1 < W and S[i][j + 1] != '#') {
            g.add_edge(f(i, j), f(i, j + 1), inf, 0);
        }
        g.add_edge(f(i, j), t, 1, -(i + j));
    }
    ll res = -g.min_cost_flow(s, t, cnt);
    cout << res << endl;
}
