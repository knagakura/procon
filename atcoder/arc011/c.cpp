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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s,g;
    cin >> s >> g;
    int N;
    cin >> N;
    vector<string> S;
    S.push_back(s);
    rep(i,N){
        string t;
        cin >> t;
        S.push_back(t);
    }
    S.push_back(g);
    if(s == g){
        cout << 0 << endl;
        cout << s << endl;
        cout << g << endl;
        return 0;
    }
    auto check = [&](int x, int y)->bool{
        int cnt = 0;
        rep(i,S[x].size()){
            if(S[x][i] != S[y][i])cnt++;
        }
        return cnt == 1;
    };
    vvec<int> G(N+2);
    rep(i,N+2)rep(j,N+2){
        if(i >= j)continue;
        if(check(i,j)){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    /*bfs*/
    vec<int> d(N+2, -1);
    vec<int> pre(N+2, -1);
    queue<int> q;
    q.push(0);
    d[0] = 0;
    while(not q.empty()){
        int from = q.front();
        q.pop();
        for(int nxt: G[from]){
            if(d[nxt] != -1)continue;
            d[nxt] = d[from] + 1;
            pre[nxt] = from;
            q.push(nxt);
        }
    }
    if(d.back() == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << d.back() -1 << endl;
    vec<string> ans;
    ans.push_back(S.back());
    int now = N+1;
    while(true){
        if(pre[now] == -1)break;
        ans.push_back(S[pre[now]]);
        now = pre[now];
    }
    reverse(all(ans));
    for(auto &a: ans){
        cout << a << endl;
    }
}