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

void solve(){
    int N;
    cin>>N;
    vector<int> v(N);
    rep(i,N){
        cin>>v[i];
    }
    int M = v.size();
    vector<int> cnt(5000,0);
    rep(i,M){
        if(v[i]<=2048)cnt[v[i]]++;
    }
    /*
    for(int i = 2; i<2048; i*=2){
        cerr<<cnt[i]<<" ";
    }
    cerr<<endl;
    */
    for(int i = 1; i<2048; i*=2){
        cnt[2*i] += int(cnt[i]/2);
    }
    /*
    for(int i = 2; i<=2048; i*=2){
        cerr<<cnt[i]<<" ";
    }
    cerr<<endl;
    */
    if(cnt[2048]>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}
int main() {
    int q;
    cin>>q;
    rep(i,q){
        solve();
    }
}