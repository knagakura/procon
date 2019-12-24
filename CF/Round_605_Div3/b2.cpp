#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
string S;
int N;
int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>S;
        N = S.size();
        map<char,int> map;
        rep(i,N)map[S[i]]++;
        int minx = min(map['L'],map['R']);
        int miny = min(map['U'],map['D']);
        if(minx == 0 && miny == 0){
            cout<<0<<endl;
            cout<<endl;
            continue;
        }
        if(minx == 0 || miny == 0){
            cout<<2<<endl;
            if(minx == 0)cout<<"UD"<<endl;
            else cout<<"LR"<<endl;
            continue;
        }
        cout<<2 * (minx+miny)<<endl;
        rep(i,minx)cout<<"L";
        rep(i,miny)cout<<'U';
        rep(i,minx)cout<<"R";
        rep(i,miny)cout<<"D";
        cout<<endl;
    }
}