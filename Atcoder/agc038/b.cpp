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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin>>N>>K;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    int ans = 1;
    priority_queue<int> Q;
    rep(i,K){
        Q.push(a[i]);
    }
    for(int i = K; i < N; ++i){
        //なくなるやつはa[i-1]
        //そいつとQ.top()が同じ時はpopする。
        cerr<<a[i-K]<<" "<<a[i]<<endl;
        cerr<<Q.top()<<endl;

        if(a[i-K] == Q.top()){
            Q.pop();
            ans++;
        }
        if(a[i]<Q.top()){
            ans++;
            cerr<<"++"<<endl;
        }
        Q.push(a[i]);
    }
    cout<<ans<<endl;

}