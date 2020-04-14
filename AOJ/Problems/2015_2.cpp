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

bool solve(){
    int N,M;
    cin>>N>>M;
    if(N == 0&&M==0)return true;
    vector<int> H(N),W(N);
    vector<int> a(1,0),b(1,0);
    //頻度分布
    vector<int> X(1005,0),Y(1005,0);
    rep(i,N){
        cin>>H[i];
        a.push_back(a.back() + H[i]);
    }
    rep(i,M){
        cin>>W[i];
        b.push_back(b.back() + W[i]);
    }
    int A = a.size();
    int B = b.size();
    rep(i,A)rep(j,A){
        if(i >= j)continue;
        int d = abs(a[i]-a[j]);
        X[d]++;
    }
    rep(i,B)rep(j,B){
        if(i >= j)continue;
        int d = abs(b[i]-b[j]);
        Y[d]++;
    }
    ll ans = 0;
    /*
    for(int i = 1;i <= 10;i++){
        cerr<<X[i]<<Y[i]<<endl;
    }*/
    //print(a);print(b);
    rep1(i,1001){
        ans += X[i] * Y[i];
    }
    cout<<ans<<endl;
    return false;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    while(1){
        if(solve())break;
    }
}