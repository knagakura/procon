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
typedef pair<l_l,ll> plli;
void Case(int t){
    cout << "Case #" << t << ": ";
}

ll ans;
set<plli> v;
bool debug;
ll cnt;
void dfs(ll l, ll r, ll idx, ll start){
    plli x = {{r, -INFLL},-1};
    while(not v.empty()){
        auto it = v.upper_bound(x);
        if(it == v.end())break;
        auto nxt = *it;
        ll nl = nxt.first.first;
        ll nr = nxt.first.second;
        ll nidx = nxt.second;
        if(idx % 2 == 0 && idx + 1 == nidx){
            it++;
            if(it == v.end())break;
            nxt = *it;
            nl = nxt.first.first;
            nr = nxt.first.second;
            nidx = nxt.second;
        }
        if(nl != r)break;
        v.erase(nxt);
        dfs(nl,nr,nidx,start);
        x = nxt;
    }
    chmax(ans, r - start);
}
void solve(int t){
    Case(t);
    ll N;
    cin >> N;
    v.clear();
    debug = t == 25;
    if(debug)cnt =0;
    for(ll i = 0; i < 2*N; i+=2){
        ll P, H;
        cin >> P >> H;
        v.insert({{P-H,P},i});
        v.insert({{P,P+H},i+1});
    }
    ans = 0;
    while(not v.empty()){
        auto x = *v.begin();
        ll l = x.first.first;
        ll r = x.first.second;
        ll idx = x.second;
        v.erase(x);
        dfs(l,r,idx,l);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    clock_t start = clock();

    int t;
    cin >> t;
    rep1(i,t+1)solve(i);

    clock_t end = clock();
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    printf("time %lf[ms]\n", time);
}