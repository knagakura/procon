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

template<typename T = int>
struct edge{
    int to;
    T cost;
    int id;
    edge(int _to, T _cost = 1, int _id = -1) :to(_to), cost(_cost), id(_id) {}
};

ll N, S;
int root = 0;
vvec<edge<ll>> G;
vec<ll> val; // 辺が何回葉に寄与しているか
vec<ll> sum; // 葉までのpathの和
vvec<int> leafs;
ll dfs1(int cur = 0, int pre = -1){
    if(cur != root && G[cur].size() == 1)return 1;
    ll res = 0;
    for(edge p: G[cur]){
        if(p.to == pre)continue;
        ll ress = dfs1(p.to, cur);
        val[p.id] = ress;
        res += ress;
    }
    return res;
}

void dfs2(int cur = 0, int pre = -1, ll summ = 0){
    if(cur != root && G[cur].size() == 1)sum[cur] = summ;
    ll res = summ;
    for(edge p: G[cur]){
        if(p.to == pre)continue;
        dfs2(p.to, cur, res + p.cost);
    }
}
// vector<int> dfs3(int cur = 0, int pre = -1){
//     if(cur != root && G[cur].size() == 1){
//         vector<int> v(1,cur);
//         return v;
//     }
//     vector<int> res;
//     for(edge p: G[cur]){
//         if(p.to == pre)continue;
//         auto tmp = dfs3(p.to, cur);
//         for(auto tmp)
//     }
// }
void solve(){
    G.clear();
    leafs.clear();
    cin >> N >> S;
    G.resize(N);
    val.resize(N-1);
    sum.assign(N,0);
    // leafs.resize(N-1); //ある辺が寄与する葉のリスト
    vector<ll> w(N-1), c(N-1);
    rep(i,N-1){
        int f,t;
        cin >> f >> t >> w[i] >> c[i];
        f--,t--;
        G[f].emplace_back(t,w[i],i);
        G[t].emplace_back(f,w[i],i);
    }
    //
    dfs1();
    // print(val); // 辺の寄与回数, edge.idと繋がる
    dfs2();
    // print(sum); // 葉（頂点までのpathの和)
    priority_queue<pair<ll,l_l>> pq1,pq2;
    rep(i,N-1){
        if(c[i] == 1)pq1.push({(w[i]-w[i]/2) * val[i],{w[i],val[i]}});
        if(c[i] == 2)pq2.push({(w[i]-w[i]/2) * val[i],{w[i],val[i]}});
    }
    ll all_sum = accumulate(all(sum),0LL);
    // calc: pq?
    ll ans = 0;
    while(all_sum > S){
        // dump(all_sum);
        // if(all_sum <= S)break;
        ll all_sums[2] = {all_sum, all_sum};
        // 1から2回やる
        priority_queue<pair<ll,l_l>> tmppq1,tmppq2;
        {
            if(not pq1.empty()){
                tmppq1 = pq1;
                rep(i,2){
                    auto p = tmppq1.top();
                    tmppq1.pop();
                    ll ww = p.second.first;
                    ll cntt = p.second.second;
                    ll nww = ww/2;
                    ll sub = ww - nww;
                    all_sums[0] -= sub * cntt;
                    if(all_sums[0] <= S){
                        ans+=i+1;
                        cout << ans << endl;
                        return;
                    }
                    pair<ll,l_l> np = {(nww-nww/2) * cntt, {nww, cntt}};
                    tmppq1.push(np);
                }
            }
        }
        // 2から1回やる
        {
            if(not pq2.empty()){
                tmppq2 = pq2;
                auto p = tmppq2.top();
                tmppq2.pop();
                ll ww = p.second.first;
                ll cntt = p.second.second;
                ll nww = ww/2;
                ll sub = ww - nww;
                all_sums[1] -= sub * cntt;
                pair<ll,l_l> np = {(nww-nww/2) * cntt, {nww, cntt}};
                tmppq2.push(np);
            }
        }
        if(all_sums[0] < all_sums[1])pq1 = tmppq1;
        else pq2 = tmppq2;
        all_sum = min(all_sums[0],all_sums[1]);
        ans += 2;
    }
    cout << ans << endl;

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}
