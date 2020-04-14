#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int N,A,B,C;
vector<int> l;
int dfs(int cnt, int a, int b, int c){
    if(cnt == N){
        if(a != 0&&b != 0&&c != 0){
            return abs(A-a) + abs(B-b) + abs(C-c) - 30;
        }
        else return INF;
    }
    int res = INF;
    res = min(res, dfs(cnt+1, a + l[cnt], b, c)+10);
    res = min(res, dfs(cnt+1, a, b + l[cnt], c)+10);
    res = min(res, dfs(cnt+1, a, b, c + l[cnt])+10);
    res = min(res, dfs(cnt+1, a, b, c));
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>A>>B>>C;
    l.resize(N);
    rep(i,N)cin>>l[i];
    cout<<dfs(0,0,0,0)<<endl;
}