#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

// ベルマンフォード法
template<class T> class Graph {
public:
    struct edge{int from; int to; T cost; int id;};
    int V; // number of vertex
    int E = 0; // after add, ++;
    int inf = 100010001;
    vector<T> d; //distance
    vector<edge> edges;
    Graph(int _V): V(_V){
        d = vector<T>(V, inf);
    };
    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        edges.push_back({from, to, cost, id});
        E++;
    }
    void shortest_path(int s){
        for(int i = 0; i < V; i++) d[i] = inf;
        d[s] = 0;
        while(true){
            bool update = false;
            for(int i = 0; i < E; i++){
                edge e = edges[i];
                if(d[e.from] != inf && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    update = true;
                }
            }
            if(!update) break;
        }
    }
    bool find_negative_loop(){
        for(int i = 0; i < V; i++) d[i] = 0;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < E; j++){
                edge e = edges[j];
                if(d[e.to] > d[e.from] + e.cost){
                    d[e.to] = d[e.from] + e.cost;
                }
                // V回目にも更新があるなら、負の閉路が存在する
                if(i == V - 1) return true;
            }
        }
        return false;
    }

};
ll V,E,P;
vec<ll> A,B,C;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    cin >> V >> E >> P;
    Graph<ll> G(V);
    A.resize(E);B.resize(E);C.resize(E);
    rep(i,E){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;B[i]--;
        cerr << A[i] << B[i] << C[i] << endl;
        G.add_Directed_edge(A[i], B[i], C[i]-P, i);
    }
}

/*
一回移動するごとに所持金がP減ることを最後にするのではなく、
毎回の移動でやることにすれば、考えることが減る
最大値が存在しない、つまり無限大を実現できるのは、
コストの合計が正となる閉路が存在する時である。
つまり、そこをグルグルするだけで無限にお金を増やすことができるのである。

一方そのような閉路が存在しない場合は、最後のお金を最大化することがベストになる。
寄り道して回ることがメリットにならないからである。
最後の所持金は負にはならないので注意したい。途中のコストの合計がマイナスになることを許せば、
距離の最大か問題としてダイクストラ法で解ける
*/
