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
int n;
ll ans;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    vector<ll> v;
    for(int i = 1;i <=9;i++){
        v.push_back(i);
    }
    while(v.size() < 81){
        sort(all(v));
        reverse(all(v));
        rep(i,9){
            v.push_back(v[i] * 10 + (v[i] % 10));
        }
    }
    sort(all(v));
    //print(v);
    while(t--){
        cin>>n;
        ans = upper_bound(all(v),n)-v.begin();
        cout<<ans<<endl;
    }
}