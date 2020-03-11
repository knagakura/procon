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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
//const ll MOD = (ll)1e9+7;
const ll MOD = 998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
struct mint {
    long long x; // typedef long long long long;
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
};
void debug(set<pair<int, int>>& s){
    for(auto x:s){
        cerr<<x.first<<" "<<x.second<<endl;
    }
}
vector<vector<int>> G;

//v以下の部分木の答えを返す
mint dfs(int v){
    mint res = 1;
    for(auto u:  G[v]){
        res *= dfs(u);
    }
    //0で塗ったら1通り
    //1で塗ったらres通り
    return res + 1;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    G.resize(N);
    vector<pair<int, int>> XD(N);
    rep(i,N){
        cin>>XD[i].first>>XD[i].second;
    }
    sort(all(XD));
    vector<int> X(N), D(N);
    rep(i,N){
        X[i] = XD[i].first;
        D[i] = XD[i].second;
    }
    //グラフの作成
    //後ろから見て、辺を一つずつ張る
    //張ったら、setから消す
    set<pair<int,int>> s;
    //ロボットを右側から見て、右に張れるところがあるかを見る
    for(int i = N - 1; i >= 0; i--){
    //小さい順に見ていく
    while(s.size() && s.begin()->first < X[i] + D[i]){
            G[i].push_back(s.begin()->second);
            s.erase(s.begin());
        }
        //張られる対象に変わる
        s.emplace(X[i], i);
    }
    mint ans = 1;
    for(auto x: s){
        int v = x.second;
        ans *= dfs(v);
    }
    cout<< ans.x<<endl;
}