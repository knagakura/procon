#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
const string MINUSINF = "-";

void chmax(string &a, string b){
    if(a == MINUSINF)a = b;
    else if(a.size() < b.size())a = b;
    else if(a.size() == b.size()){
        if(a < b)a = b;

    }
}

//dp[i]:　i本使って作れる数字の最大値
int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7,6};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,M;
    cin>>N>>M;
    vector<int> A(M);
    rep(i,M)cin>>A[i];
    vector<string> dp(N+1, MINUSINF);
    dp[0] = "";
    rep(i,N){
        if(dp[i] == MINUSINF)continue;
        rep(j,M){
            if(i + cost[A[j]] > N)continue;
            chmax(dp[i+cost[A[j]]], dp[i] + char('0' + A[j]));
        }
    }
    cout<<dp[N]<<endl;
}