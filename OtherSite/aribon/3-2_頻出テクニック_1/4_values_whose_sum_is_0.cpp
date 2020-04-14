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
    cin>>N;
    vector<int> A(N),B(N),C(N),D(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    rep(i,N)cin>>D[i];
    vector<int> AB, CD;
    rep(i,N)rep(j,N){
        AB.push_back(A[i] + B[j]);
        CD.push_back(C[i] + D[j]);
    }
    sort(all(AB));
    sort(all(CD));
    ll ans = 0;
    rep(i,N*N){
        int r = -AB[i];
        int add = upper_bound(all(CD), r) - lower_bound(all(CD), r);
        ans += add;
    }
    cout<<ans<<endl;
}