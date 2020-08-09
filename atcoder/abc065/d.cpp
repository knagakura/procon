#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
template <class T> using vec = vector<T>;

const int INF = (ll)1e9+5;

struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
    int group_num(){
        set<int> s;
        for(int i = 0; i < n; ++i){
            s.insert(root(i));
        }
        return int(s.size());
    }
};
struct Point{
    ll x, y, id;
    Point(ll x_, ll y_, ll id_):x(x_), y(y_), id(id_){};
};
struct edge{
    int x, y;
    ll cost;
    edge(ll x_, ll y_, ll cost_):x(x_), y(y_), cost(cost_){};
    bool operator < (const edge &e) const{
        return cost < e.cost;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    vector<Point> vx, vy;
    vx.emplace_back(-1, -1, -1);
    vx.emplace_back(INF, INF, -1);
    vy.emplace_back(-1, -1, -1);
    vy.emplace_back(INF, INF, -1);
    rep(i,N){
        ll x, y;
        cin >> x >> y;
        vx.emplace_back(x, y, i);
        vy.emplace_back(x, y, i);
    }
    auto x_comp = [](Point i, Point j){
        return i.x < j.x;
    };
    auto y_comp = [](Point i, Point j){
        return i.y < j.y;
    };
    sort(all(vx),x_comp);
    sort(all(vy),y_comp);
    vector<edge> Edges;
    rep1(i,N){
        auto f = vx[i];
        auto l = vx[i-1];
        auto r = vx[i+1];
        if(l.id != -1)Edges.emplace_back(f.id, l.id, abs(f.x - l.x));
        if(r.id != -1)Edges.emplace_back(f.id, r.id, abs(f.x - r.x));
    }
    rep1(i,N){
        auto f = vy[i];
        auto l = vy[i-1];
        auto r = vy[i+1];
        if(l.id != -1)Edges.emplace_back(f.id, l.id, abs(f.y - l.y));
        if(r.id != -1)Edges.emplace_back(f.id, r.id, abs(f.y - r.y));
    }
    sort(all(Edges));
    UnionFind uni(N);
    int sz = Edges.size();
    ll ans = 0;
    rep(i,sz){
        if(not uni.same(Edges[i].x, Edges[i].y)){
            ans += Edges[i].cost;
            uni.unite(Edges[i].x, Edges[i].y);
        }
    }
    cout << ans << endl;
}
