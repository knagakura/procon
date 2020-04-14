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
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    //print(A);
    int cnt = 1;
    rep(i,N-1){
        if(A[i]!=A[i+1])cnt++;
    }
    int m = N - cnt;
    if(m %2 == 0){
        cout<<cnt<<endl;
    }else{
        cout<<cnt - 1 <<endl;
    }
}