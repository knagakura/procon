#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)


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
void solve(){
    string s;
    cin>>s;
    auto v = RunLengthEncoder_ForString(s);
    int cnt = 0;
    for(auto p:v){
        if(p.first == '1')cnt++;
    }
    if(cnt < 2){
        cout<< 0 <<endl;
        return;
    }
    int ans = 0;
    bool ok = false;
    rep(i, v.size() - 1){
        if(!ok && v[i].first == '1')ok = true;
        if(ok && v[i].first == '0')ans += v[i].second;
    }
    cout<< ans <<endl;
}
int main() {

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}