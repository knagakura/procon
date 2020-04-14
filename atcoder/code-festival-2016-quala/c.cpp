#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

int main() {
    string s;cin>>s;
    ll K;cin>>K;
    int N = s.size();
    //'a'との距離
    vector<int> v(N,0);
    rep(i,N){
        v[i] = 'z'-s[i]+1;
        if(s[i] == 'a')v[i] = 0;
    }
    rep(i,N){
        if(v[i]<=K){
            K-=v[i];
            v[i] = 0;
        }
    }
    K%=26;
    /*
    bool flag = true;
    for (int i = N-1; i >= 0; --i){
        if(v[i]>0){
            v[i] -=K;
            flag = false;
            break;
        }
    }
    //全部'a'になっているということ
    if(flag){
        v[N-1] +=26-K;
    }
    */
    if(v[N-1]==0)v[N-1] += 26-K;
    else{
        v[N-1]-=K;
    }
    string T = "";
    rep(i,N){
        if(v[i] == 0){
            T.push_back('a');
        }
        else{
            T.push_back(char('z'-v[i]+1));
        }
    }
    cout<<T<<endl;
}