#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
template<class T> class Graph {
public:
    struct edge{int to; T cost; int id;};
    int N;
    vector<vector<edge>> G;
    vector<vector<T>> d;//distance matrix
    Graph(int _N): N(_N){
        G = vector<vector<edge>>(_N, vector<edge>(0));
        //d = vector<vector<long long>>(N, vector<long long>(N));
        d.resize(_N,vector<T>(_N));
    }
    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }
    void WarshallFloyd(){
        //initialize the distance matrix
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; j++){
                d[i][j] = ((i == j) ? 0: INFLL);
            }
        }
        for(int i = 0; i < N; ++i){
            for(auto e: G[i]){
                d[i][e.to] = e.cost;
            }
        }
        //WarshallFloyd
        for(int k = 0; k < N; ++k){
            for(int i = 0; i < N; ++i){
                for(int j = 0; j < N; ++j){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    void debug(){
        for(int i = 0; i < N; ++i){
            cerr<<i+1<<": ";
            for(edge e:G[i]){
                cerr<<"{"<<e.to+1<<", "<<e.cost<<"}, ";
            }
            cerr<<endl<<endl;
        }
        cerr<<"distance_matrix"<<endl;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(d[i][j] == INFLL){
                    cerr<<-1<<" ";
                }else cerr<<d[i][j]<<" ";
            }
            cerr<<endl;
        }
    }
};
/*------------------------------------*/
int c[100][100];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int H,W;
    cin>>H>>W;
    Graph<ll> G(10);
    rep(i,10)rep(j,10){
        cin>>c[i][j];
        G.add_Directed_edge(i,j,c[i][j]);
    }
    G.WarshallFloyd();
    ll ans = 0;
    rep(i,H)rep(j,W){
        int a;
        cin>>a;
        if(a>=0){
            ans += G.d[a][1];
        }
    }
    cout<<ans<<endl;
}