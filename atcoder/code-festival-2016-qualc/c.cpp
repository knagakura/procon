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
    int N;
    cin>>N;
    vector<ll> T(N),A(N);
    ll maxT = 0, maxA = 0;
    rep(i,N){cin>>T[i];maxT = max(maxT, T[i]);}
    rep(i,N){cin>>A[i];maxA  = max(maxA, A[i]);}
    if(maxT!=maxA){
        cout<<0<<endl;
        return 0;
    }
    if(A[0]!=T[N-1]){
        cout<<0<<endl;
        return 0;
    }
    //自由度があるかないか
    vector<int> GL(N),GR(N);
    GL[0] = 0;
    GR[N-1] = 0;
    rep1(i,N){
        if(T[i-1]==T[i]){
            GL[i] = 1;
        }
        else{
            GL[i] = 0;
        }
    }
    for (int i = N-2; i >= 0; --i){
        if(A[i]==A[i+1]){
            GR[i] = 1;
        }
        else{
            GR[i] = 0;
        }
    }
    //print(GL);
    //print(GR);
    ll ans = 1;
    rep(i,N){
        //cerr<<GR[i]<<" "<<GL[i]<<endl;
        //cerr<<T[i]<<" "<<A[i]<<endl;
        if(GR[i]==1&&GL[i]==1){
            ans*=min(T[i],A[i]);
            ans%=MOD;
        }
        else if(GL[i]==1&&GR[i]==0){
            if(T[i]>=A[i]){
                continue;
            }
            else{
                ans*=0;
            }
        }
        else if(GL[i]==0&&GR[i]==1){
            if(T[i]<=A[i]){
                continue;
            }
            else{
                ans*=0;
            }
        }
        //cerr<<ans<<endl;
    }
    cout<<ans<<endl;

}