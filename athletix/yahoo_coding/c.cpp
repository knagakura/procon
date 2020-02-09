#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
 
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({ 0,start });
 
        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u : edge[from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]) {
                    cost[to] = w;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
};

/*
使い方
1. まずインスタンス生成
重みの型、頂点の数、距離の無限大のINFLL
Dijkstra<ll> d(N, INFLL);

2. 辺を貼る
iからjに重みwの辺を貼る場合
d.make_edge(i,j,w);

3. 頂点sから解く
d.solve(s);

4. sからgの距離
d.cost[g]

GigaCode2019 E - 車の乗り継ぎ
https://atcoder.jp/contests/gigacode-2019/submissions/8651446

*/
/*------------------------------------*/
ll N,M,S,T;
vector<ll> a,b;
void input(){
    cin>>N>>M>>S>>T;
    a.resize(N);
    b.resize(M);
    rep(i,N)cin>>a[i];
    rep(i,M)cin>>b[i];
}
void solve1(){
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    vector<int> v = {0,1,2,3};
    vector<ll> za = {a[0],b[0],b[1],S};
    sort(all(v));
    //Q[i]:i個訪れるの最小値
    ll Q[2] = {INFLL,INFLL};
    do{
        print(v);
        ll x = 0;
        ll time = 1;
        ll cnt = 0;
        x += za[v[0]];
        time += za[v[0]];
        if(v[0] == 0){
            cnt++;
        }
        for(int i = 0; i < 3;i++){
            if(x == S)break;
            //teleport
            if((v[i] == 1 && v[i+1] == 2) || (v[i] == 2 && v[i+1] ==1)){
                time += 0;
                x = za[v[i+1]];
                continue;
            }
            x = za[v[i+1]];
            time += abs(za[v[i+1]] - za[v[i]]);
            if(x == a[0])cnt++;
        }
        
        if(time <= T){
            Q[cnt] = min(Q[cnt], time);
        }
    }while(next_permutation(all(v)));
    if(Q[1] != INFLL) cout<<1<<" "<<Q[1]<<endl;
    else cout<<0<<" "<<Q[0]<<endl;
}
void solve2(){
    //time[i]を取るのに必要な時間
    vector<ll> time(N+1,0);
    rep1(i,N+1){
        time[i] = 2 * min(a[i-1]-b[i-1], b[i]-a[i-1]);
    }
    
    ll anstime = 0;
    ll anscnt = 0;
    if(N >= 100)return;
    for(int i = 0; i < bit(N);i++){
        ll tmp = b[0] + S - b[M-1];
        ll cnt = 0;
        for(int j = 0;j < N;j++){
            if(i & bit(j)){
                tmp+= time[j+1];
                cnt++;
            }
        }
        cerr<<tmp<<endl;
        if(tmp <= T){
            if(chmax(anscnt,cnt) && chmax(anstime,tmp)&&tmp <= T){
                anstime = tmp;
            }
        }
    }
    cout<<anscnt<<" "<<anstime<<endl;
}
void solve(){
    Dijkstra<ll> G(N + M + 2, INFLL);
    for(int i = 0; i < N+M+2; i++){
        for(int j = 0; j < N+M+2;j++){
            int w = 0;
            G.make_edge(i,j,w);
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    input();
    if(N == 1 && M == 2)solve1();
    else if(M == N+1)solve2();
}