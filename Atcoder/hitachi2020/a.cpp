#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    
    string S;
    cin>>S;
    if(S.size()%2 == 1){
        cout<<"No"<<endl;
        return 0;
    }
    rep(i, (int)S.size()-1){
        if(S[i] == 'h' && S[i+1] == 'i'){
            i++;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}