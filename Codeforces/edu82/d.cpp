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
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M);
    vector<int> beki(M);
    ll sum = 0;
    rep(i,M){
        cin >> a[i];
        sum += a[i];
    }
    if(N > sum){
        cout << -1 << endl;
        return;
    }
    //aを二冪に
    rep(i,M){
        ll tmp = a[i];
        int cnt = 0;
        while(tmp > 1){
            tmp /= 2;
            cnt++;
        }
        beki[i] = cnt;
    }
    vector<int> Nbeki(60);
    int cnt = 0;
    while(N > 0){
        Nbeki[cnt] = N % 2;
        N /= 2;
        cnt++;
    }
    print(a);print(beki);print(Nbeki);
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