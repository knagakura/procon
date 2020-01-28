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

    ll N,K,S;
    cin>>N>>K>>S;
    vector<int> A(N,S);
    if(N == K){
        rep(i,N){
            cout<<A[i]<<endl;
        }
        return 0;
    }
    if(S == 1){
        rep(i,K){
            cout<<1<<endl;
        }
        rep(i,N-K){
            cout<<min(S+1,(ll)1e9)<<endl;
        }
        return 0;
    }
    ll a = S/2;
    ll b = S - a;
    rep(i,N){
        if(i < K+1){
            if(i % 2 == 0)cout<<a<<endl;
            else cout<<b<<endl;
        }
        else{
            if(S == 1e9){
                cout<<5<<endl;
            }
            else{
                cout<<min(S+1,(ll)1e9)<<endl;
            }
        }
    }
    /*
    rep(i,K+1){
        if(i%2 == 0){
            A[i] = a;
        }
        else A[i] = b;
    }
    for(int i = K+1;i<N;i++){
        A[i] = min(S+1,(ll)1e9);
    }
    rep(i,N){
        cout<<A[i]<<endl;
    }
    */
}