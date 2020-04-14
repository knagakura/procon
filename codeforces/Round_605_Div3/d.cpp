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

    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    vector<int> s(n+1,0);
    s[0] = 1;
    s[n] = 1;
    ll ans = 0;
    ll cnt = 1;
    rep(i,n-1){
        if(a[i+1]-a[i] > 0){
            s[i+1] = 1;
            cnt++;
        }
        else{
            chmax(ans, cnt);
            cnt = 1;
        }
    }
    chmax(ans, cnt);
    //cerr<<" ";print(a);
    //cerr<<"  ";print(s);
    //iを外したときに、その前後が繋がるのか
    //繋がるのだとしたら、それらはもともと何個繋がってきたのか
    //iを削除したとき、見たいのは、s[i]とs[i+1]
    //両方1なら、変化なし
    //片方でも0なら、変化が起きる
    //両端からの累積連続値を持っておいて、考える。
    vector<ll> cuml(n+2,0),cumr(n+2,0);
    rep1(i,n+1){
        if(s[i-1] == 1){
            cuml[i] = cuml[i-1]+1;
        }
        else{
            cuml[i] = 1;
        }
    }
    for(int i = n;i >= 1;i--){
        if(s[i] == 1)cumr[i] = cumr[i+1]+1;
        else cumr[i] = 1;
    }
    //print(cuml);
    //print(cumr);
    rep1(i,n-1){
        //cerr<<a[i-1]<<" "<<a[i+1]<<endl;
        //cerr<<cuml[i]<<" "<<cumr[i+2]<<endl;
        if(a[i-1] < a[i+1]){
            //cerr<<cuml[i]<<" "<<cumr[i+2]<<endl;
            chmax(ans, cuml[i] + cumr[i+2]);
        }
    }
    cout<<ans<<endl;
}