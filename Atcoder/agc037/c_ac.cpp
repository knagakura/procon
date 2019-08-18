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
    priority_queue<P> PQ;
    rep(i,N)cin>>A[i];
    rep(i,N){
        cin>>B[i];
        PQ.push({B[i],i});
    }
    ll ans = 0;
    while(!PQ.empty()){
        auto maxx = PQ.top();
        PQ.pop();
        int b = maxx.first;
        int i_m = maxx.second;
        int i_r = i_m + 1;
        int i_l = i_m -1; 
        if(b == A[i_m]){
            continue;
        }
        if(i_m == N-1){
            i_r = 0;
        }
        else if(i_m == 0){
            i_l = N-1;
        }
        ll a = B[i_l];
        ll c = B[i_r];
        if(b<=a+c){
            cout<<-1<<endl;
            return 0;
        }
        if((b-A[i_m])%(a+c)==0){
            ans+=(b-A[i_m])/(a+c);
            B[i_m] = A[i_m];
        }
        else{
            ans += b/(a+c);
            b %= (a+c);
            B[i_m] = b;
        }
        if(A[i_m] == B[i_m]){
            continue;
        }
        PQ.push({b,i_m});
    }
    if(A!=B){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
