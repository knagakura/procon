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
typedef pair<l_l,int> plli;
void Case(int t){
    cout << "Case #" << t << ": ";
}

ll ans;
// vector<plli> v;
set<plli> v;
vector<bool> visited;
bool debug;
void dfs(ll l, ll r, ll idx, ll start){
    if(visited[idx])return;
    // cerr << l << " " << r << " " << idx << " " << start << endl;
    visited[idx] = true;
    // にぶたんの左右
    plli x = {{r, -INFLL},-1};
    plli y = {{r, INFLL},INF};
    // int a = lower_bound(all(v), x) - v.begin();
    // int b = upper_bound(all(v), y) - v.begin();
    // for(int ni = a; ni < b; ni++){
    //     ll nl = v[ni].first.first;
    //     ll nr = v[ni].first.second;
    //     ll nidx = v[ni].second;
    //     if(visited[nidx])continue;
    //     if(idx % 2 == 0 && idx + 1 == nidx)continue; // 同じ木
    //     dfs(nl, nr, nidx, start);
    // }
    if(v.empty()){
        chmax(ans, r - start);
        return;
    }
    // auto it = v.lower_bound(x);
    // for(auto a = it; a != v.end(); a++){
    //     auto nxt = *a;
    //     print(v);
    //     dump(nxt);
    //     ll nl = nxt.first.first;
    //     ll nr = nxt.first.second;
    //     ll nidx = nxt.second;
    //     if(nl != r)break;
    //     if(idx % 2 == 0 && idx + 1 == nidx)continue;
    //     cerr << nxt << "を削除しました" << endl;
    //     v.erase(a);
    //     dfs(nl,nr,nidx,start);
    // }
    while(not v.empty()){
        auto nxt = *v.lower_bound(x);
        ll nl = nxt.first.first;
        ll nr = nxt.first.second;
        ll nidx = nxt.second;
        if(nl != r)break;
        if(idx % 2 == 0 && idx + 1 == nidx){
            nxt.first.second++;
            x = nxt;
            continue;
        }
        v.erase(nxt);
        // dump(nxt);
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
    for(ll i = 0; i < 2*N; i+=2){
        ll P, H;
        cin >> P >> H;
        // v.push_back({{P-H,P},i});
        // v.push_back({{P,P+H},i+1});
        v.insert({{P-H,P},i});
        v.insert({{P,P+H},i+1});
    }
    // sort(all(v));
    visited.assign(2*N,false);
    // ans = 0;
    // rep(i,2*N){
    //     ll l = v[i].first.first;
    //     ll r = v[i].first.second;
    //     ll idx = v[i].second;
    //     if(visited[idx])continue;
    //     dfs(l,r,idx,l);
    // }
    while(not v.empty()){
        auto x = *v.begin();
        ll l = x.first.first;
        ll r = x.first.second;
        ll idx = x.second;
        if(visited[idx])continue;
        v.erase(x);
        dfs(l,r,idx,l);
    }
    cout << ans << endl << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    rep1(i,t+1)solve(i);
}