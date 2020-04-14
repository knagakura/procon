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
    vector<ll> A(N),B(N);
    priority_queue<P> C;
    rep(i,N){
        cin>>A[i];
    }
    rep(i,N){
        cin>>B[i];
        C.push({B[i],i});
    }

    ll ans = 0;
    while(!C.empty()){
        auto maxx = C.top();
        C.pop();
        int maxB = maxx.first;
        int i_m = maxx.second;
        int i_r = i_m + 1;
        int i_l = i_m -1; 
        if(i_m == N-1){
            i_r = 0;
        }
        else if(i_m == 0){
            i_l = N-1;
        }
        if(maxB<B[i_l]+B[i_r]){
            cout<<-1<<endl;
            return 0;
        }
        //cerr<<maxB/(B[i_l]+B[i_r])<<endl;
        //A[i_m]より少なくならないようにしたい
        ll l = -1; ll r = maxB/(B[i_l]+B[i_r])+1;
        ll mid = (l+r)/2;
        while(r-l>1){
            //cerr<<mid<<endl;
            mid = (l+r)/2;
            if(maxB-(B[i_l]+B[i_r])*mid<A[i_m]){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        ans += l;
        maxB -= l*(B[i_l]+B[i_r]);
        B[i_m] = maxB;
        //print(A);
        //print(B);
        if(A[i_m] == B[i_m]){
            continue;
        }
        C.push({maxB,i_m});
    }
    if(A!=B){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;

}