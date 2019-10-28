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
ll N,Q;
string s;
vector<char> t,d;


int main() {
    cin>>N>>Q>>s;
    t.resize(Q);d.resize(Q);
    rep(i,Q){
        cin>>t[i]>>d[i];
    }
    //simulation
    vector<int> golem(N+2,1);
    rep(i,Q){
        rep(j,N){
            if(s[j] == t[i]){
                if(d[i] == 'R'){
                    golem[j+1+1] += golem[j+1];
                    golem[j+1]=0;
                }
                else{
                    golem[j+1-1] += golem[j+1];
                    golem[j+1] = 0;
                }
            }
        }
    }
}