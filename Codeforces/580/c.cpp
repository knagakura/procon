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
    if(N%2 == 0){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
    }
    vector<int> v(2*N+1);
    for(int i = 1; i <= N; ++i){
        if(i%2  == 1){
            v[i] = 2*i-1;
            v[i+N] =2*i;
        }
        else{
            v[i] = 2*i;
            v[i+N] = 2*i-1;
        }
    }
    rep1(i,2*N+1){
        if(i == 2*N)cout<<v[i]<<endl;
        else{
            cout<<v[i]<<" ";
        }
    }

}