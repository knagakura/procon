#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    int N;string S;
    cin>>N>>S;
    int ans = 0;
    rep(i,10)rep(j,10)rep(k,10){
        int cnt = 0;
        
        if(cnt==3)ans++;
    }
    cout<<ans<<endl;
}