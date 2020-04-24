#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
template<typename T>
vector<pair<T,long long>> RunLengthEncoder(vector<T> &v){
    vector<pair<T,long long>> RLE;
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

vector<pair<char,long long>> RunLengthEncoder_ForString(string v){
    vector<pair<char,long long>> RLE;
    RLE.push_back({'0', 0LL});
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
    RLE.push_back({'0', 0LL});
    return RLE;
}

void solve(int t){
    string S;
    cin >> S;
    auto v = RunLengthEncoder_ForString(S);
    int M = v.size();
    vector<int> cnt(M+1, 0);
    rep(i,M){
        cnt[i] += v[i].first - '0';
        cnt[i+1] -= v[i].first - '0';
    }
    //print(cnt);
    string ans = "";
    rep(i,M){
        rep(_, abs(cnt[i])){
            ans.push_back(cnt[i] > 0 ? '(':')');
        }
        rep(_, v[i].second){
            ans.push_back(v[i].first);
        }
    }
    cout  << "Case #" << t << ": "  << ans << endl;
}
int main() {
    int t;
    cin >> t;
    rep(i,t){
        solve(i+1);
    }
}