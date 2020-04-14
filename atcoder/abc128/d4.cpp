#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,K;
    cin>>N>>K;
    vector<ll> V(N);
    rep(i,N)cin>>V[i];

    ll ans = 0;
    //左からl個,右からr個とって、
    //負の数をK-(l + r)個捨てる
    for(int l = 0; l <= N; l++){
        for(int r = 0; r <= N; r++){
            if(l + r > K||l + r > N)continue;
            ll cnt = 0;
            priority_queue<ll, vector<ll>, greater<ll> > q;
            rep(i,l){
                q.push(V[i]);
                cnt += V[i];
            }
            rep(j,r){
                q.push(V[N-1-j]);
                cnt += V[N-1-j];
            }
            rep(_,K-(l+r)){
                if(q.empty())break;
                ll cur = q.top();
                if(cur < 0){
                    q.pop();
                    cnt -= cur;
                }
            }
            chmax(ans, cnt);
        }
    }
    cout<<ans<<endl;
}