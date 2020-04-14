#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    int N;
    cin>>N;
    vector<ll> P(N),Q(N),C;
    rep(i,N){
        cin>>P[i];
        P[i]--;
        Q[P[i]] = i;
    }
    print(P);print(Q);
    int ans = 0;
    int cnt = 1;
    rep1(i,N){
        if(Q[i-1]<Q[i])cnt++;
        else{
            ans = max(ans, cnt);
            C.push_back(cnt);
            cnt = 1;
        }
        if(i == N-1){
            C.push_back(cnt);
        }
    }
    ans = max(ans, cnt);
    ans = N - ans;
    print(C);
    cout<<ans<<endl;

}