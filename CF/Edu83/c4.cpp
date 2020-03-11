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

void solve(){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector<int> beki(60);
    //k進数に変換する
    rep(i,N){
        int cnt = 0;
        while(A[i] > 0){
            if(A[i] % K > 1){
                cout<<NO<<endl;
                return;
            }
            if(A[i] % K == 1){
                beki[cnt]++;
            }
            A[i] /= K;
            cnt++;
        }
    }
    rep(i,60){
        if(beki[i] > 1){
            cout<<NO<<endl;
            return;
        }
    }
    cout<<YES<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;

    cin>>q;
    while(q--){
        solve();
    }
}