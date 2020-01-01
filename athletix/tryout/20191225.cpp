#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) 
#define all(a) (a).begin(),(a).end()

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

int main() {
    string S;
    cin>>S;
    sort(all(S));
    auto v = RunLengthEncoder_ForString(S);
    string ans = S;
    if(v[0].first == '0'){
        ans = "";
        ans.push_back(v[1].first);
        v[1].second--;
        for(auto p:v){
            while(p.second--){
                ans.push_back(p.first);
            }
        }
    }
    cout<<ans<<endl;
}