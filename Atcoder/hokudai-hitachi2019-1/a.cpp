#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int V,E;
int Tmax;
vector<vector<pair<int, int>>> Graph;
vector<vector<pair<int, int>>> info;
//point:時刻iにいる場所
vector<int> command,point;
void INIT(){
    //入力
    cin>>V>>E;
    Graph.resize(V);
    rep(_, E){
        int u,v,d;
        cin>>u>>v>>d;
        u--;v--;
        Graph[u].push_back({v,d});
        Graph[v].push_back({u,d});
    }
    cin>>Tmax;
    info.resize(Tmax);
    rep(i, Tmax){
        int N_new;
        cin>>N_new;
        rep(_, N_new){
            int new_id, dst;
            cin>>new_id>>dst;
            info[i].push_back({new_id,dst});
        }
    }
    //commandの初期化
    command.resize(Tmax);
    rep(i,Tmax)command[i] = -1;
    point.resize(Tmax+1);
    point[0] = 0;
    rep1(i,Tmax+1){
        point[i] = 0;
    }
}

int RandomWalk(int v){
    mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<int> dist(0, Graph[v].size()-1);
    return Graph[v][dist(mt)].first + 1;
}

void Simulation(){
    rep(i,Tmax){
        command[i] = RandomWalk(point[i]);
        point[i+1] = command[i]-1;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    INIT();
    Simulation();
    rep(i,Tmax){
        cout<<command[i]<<'\n';
    }
    /*
    print(command);
    print(point);
    */
}