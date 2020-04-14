#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double a,b,x;
    cin>>a>>b>>x;
    if(x<=a*b*a/2){
        double radian = atan2(b, 2*x/(a*b));
        //cout<< radian <<endl;
        cout<< radian* 180 / PI<<endl;
    }
    else{
        double radian = atan(2*(a*a*b-x)/(a*a*a));
        cout<<radian*180/PI<<endl;
    }
}