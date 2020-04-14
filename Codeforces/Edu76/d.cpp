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
    rep(i,n)cin>>a[i];
    int m;
    cin>>m;
    vector<int> power(n+2,0);
    rep(i,m){
        int p,s;
        cin>>p>>s;
        chmax(power[s],p);
    }
    for(int i = n;i>=2;i--){
        chmax(power[i-1],power[i]);
    }
    //print(power);
    
    int l = 0;
    int cnt = 0;
    while(l < n){
        for(int r = n; r >= l; r--){
            int length = r-l;
            if(r !=n&&length == 0){
                cout<<-1<<endl;
                return;
            }
            ll maxa  = 0;
            for(int k = l;k<r;k++){
                chmax(maxa,a[k]);
            }
            if(power[length]>=maxa){
                //cerr<<"l,r:"<<l<<" "<<r<<endl;
                //cerr<<power[length]<<" "<<maxa<<endl;
                cnt++;
                l = r;
                break;
            }
        }
    }
    cout<<cnt<<endl;
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