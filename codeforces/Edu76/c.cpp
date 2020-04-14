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
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    vector<int> idx[n];
    rep(i,n){
        cin>>a[i];
        a[i]--;
        idx[a[i]].push_back(i);
    }
    int ans = INF;
    rep(i,n){
        if((int)idx[i].size()==1)continue;
        rep(j,(int)idx[i].size()-1){
            chmin(ans, idx[i][j+1]-idx[i][j]+1);
        }
    }
    if(ans ==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}