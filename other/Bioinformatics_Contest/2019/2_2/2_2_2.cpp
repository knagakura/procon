#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double eps = numeric_limits<double>::epsilon();
const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(20);
    int T;
    cin>>T;
    rep(_,T){
        double n[3];
        double a,b;
        cin>>n[0]>>a>>b;
        n[1] = a * n[0] - b * n[0] * n[0];
        n[2] = a * n[1] - b * n[1] * n[1];
        double ans = 0;
        if(n[1]<=0||n[2]<=0){
            ans = 0;
        }
        else if(n[0] == n[1]&&n[1] == n[2]){
            ans = n[0];
        }
        //単調増加or減少
        else if((n[1]-n[0]) * (n[2]-n[0]) >0){
            if(n[1]-n[0]>0){
                ans = -1;//INF
            }
            else{
                ans = 0;
            }
        }
        //振動
        else if((n[1]-n[0]) * (n[2]-n[0]) <0){
            ans = -1;
        }
        cout<<ans<<endl;
    }
}