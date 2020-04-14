#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main() {
    int N;
    cin>>N;
    ll maxa = 0;
    ll maxt_a = 0;
    rep(i,N){
        ll a,t;
        cin>>a>>t;
        chmax(maxa,a);
        chmax(maxt_a,t + a);
    }
    cout<<max(2 * maxa,maxt_a)<<endl;
}