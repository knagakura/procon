#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
const ll INFLL = (ll) 1e18 + 1;
ll A[111], B[111];
ll C[111], D[111];
vector<l_l> edge1[55];
vector<l_l> edge2[55 * 2500];

vector<ll> dijkstra(ll s){
    priority_queue<l_l, vector<l_l>, greater<l_l>> pq;
    vector<ll> dist(55*2500, INFLL);
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        ll from = tmp.second;
        ll d = tmp.first;
        //if(dist[from] < d)continue;
        for(auto p: edge2[from]){
            ll to = p.first;
            ll d = p.second;
            if(dist[to] > dist[from] + d){
                dist[to] = dist[from] + d;
                pq.push(l_l(dist[to], to));
            }
        }
    }
    return dist;
}
ll f(ll v, ll s){
    return v*2500 + s;
}
int main(){
    ll n, m ,s, u, v;
    cin >> n >> m >> s;
    for(ll i = 0;i < m;i++){
        cin >> u >> v >> A[i] >> B[i];
        u--;v--;
        edge1[u].emplace_back(v, i);
        edge1[v].emplace_back(u, i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> C[i] >> D[i];
    }
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j <= 2499;j++){
            ll to = min(j + C[i], 2499ll);
            edge2[f(i,j)].emplace_back(f(i,to), D[i]);
            for(auto e: edge1[i]){
                ll to2 = e.first;
                ll edge_idx = e.second;
                if(j - A[edge_idx] < 0)continue;
                edge2[f(i,j)].emplace_back(f(to2, j-A[edge_idx]), B[edge_idx]);
            }
        }
    }
    s = min(s, 2499LL);
    auto dist = dijkstra(f(0,s));
    for(ll i = 1;i < n;i++){
        ll ans = INFLL;
        for(ll j = 0;j < 2500;j++){
            ans = min(ans, dist[f(i, j)]);
        }
        cout << ans << endl;
    }
}