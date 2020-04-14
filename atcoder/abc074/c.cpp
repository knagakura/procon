#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    a *= 100;
    b *= 100;
    int ans_all = 0;
    int ans_s = 0;
    double tmp = -1;
    for(int i = 0; i*a <= f; i++){
        for(int j = 0; i*a + j*b <= f;j++){
            int w = i*a + j*b;
            if(w == 0)continue;
            for(int k = 0;w + k*c <= f;k++){
                for(int l = 0; w + k*c + l*d <= f;l++){
                    int s = k*c + l*d;
                    if(s > (w / 100) * e)continue;
                    double noudo = 100*s/double(w + s);
                    if(tmp < noudo){
                        tmp = noudo;
                        ans_s = s;
                        ans_all = w + s;
                    }
                }
            }
        }
    }
    cout<<ans_all<<" "<<ans_s<<endl;
}

