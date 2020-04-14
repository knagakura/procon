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

vector<int64_t> a(55),p(55);

int64_t F(int64_t n, int64_t x){
    if(n == 0){
        if(x <= 0)return 0LL;
        else return 1;
    }
    else if(x <= 1 + a[n-1]){
        return F(n-1, x-1);
    }
    else{
        return p[n-1] + 1 + F(n-1, x - 2 - a[n-1]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int64_t n, x; cin >> n >> x;
    a[0] = p[0] = 1;
    for(int i=1; i<=n; ++i){
        a[i] = 2*a[i-1]+3;
        p[i] = 2*p[i-1]+1;
    }
    cout<< F(n,x) <<endl;
}