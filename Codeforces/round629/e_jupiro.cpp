#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int inf = 1 << 28;
constexpr long long mod = 1000000007LL;
//constexpr long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n;
vector<int> g[200005];
vector<int> dep;

struct LCA {
	static const int BITLEN_MAX = 20;
	vector<int> parent[BITLEN_MAX];
	vector<int> depth;
	int bitlen;

	LCA() {}
	LCA(int N, const vector<int> edges[]) { initialize(N, edges); }
	void initialize(int N, const vector<int> edges[]) {
		int root = 0;
		bitlen = 1;
		while ((1 << bitlen) < N) bitlen += 1;
		for (int i = 0; i < bitlen; i++) parent[i].resize(N);
		depth.resize(N, -1);

		dfs(root, -1, 0, edges);
		for (int k = 0; k < bitlen - 1; k++) {
			for (int v = 0; v < N; v++) {
				if (depth[v] == -1) continue;
				if (parent[k][v] < 0) {
					parent[k + 1][v] = -1;
				}
				else {
					parent[k + 1][v] = parent[k][parent[k][v]];
				}
			}
		}
	}

	void dfs(int v, int p, int d, const vector<int> edges[]) {
		parent[0][v] = p;
		depth[v] = d;
		for (auto u : edges[v]) {
			if (u != p) dfs(u, v, d + 1, edges);
		}
	}

	int calc_lca(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < bitlen; k++) {
			if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
		}
		if (u == v) return u;
		for (int k = bitlen - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}

	int calc_dist(int u, int v) {
		int l = calc_lca(u, v);
		return depth[u] + depth[v] - depth[l] * 2;
	}
};

LCA lca;

void dfs1(int cur, int pre) {
	for (auto next : g[cur]) {
		if (next == pre) continue;
		dep[next] = dep[cur] + 1;
		dfs1(next, cur);
	}
}


int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	int kkt; scanf("%d %d", &n, &kkt);
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep = vector<int>(n);
	dfs1(0, -1);
	lca.initialize(n, g);
	while (kkt--) {
		int jupi; scanf("%d", &jupi);
		vector<int> v(jupi);
		int mx = -1;
		int idx = -1;
		for (int i = 0; i < jupi; i++) {
			scanf("%d", &v[i]);
			v[i]--;
			if(chmax(mx, dep[v[i]])) idx = v[i];
		}
		bool flag = true;
		for (int i = 0; i < jupi; i++) {
			int lc = lca.calc_lca(idx, v[i]);
			if (lc == v[i]) continue;
			if (lca.calc_dist(v[i], lc) > 1) flag = false;
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;

}