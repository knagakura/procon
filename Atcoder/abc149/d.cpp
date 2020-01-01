#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
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
//
//dp[i][k][j]
//i回目までで、i回目にkを出して、
ll dp[123456][10][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,K,R,S,P;
    string T;

    cin>>N>>K>>R>>S>>P>>T;

    //勝つ手
    map<char, ll> map;
    map['r'] = P;
    map['s'] = R;
    map['p'] = S;

    ll ans = 0;
    vector<string> vt(K,"");
    rep(i,K){
        int idx = i;
        while(idx < N){
            vt[i].push_back(T[idx]);
            idx += K;
        }
    }
    rep(i,K){
        //cerr<<vt[i]<<endl;
        auto v = RunLengthEncoder_ForString(vt[i]);
        for(int j = 0; j < (int)v.size(); j++){
            if(v[j].second % 2 == 0){
                ans += map[v[j].first] * v[j].second/2;
            }
            else{
                ans += map[v[j].first] * (v[j].second/2 + 1);
            }
        }
    }
    cout<<ans<<endl;
}