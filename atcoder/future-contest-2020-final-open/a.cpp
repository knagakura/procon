#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int N,S,K;
vector< vector<P> > G(1005);
vector<vector<vector<int>>> T(1005,vector<vector<int>>(10005,vector<int>()));

int p[1005][22] = {};
/*------------------------------------
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> S >> K;
    rep(i,N){
        int x,y,c;
        cin>>x>>y>>c;
        x--;y--;
        G[x].push_back(make_pair(y,c));
        G[y].push_back(make_pair(x,c));
    }
    rep(i,S){
        rep1(j,K){
        cin>>p[i][j];
        p[i][j]--;
        T[i][j].push_back(p[i][j]);
        T[i][p[i][j]].push_back(j);  
        }
    }
}