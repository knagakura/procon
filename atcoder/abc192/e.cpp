#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<stack>
#include<unordered_map>
#include<bitset>
#include<limits>
#include<complex>
#include<array>
#include<numeric>
#include<functional>
#include<random>


using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,m,n) for(ll (i)=(ll)(m);i<(ll)(n);i++)
#define REP(i,n) rep(i,0,n)
#define all(hoge) (hoge).begin(),(hoge).end()
#define llsize(c) ((ll)c.size())
typedef pair<ll, ll> P;


constexpr long double m_pi = 3.1415926535897932L;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 61;
constexpr long double EPS = 1e-10;
template<typename T> using vector2 = vector<vector<T>>;
template<typename T> using vector3 = vector<vector2<T>>;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
string operator*(const string& s, int k) {
	if (k == 0) return "";
	string p = (s + s) * (k / 2);
	if (k % 2 == 1) p += s;
	return p;
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }

struct Edge {//グラフ
	int to;
    ll w;
    ll k;
	Edge(int _to, ll _w, ll _k) {
		to = _to; w = _w; k = _k;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
void add_edge(Graph& G, int from, int to, ll w, ll k) {
	G[from].push_back(Edge(to, w, k));
}

Array Dijkstra(Graph& g, ll s) {//O(|E|log|V|)
	Array ret(g.size(), INF);
	ret[s] = 0;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ ret[s], s });
	while (!q.empty()) {
		auto [d, v] = q.top();
		q.pop();
		if (ret[v] < d)continue;
		for (auto e : g[v]) {
            ll nret = ret[v] + e.w + (e.k - (ret[v]%e.k)) % e.k;
			if (chmin(ret[e.to], nret)){
                q.push({ ret[e.to], e.to });
            }
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

    int N, M;
    cin >> N >> M;
    int S, G;
    cin >> S >> G;
    S--, G--;
    Graph g(N);
    for(int i = 0; i < M; i++){
        int a, b;
        ll t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        add_edge(g, a, b, t, k);
        add_edge(g, b, a, t, k);
    }
    auto v = Dijkstra(g, S);
    if(v[G] == INF){
        cout << -1 << endl;
    }
    else{
        cout << v[G] << endl;
    }
	return 0;
}