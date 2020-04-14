#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
//typedef vector<unsigned int>vec;
typedef vector<ll>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
//const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;
    vector<double> X(N+2), V(N+2), D(N+2);
    X[0] = 0;
    cin >> V[0] >> D[0];
    REP(i,N) cin >> X[i+1] >> V[i+1] >> D[i+1];
    X[N+1] = L;
    Dijkstra<double> d(N+2, (double)LINF);
    REP(i,N+2) REP(j,N+2){
        if(X[i] >= X[j]) continue;
        if(X[j] - X[i] > D[i]) continue;
        double dist = X[j] - X[i];
        d.make_edge(i, j, dist / V[i]);
    }
    d.solve(0);
    double ans = d.cost[N+1];

    print(X);print(V);print(D);
    if(ans == LINF) cout << "impossible" << endl;
    else printf("%.12lf\n", ans);
}
