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

    int N;
    ll D,A;
    cin>>N>>D>>A;
    vector<pair<ll,ll>> XH;
    rep(i,N){
        int x,h;
        cin>>x>>h;
        XH.push_back({x,h});
    }
    sort(all(XH));
    vector<ll> X(N),H(N);
    rep(i,N){
        X[i] = XH[i].first;
        H[i] = (XH[i].second + A - 1) / A;
    }
    ll ans = 0;

    queue<pair<ll,ll>> Q;
    ll Qsum = 0;
    rep(i,N){
        //古い情報から見ていって、今見ている位置に影響を与えない
        //爆発は除いていく
        while(!Q.empty() && Q.front().first < X[i]){
            Qsum -= Q.front().second;
            Q.pop();
        }
        //今までの爆発でできるやつ
        H[i] -= Qsum;
        //すでに死んでいたら何もしない
        if(H[i] <= 0)continue;
        ans += H[i];
        Q.push(make_pair(X[i]+2*D, H[i]));
        Qsum += H[i];
    }
    cout<<ans<<endl;
}