#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    ll N,K;string S;
    cin>>N>>K>>S;
    S.push_back('.');

    ll cnt = 0;
    rep(i,N){
        if(i == N-1)continue;
        if(S[i]!=S[i+1]){
            cnt++;
        }
    }
    cerr<<cnt<<endl;
    ll kyoukai = cnt - K*2;
    cerr<<kyoukai<<endl;
    if(kyoukai<0){
        cout<<N-1<<endl;
        return 0;
    }
    ll ans = N - kyoukai-1;
    cout<<ans<<endl;
}