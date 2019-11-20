#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

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
        }
    }
    return RLE;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
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