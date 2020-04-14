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
        ll b = PQ.top().first;
        ll idx = PQ.top().second;
        PQ.pop();
        ll a = B[(idx-1+N)%N];
        ll c = B[(idx+1+N)%N];
        ll wa = a+c;
        ll diff = b - A[idx];
        if(diff == 0){
            continue;
        }
        else if(diff<0){
            cout<<-1<<endl;
            return 0;
        }
        else{
            if(diff/wa<=0){
            cout<<-1<<endl;
            return 0;
            }
            print(A);
            print(B);
            cerr<<diff<<" "<<wa<<endl;
            ans += diff/wa;
            b -= (diff/wa)*wa;
            B[idx] = b;
        }
        PQ.push({b,idx});
    }
    if(A!=B){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
}
