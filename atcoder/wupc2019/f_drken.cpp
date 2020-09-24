#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// edge class (for network-flow)
template<class FLOWTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};

// graph class (for network-flow)
template<class FLOWTYPE> struct Graph {
    vector<vector<Edge<FLOWTYPE> > > list;

    Graph(int n = 0) : list(n) { }
    void init(int n = 0) { list.clear(); list.resize(n); }
    void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge<FLOWTYPE> >& operator [] (int i) { return list[i]; }
    inline const size_t size() const { return list.size(); }

    inline Edge<FLOWTYPE> &redge(Edge<FLOWTYPE> e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }

    void addedge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
    }

    void add_undirected_edge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, cap));
    }

    
    // debug
    friend ostream& operator << (ostream& s, const Graph& G) {
    s << endl; for (int i = 0; i < G.size(); ++i) { s << i << " : " << G.list[i] << endl; }return s;
    }
    
};

template<class FLOWTYPE> struct Dinic {
    const FLOWTYPE INF = 1LL << 60; // to be set
    vector<int> level, iter;

    Dinic() { }
    void dibfs(Graph<FLOWTYPE> &G, int s) {
        level.assign((int)G.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); ++i) {
                Edge<FLOWTYPE> &e = G[v][i];
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    FLOWTYPE didfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge<FLOWTYPE> &e = G[v][i], &re = G.redge(e);
            if (level[v] < level[e.to] && e.cap > 0) {
                FLOWTYPE d = didfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    re.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t) {
        level.assign((int)G.size(), -1); iter.assign((int)G.size(), 0);
        FLOWTYPE res = 0;
        while (true) {
            dibfs(G, s);
            if (level[t] < 0) return res;
            for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
            FLOWTYPE flow = 0;
            while ((flow = didfs(G, s, t, INF)) > 0) {
                res += flow;
            }
        }
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<long long> c(N, -2);
    for (int i = 1; i < N - 1; ++i) cin >> c[i];
    vector<int> a(M), b(M);
    for (int i = 0; i < M; ++i) cin >> a[i] >> b[i], --a[i], --b[i];
    const long long INF = 1LL << 50;
    Graph<long long> G(N * 2 + 2);
    int s = N * 2, t = s + 1;
    // 頂点の分裂
    for (int v = 0; v < N; ++v) {
        if (c[v] > 0) {
            G.addedge(v, v + N, c[v]);
        }
    }
    // スーパーノード
    for (int v = 0; v < N; ++v) {
        if (c[v] == -1) {
            G.addedge(s, v, INF);
            G.addedge(v + N, t, INF);
        }
    }
    // グラフの形そのものを作る
    for (int i = 0; i < M; ++i) {
        int from = a[i] + N, to = b[i];
        if (c[a[i]] == -1) from = a[i];
        if (c[b[i]] == -1) to = b[i] + N;
        G.addedge(from, to, INF);
    }
    Dinic<long long> din;
    long long res = din.solve(G, s, t);
    cout << (res < INF ? res : -1) << endl;
}