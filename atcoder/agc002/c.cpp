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

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,L;
    cin>>N>>L;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    ll idx = 0;
    bool f = false;
    rep(i,N-1){
        if(a[i] + a[i+1] >= L){
            idx = i;
            f = true;
            break;
        }
    }
    if(!f){
        cout<<"Impossible"<<endl;
        return 0;
    }
    vector<int> ans;
    for(int i = idx; i < N-1; i++){
        ans.push_back(i);
    }
    for(int i = idx - 1; i >= 0; i--){
        ans.push_back(i);
    }
    reverse(all(ans));
    cout<<"Possible"<<endl;
    rep(i,N-1){
        cout<<ans[i] + 1<<endl;
    }
}