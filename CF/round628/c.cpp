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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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

struct edge
{
    int to;int id;
};
vvec<edge> G;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    G.resize(N);
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    bool ok = false;
    vector<int> ans(N-1,-1);
    int cnt = 0;
    rep(i,N){
        if(G[i].size() > 2){
            ok = true;
            for(edge e: G[i]){
                int id = e.id;
                ans[id] = cnt;
                cnt++;
            }
            break;
        }
    }
    if(!ok){
        rep(i,N-1){
            cout << i << endl;
        }
        return 0;
    }

    rep(i,N-1){
        if(ans[i] == -1){
            ans[i] = cnt;
            cnt++;
        }
    }
    rep(i,N-1){
        cout << ans[i] <<endl;
    }
}