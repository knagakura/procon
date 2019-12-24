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

    int t;
    cin>>t;
    while(t--){
        vector<ll> a(3);
        cin>>a[0]>>a[1]>>a[2];
        sort(all(a));
        set<ll> s;
        rep(i,3)s.insert(a[i]);
        ll ans = 0;
        if(s.size() == 2){
            if(a[0] == a[1]){
                if(a[2] - a[1] == 1){
                    a[2]--;
                }
                else{
                    a[0]++;a[1]++;a[2]--;
                }
            }
            else if(a[1] == a[2]){
                if(a[1]- a[0] == 1){
                    a[0]++;
                }
                else{
                    a[0]++;a[1]--;a[2]--;
                }
            }
            ans = a[2]-a[1] + a[1]-a[0] + a[2] - a[0];
        }
        if(s.size() == 3){
            a[0]++;
            a[2]--;
            //print(a);
            ans = a[2]-a[1] + a[1]-a[0] + a[2] - a[0];
        }
        cout<<ans<<endl;
    }
}