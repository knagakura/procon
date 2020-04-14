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
void debug(queue<pair<int, ll>> q){
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        cerr<<"{"<<x.first<<", "<<x.second<<"}, ";
    }
    cerr<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,D,A;
    cin>>N>>D>>A;

    vector<pair<ll,ll>> XH(N);
    vector<ll> X(N),H(N);
    rep(i,N){
        cin>>XH[i].first>>XH[i].second;
    }
    sort(all(XH));
    rep(i,N){
        X[i] = XH[i].first;
        H[i] = (XH[i].second + A - 1) / A;
    }
    //print(X);print(H);

    /*queueの中に必要なもの
    {index, そこでの爆発回数}
    */
    ll sumq = 0;
    queue<pair<int,ll>> q;
    ll ans = 0;
    rep(i,N){
        //左端の設定
        while(!q.empty()){
            auto l = q.front().first;
            auto h = q.front().second;
            if(X[l] < X[i] - 2 * D){
                sumq -= h;
                q.pop();
            }
            else break;
        }
        //debug(q);
        //cerr<<sumq<<endl;
        //すでに起こった爆発
        H[i] -= sumq;
        if(H[i] <= 0)continue;
        //今起こった爆発を記録
        ans += H[i];
        sumq += H[i];
        q.push({i, H[i]});
    }
    cout<<ans<<endl;
}

/*あるiを見たとき
すでにある爆発でいくら減ってるかを計算したい
左端がどこまで効いてくるのかを考えたい

qの中には,過去の履歴が残っている
*/
