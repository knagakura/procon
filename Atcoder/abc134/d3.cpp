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

    int N;
    cin>>N;
    vector<int> a(N+1);
    rep1(i,N+1)cin>>a[i];
    vector<int> b(N+1,0);
    int M = 0;
    for(int i = N; i >= 1;i--){
        int sum = 0;
        //jはiの倍数 N / i 回
        for(int j = 2 * i;j <= N;j += i){
            sum = (sum + b[j]) % 2;
        }
        if(sum % 2 == 0 && a[i] == 0)b[i] = 0;
        if(sum % 2 == 0 && a[i] == 1)b[i] = 1;
        if(sum % 2 == 1 && a[i] == 0)b[i] = 1;
        if(sum % 2 == 1 && a[i] == 1)b[i] = 0;
        if(b[i])M++;
    }
    cout<<M<<endl;
    rep1(i,N+1){
        if(b[i]){
            cout<<i<<endl;
        }
    }
}