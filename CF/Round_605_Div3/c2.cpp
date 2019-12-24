#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
/*------------------------------------/
for library*/

vector<pair<char,long long>> RunLengthEncoder_ForString(string v){
    vector<pair<char,long long>> RLE;
    long long cnt = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        if(i == (int)v.size()-1){
            RLE.push_back(make_pair(v[i], cnt));
            continue;
        }
        if(v[i] == v[i+1])cnt++;
        else{
            RLE.push_back(make_pair(v[i],cnt));
            cnt = 1;
        }
    }
    return RLE;
}
/*------------------------------------*/

int main() {

    int N,K;
    string S;
    cin>>N>>K>>S;
    vector<char> c(K);
    rep(i,K)cin>>c[i];
    string T = "";
    rep(i,N){
        bool ok = false;
        rep(j,K){
            if(S[i] == c[j]){
                ok = true;
            }
        }
        if(ok)T.push_back('1');
        else T.push_back('0');
    }
    cerr<<T<<endl;
    auto v = RunLengthEncoder_ForString(T);
    ll ans = 0;
    for(auto p:v){
        if(p.first == '1'){
            ans += p.second * (p.second+1)/2;
        }
    }
    cout<<ans<<endl;
}