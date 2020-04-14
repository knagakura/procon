#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

vector<pair<char,int>> RunLengthEncoder_ForString(string v){
    vector<pair<char,int>> RLE;
    int cnt = 1;
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
    int N,K;
    string S;
    cin>>N>>K;
    cin>>S;
    auto T = RunLengthEncoder_ForString(S);
    ll ans = 0;
    rep(i,(int)T.size()){
        ans += T[i].second-1;
    }
    ans = min((ll)N-1,ans + 2 * K);
    cout<<ans<<endl;
}