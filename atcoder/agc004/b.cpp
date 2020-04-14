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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,x;
    cin>>N>>x;
    vector<ll> a(N);
    vector<bool> getted(N,false);
    ll ans = 0;
    bool ALL = true;
    ll minn = 0;
    int min_idx = 0;
    rep(i,N){
        cin>>a[i];
        if(chmin(minn, a[i])){
            min_idx = i;
        }
        getted[i] = (a[i] <= x);
        if(getted[i]){
            ans += a[i];
            ALL = false;
        }
    }
    //

    if(ALL){
        rep(i,N){
            if(i == min_idx){
                ans += a[i];
                getted[i] = true;
            }
        }
    }

    print(a);
    print(getted);
    while(1){
        bool all_getted = true;
        rep(i,N){
            if(!getted[i])all_getted = false;
        }
        if(all_getted)break;
        //現状で回す操作をするべきなのか
        rep(i,N){

        }
    }
}