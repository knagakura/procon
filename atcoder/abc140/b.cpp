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
    vector<ll> A(N),B(N),C(N);
    rep(i,N){
        cin>>A[i];
        A[i]--;
    }
    rep(i,N)cin>>B[i];
    rep(i,N-1)cin>>C[i];
    //print(A);print(B);print(C);
    int ans =  B[A[0]]; 
    rep1(i,N){
        //cerr<<ans<<endl;
        ans += B[A[i]];
        if(A[i-1]+1==A[i]){
            ans += C[A[i-1]];
        }
    }
    cout<<ans<<endl;

}