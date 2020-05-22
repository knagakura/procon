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

struct mint {
    long long x;
    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint modpow(long long t) const {
        if (!t) return 1;
        mint a = modpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return modpow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};
int N,M;
int s,g;
vvec<int> G;
vvec<int> G2;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    cin >> s >> g;
    s--;g--;
    cin >> M;
    G.resize(N);
    G2.resize(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> q;
    vec<int> d(N,-1);
    q.push(s);
    d[s] = 0;
    while(not q.empty()){
        int v = q.front();
        q.pop();
        for(int &nv: G[v]){
            if(d[nv] == -1){
                G2[nv].push_back(v);
                d[nv] = d[v] + 1;
                q.push(nv);
            }
            else{
                if(d[v]+1 == d[nv]){
                    G2[nv].push_back(v);
                }
            }
        }
    }
    vec<mint> ans(N, 0);
    vec<bool> visited(N,false);
    queue<int> q2;
    ans[g] = 1;
    visited[g] = true;
    q2.push(g);
    /*calc*/
    while(not q2.empty()){
        int v = q2.front();
        q2.pop();
        for(int &nv: G2[v]){
            ans[nv] += ans[v];
            if(!visited[nv])q2.push(nv);
            visited[nv] = true;
        }
    }
    cout << ans[s] << endl;
    /*
    rep(i,N)print(G[i]);
    rep(i,N)print(G2[i]);
    print(ans);
    */
}