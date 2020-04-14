#include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 typedef long long ll;
 template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 int main() {
     int N;
     cin>>N;
     ll ans = 0;
     rep(i,N){
         ll a,t;
         cin>>a>>t;
         chmax(ans,max(a,t) + a);
     }
     cout<<ans<<endl;
 }