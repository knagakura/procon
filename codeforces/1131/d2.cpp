#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
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
int main(){
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    rep(i,N)cin >> a[i];
    UnionFind uni(N+M);
    rep(i,N){
        rep(j,M){
            if(a[i][j] == '='){
                uni.unite(i, N+j);
            }
        }
    }
    vvec<int> G(N+M);
    // 入次数を管理する
    vec<int> cnt(N+M,0);
    rep(i,N)rep(j,M){
        if(a[i][j] == '>'){
            G[uni.root(N+j)].push_back(uni.root(i));
            cnt[uni.root(i)]++;
        }
        if(a[i][j] == '<'){
            G[uni.root(i)].push_back(uni.root(N+j));
            cnt[uni.root(N+j)]++;
        }
    }
    vec<int> ans(N+M, -1);
    queue<int> q;
    rep(i,N+M){
        if(uni.root(i) != i)continue;
        if(cnt[i] == 0){
            q.push(i);
            ans[i] = 1;
        }
    }
    while(not q.empty()){
        int cur = q.front();
        q.pop();
        for(auto &nxt: G[cur]){
            chmax(ans[nxt], ans[cur]+1);
            cnt[nxt]--;
            if(cnt[nxt] == 0){
                q.push(nxt);
            }
        }
    }
    rep(i,N+M){
        ans[i] = ans[uni.root(i)];
    }
    bool ok = true;
    rep(i,N)rep(j,M){
        if(ans[i] == -1 || ans[N+j] == -1)ok = false;
        if(a[i][j] == '=' && ans[i] != ans[N+j])ok = false;
        if(a[i][j] == '>' && ans[i] <= ans[N+j])ok = false;
        if(a[i][j] == '<' && ans[i] >= ans[N+j])ok = false;
    }
    if(not ok){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    rep(i,N){
        cout << ans[i] << ((i == N-1) ? '\n': ' ');
    }
    rep(j,M){
        cout << ans[N+j] << ((j == M-1) ? '\n': ' ');
    }
}
