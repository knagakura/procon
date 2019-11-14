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
const double eps = 1e-8;
const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(20);
    int T;
    cin>>T;
    rep(_,T){
        double n1,a,b;
        cin>>n1>>a>>b;
        double ans = -1; 
        double n2 = 0;
        int cnt = 0;

        while(1){
            n2 = a * n1 - b * n1*n1;
            if(cnt< 10||cnt>1e7 - 10){
                cerr<<cnt<<": "<<n2<<endl;
            }
            if(n2 < 0){
                ans = 0;
                break;
            }
            else if(abs(n2-n1) < eps){
                cerr<<"(n1,n2):"<<n1<<" "<<n2<<endl;
                if(n2 < 1e-8){
                    ans = 0;
                }
                else{
                    ans = n2;
                }
                break;
            }
            else if(n2 > INF){
                ans = -1;
                break;
            }
            if(cnt>1e7){
                cerr<<"収束"<<endl;
                cerr<<"(n1,n2):"<<n1<<" "<<n2<<endl;
                if(n2 < 1e-5){
                    ans = 0;
                }
                else{
                    ans = n2;
                }
                break;
            }
            n1 = n2;
            cnt++;
        }
        cout<<ans<<endl;
    }
}