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

    int N,Ave,D;
    cin>>N>>Ave>>D;

    int Sum = Ave * N;
    vector<ll> S(N);
    ll maxS = 0;
    ll minS = INFLL;
    double sumS = 0;
    rep(i,N){
        cin>>S[i];
        chmax(maxS, S[i]);
        chmin(minS, S[i]);
        sumS += S[i];
    }
    //P * S + Qにすると
    //合計   P * sumS + Q
    //差    P * (maxS - minS)
    //よって、P = d / (maxS - minS)
    //Q = Sum - P * sumS
    if(maxS - minS == 0){
        cout<<-1<<endl;
        return 0;
    }
    double P = D / double(maxS - minS);
    double Q = (Sum - D / double(maxS - minS) * sumS) / (double)N;
    cout<<P<<" "<<Q<<endl;
}