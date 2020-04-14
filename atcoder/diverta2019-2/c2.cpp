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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    ll ans = 0;
    vector<pair<ll,ll>> ansv;
    rep1(i,N-1){
        if(A[i] >= 0){
            ansv.push_back(make_pair(A[0],A[i]));
            A[0]-=A[i];
        }
        else{
            ansv.push_back(make_pair(A[N-1],A[i]));
            A[N-1]-=A[i];
        }
    }
    ansv.push_back(make_pair(A[N-1],A[0]));
    A[N-1] -= A[0];
    cout<<A[N-1]<<endl;
    for(auto p:ansv){
        cout<<p.first<<" "<<p.second<<endl;
    }
}