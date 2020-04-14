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
    bool longest = false;
    T inf = 100010001;
    vector<T> d; //distance
    vector<edge> edges;
    Graph(int _V, bool _long = false): V(_V),longest(_long){
        d = vector<T>(V);
    };
    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        edges.push_back({from, to, cost, id});
        E++;
    }
    bool shortest_path(int s){
        if(longest){
            cerr << "longest_path is good" <<endl;
            return false;
        }
        for(int i = 0; i < V; i++) d[i] = inf;
        d[s] = 0;
        int cnt = 0;
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
            cnt++;
            if(cnt == V - 1 && update){
                return true;
            }
        }
        return false;
    }
    bool find_negative_loop_from_s(int s){
        return shortest_path(s);
    }
    // 始点によらないloop
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
    //
    bool longest_path(int s){
        if(!longest){
            cerr << "shortest path is good" <<endl;
            return false;
        }
        for(int i = 0; i < V; i++) d[i] = -inf;
        d[s] = 0;
        int cnt = 0;
        ll tmp = 0;
        ll loop_limit = 2 * V;
        while(loop_limit--){
            //print(d);
            bool update = false;
            for(int i = 0; i < E; i++){
                edge e = edges[i];
                if(d[e.from] != -inf && d[e.to] < d[e.from] + e.cost) {
                    //cerr <<e.from << " " << e.to << endl;
                    //cerr <<d[e.to] << " -> " << d[e.from] + e.cost <<endl;
                    d[e.to] = d[e.from] + e.cost;
                    update = true;
                }
            }
            cnt++;
            //dump(cnt);
            if(!update) break;
            if(cnt == V-1){
                //止まるはずだったところで止めておく
                tmp = d[V-1];
                //更新が起きるなら、閉路があることは確認される
                if(update){
                    continue;
                }
                else{
                    return false;
                }
            }
            if(loop_limit < V){
                if(tmp != d[V-1]){
                    return true;
                }
            }
        }
        return false;
    }
    //始点s
    bool find_positive_loop_from_s(int s){
        return longest_path(s);
    }
    //始点によらない
    bool find_positive_loop(){
        for(int i = 0; i < V; i++) d[i] = 0;
        for(int i = 0; i < V; i++){
            for(int j = 0; j < E; j++){
                edge e = edges[j];
                if(d[e.to] < d[e.from] + e.cost){
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
vector<ll> A,B,C;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> V >> E >> P;
    Graph<ll> G(V, true);
    A.resize(E);B.resize(E);C.resize(E);
    rep(i,E){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;B[i]--;
        G.add_Directed_edge(A[i], B[i], C[i]-P, i);
    }＾
        cout << -1 << endl;
        return 0;
    }
    else{
        cout << max(0LL, G.d[V-1]) << endl;
    }
}
