#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
    int N,K;
    cin>>N>>K;
    int cnt =0;
    vector<int> h(N);
    for(int i = 0;i<N;i++)cin>>h[i];
    for(int i = 0; i<N; i++){
        if(h[i] >= K){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}