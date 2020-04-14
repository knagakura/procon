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
    cout << fixed << setprecision(20);
    int N,K;
    cin>>N>>K;
    vector<ll> A(N),F(N);
    priority_queue<int> que;
    rep(i,N){
        cin>>A[i];
        que.push(A[i]);
    }
    rep(i,N){
        cin>>F[i];
    }
    sort(all(F));
    while(K--){
        int x = que.top();
        cerr<<x<<endl;
        if(x ==0)break;
        que.pop();
        x--;
        que.push(x);
    }
    ll ans = 0;
    rep(i,N){
        int x = que.top();
        cerr<<x<<" "<<F[i]<<endl;
        que.pop();
        ans =max(ans, x * F[i]);
    }
    cout<<ans<<endl;
}