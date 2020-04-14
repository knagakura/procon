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
    int N;string S;
    cin>>N>>S;
    int cntz = 0, cntn = 0;
    rep(i,N){
        if(S[i] == 'n')cntn++;
        else if(S[i] == 'z'){
            cntz++;
        }
    }
    rep(i,cntn){
        cout<<1<<" ";
    }
    rep(i,cntz){
        cout<<0;
        if(i == cntz-1){
            cout<<endl;
        }
        else cout<<" ";
    }
}