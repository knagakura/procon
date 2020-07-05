#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define uniq(x) x.erase(unique(all(x)),x.end())
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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

ll N, M;
vvec<int> G;
vec<ll> v;
vec<bool> visited;
vec<int> cnt;
bool dfs(int cur, int pre = -1, ll cnt = 1){
    //visited[cur] = true;
    chmax(v[cur],cnt);
    bool ng = false;
    for(auto &nxt: G[cur]){
        // ループ
        if(visited[nxt]){
            ng = true;
            return true;
        }
        //visited[cur] = true;
        ng |= dfs(nxt, cur, v[cur]+1);
    }
    return ng;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    vector<string> a(N);
    rep(i,N){
        cin >> a[i];
    }
    UnionFind uni(N+M);
    rep(i,N)rep(j,M){
        if(a[i][j] == '='){
            uni.unite(i, N + j);
        }
    }
    G.resize(N+M);
    v.assign(N+M,-1);
    cnt.assign(N+M, 0);
    rep(i,N)rep(j,M){
        if(a[i][j] == '=')continue;
        if(a[i][j] == '>'){
            G[uni.root(N+j)].push_back(uni.root(i));
        }
        if(a[i][j] == '<'){
            G[uni.root(i)].push_back(uni.root(N+j));
        }
    }
    bool ok = true;
    rep(i,N+M){
        //if(G[i].empty())continue;
        visited.assign(N+M, false);
        if(dfs(i)){
            //dump(i);
            ok = false;
        }
    }
    if(!ok){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i,N){
        cout << v[uni.root(i)] << " ";
    }
    cout << endl;
    rep(j,M){
        cout << v[uni.root(N+j)] <<  " ";
    }
    cout << endl;
}
