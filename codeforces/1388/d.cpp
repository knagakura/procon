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
vvec<ll> G;
void solve(){
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i,N)cin >> a[i];
    rep(i,N){
        cin >> b[i];
        if(b[i] > 0)b[i]--;
    }
    G.resize(N);
    vector<ll> used(N,false);
    deque<ll> v;
    vector<int> cnt(N,0);// 入次数
    ll ans = 0;
    rep(i,N){
        if(b[i] == -1)continue;
        if(a[i] > 0){
            G[i].emplace_back(b[i]);
            cnt[b[i]]++;
        }
    }
    // Gをトポロジカルソート
    queue<int> q;
    rep(i,N){
        if(a[i] < 0)continue;
        if(cnt[i] == 0)q.push(i);
    }
    while(not q.empty()){
        int cur = q.front();
        q.pop();
        if(a[cur] < 0)continue;
        ans += a[cur];
        used[cur] = true;
        v.push_back(cur);
        for(auto nxt: G[cur]){
            a[nxt] += a[cur];
            cnt[nxt]--;
            if(cnt[nxt] == 0)q.push(nxt);
        }
    }
    rep(i,N){
        if(not used[i]){
            v.push_back(i);
            ans += a[i];
        }
    }
    cout << ans << endl;
    rep(i,N)cout << v[i]+1 << " ";
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t = 1;
    while(t--)solve();
}
