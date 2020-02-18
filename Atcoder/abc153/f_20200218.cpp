#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
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

    ll N,D,A;
    cin>>N>>D>>A;
    vector<pair<ll, ll>> XH(N);
    rep(i,N){
        cin>>XH[i].first>>XH[i].second;
    }
    sort(all(XH));
    vector<ll> X(N),H(N);
    rep(i,N){
        X[i] = XH[i].first;
        H[i] = XH[i].second;
    }
    //以前の爆発イベントを格納しておく
    //自分に影響のある範囲のみを常に保存していく
    //どこまでいくつの爆発が起きたのかを記録する
    //爆発範囲の右端, 回数
    queue<pair<ll, ll>> q;
    
    //qに詰まっている回数の合計
    ll qsum = 0;
    ll ans = 0;
    rep(i,N){
        while(!q.empty() &&  q.front().first < X[i]){
            qsum -= q.front().second;
            q.pop();
        }
        H[i] -= qsum * A;
        if(H[i] <= 0)continue;
        //回数
        ll cnt = (H[i] + A - 1) / A;
        ans += cnt;
        q.push(make_pair(X[i] + 2 * D, cnt));
        qsum += cnt;
    }
    cout<<ans<<endl;
}