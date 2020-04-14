#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
bool check(ll a,ll b, ll x, ll x1, ll x2){
    if(a == b&&a == 0){
        return true;
    }
    if(a == b){
        if(x1 <= x + 1 && x + 1 <= x2)return true;
        else if(x1 <= x - 1 && x - 1 <= x2)return true;
        else return false;
    }
    ll dxx = b - a;
    if(x1 <= x+dxx && x + dxx <=x2)return true;
    return false;
}
bool solve(){
    ll a,b,c,d,x,y,x1,y1,x2,y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if(check(a,b,x,x1,x2) && check(c,d,y,y1,y2)){
        return true;
    }
    else return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--){
        if(solve()){
            cout << Yes << endl;
        }
        else{
            cout << No << endl;
        }
    }
}