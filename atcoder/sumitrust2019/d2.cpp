#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    int N;
    string S;
    cin>>N>>S;
    
    set<int> s1,s2,s3;
    rep(i,N){
        int num = S[i]-'0';
        for(auto x:s2){
            s3.insert(x * 10 + num);
        }
        for(auto x:s1){
            s2.insert(x * 10 + num);
        }
        s1.insert(num);
    }
    cout<<s3.size()<<endl;
}