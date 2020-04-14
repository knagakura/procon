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
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int m;
    cin>>m;
    vector<int> b(m);
    rep(i,m)cin>>b[i];
    seti v;
    rep(i,n){
        v.insert(a[i]);
    }
    rep(j,m){
        v.insert(b[j]);
    }
    rep(i,n)rep(j,m){
        int ab = a[i]+b[j];
        if(v.find(ab)==v.end()){
            cout<<a[i]<<" "<<b[j]<<endl;
            return 0;
        }
    }
}