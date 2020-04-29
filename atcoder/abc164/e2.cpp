#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
const ll INFLL = (ll) 1e18 + 1;
struct edge{
    ll to;
    ll a;
    ll b;
};
vector<ll> A,B,C,D;
vector<vector<edge>> edge1,edge2;

vector<ll> dijkstra(ll s){
    priority_queue<l_l, vector<l_l>, greater<l_l>> pq;
    vector<ll> dist(55*3000, INFLL);
    dist[s] = 0;
    pq.push({dist[s], s});
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        ll from = tmp.second;
        ll d = tmp.first;
        for(auto p: edge2[from]){
            if(dist[p.to] > dist[from] + p.b){
                dist[p.to] = dist[from] + p.b;
                pq.push(l_l(dist[p.to], p.to));
            }
        }
    }
    return dist;
}
ll f(ll v, ll s){
    return v*3000 + s;
}
int main(){
    ll n, m ,s, u, v;
    cin >> n >> m >> s;
    edge1.resize(n);
    A.resize(m);
    B.resize(m);
    C.resize(n);
    D.resize(n);
    for(ll i = 0;i < m;i++){
        cin >> u >> v >> A[i] >> B[i];
        u--;v--;
        edge1[u].push_back({v,A[i],B[i]});
        edge1[v].push_back({u,A[i],B[i]});
    }
    for (int i = 0; i < n; ++i) {
        cin >> C[i] >> D[i];
    }
    edge2.resize(n*(3000+5));
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j <= 2999;j++){
            ll to = min(j + C[i], 2999ll);
            edge2[f(i,j)].push_back({f(i, to), 0, D[i]});
            for(auto e: edge1[i]){
                if(j - e.a < 0)continue;
                edge2[f(i,j)].push_back({f(e.to, j-e.a), e.a, e.b});
            }
        }
    }
    s = min(s, 2999LL);
    auto dist = dijkstra(f(0,s));
    for(ll i = 1;i < n;i++){
        ll ans = INFLL;
        for(ll j = 0;j < 3000;j++){
            ans = min(ans, dist[f(i, j)]);
        }
        cout << ans << endl;
    }
}