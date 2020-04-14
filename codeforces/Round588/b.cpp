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
    string S;
    cin>>S;
    if(K==0){
        cout<<S<<endl;
        return 0;
    }
    if(N == 1&&K>0){
        cout<<0<<endl;
        return 0;
    }
    int done = 0;
    if(S[0] != '1'){
        S[0] = '1';
        done++;
    }
    rep1(i,N){
        if(done>=K){
            break;
        }
        if(S[i] != '0'){
            S[i] = '0';
            done++;
        }
    }
    cout<<S<<endl;
}