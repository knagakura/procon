#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

template<class T>
bool chmin(T& a, T b){
    if (a > b) {
        a = b; 
        return true;
    } 
    return false; 
}
const long long INFLL = (long long)1e18+1;

int main() {

    int A,B,M;
    cin>>A>>B>>M;
    vector<long long> a(A);
    long long mina = INFLL;
    rep(i,A){
        cin>>a[i];
        chmin(mina, a[i]);
    }
    vector<long long> b(B);
    long long minb = INFLL;
    rep(i,B){
        cin>>b[i];
        chmin(minb, b[i]);
    }
    long long ans = mina+minb;
    rep(i,M){
        int x,y,c;
        cin>>x>>y>>c;
        x--;y--;
        chmin(ans, a[x] + b[y] - c);
    }
    cout<<ans<<endl;
}