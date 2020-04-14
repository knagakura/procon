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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    ll ans = 0;
    print(A);
    if(N%2 == 0){//偶数
        //大小大小
        ans = 0;
        for (int i = N-1; i >= N/2; --i){
            if(i == N/2){
                ans += A[i];
            }
            else{
                ans += 2*A[i];
            }
            //cerr<<ans<<endl;
        }
        for(int i = 0; i < N/2; ++i){
            if(i == N/2-1){
                ans -= A[i];
            }
            else{
                ans -= 2*A[i];
            }
            //cerr<<ans<<endl;
        }
    }
    else{//奇数
        //大小大小大
        ll ans1 = 0;
        for (int i = N-1; i >=N/2; --i){
            if(i == N/2||i == N/2 + 1){
                ans1 += A[i];
            }
            else{
                ans1 += 2*A[i];
            }
        }
        for(int i = 0; i < N/2; ++i){
                ans1 -= 2*A[i];
        }
        //小大小大小
        ll ans2 = 0;
        for (int i = N-1; i >N/2; --i){
            ans2 += 2*A[i];
        }
        for(int i = 0; i <= N/2; ++i){
            if(i == N/2||i == N/2-1){
                ans2 -= A[i];
            }
            else{
                ans2 -= 2*A[i];
            }
        }
        ans = max(ans1,ans2);
        //cerr<<ans1<<" "<<ans2<<endl;
    }
    cout<<ans<<endl;

}