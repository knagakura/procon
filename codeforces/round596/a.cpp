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
    int a,b;
    cin>>a>>b;
    int x,y;
    if(a == b){
        x = 100*a;
        y = 100*a+1;
    }
    else if(b-a==1){
        x = b*100-1;
        y = b*100;
    }
    else if(a == 9&&b == 1){
        x = 9;
        y = 10;
    }
    else{
        cout<<-1<<endl;
        return 0;
    }
    cout<<x<<" "<<y<<endl;
}