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
ll N,X;
string S;
vector<ll> cnt;
void solve(){
    cin>>N>>X>>S;
    cnt.assign(N, 0);

    int tmp = 0;
    rep(i,N){
        if(S[i] == '0')tmp++;
        else tmp--;
        cnt[i] = tmp;
    }
    ll a = cnt.back();
    ll ans = 0;
    if(X == 0)ans++;
    /*
    cerr<<"X,a: "<<X<<" "<<a<<endl;
    print(cnt);
    */
    if(a == 0){
        rep(i,N){
            if(cnt[i] == X){
                cout<<-1<<endl;
                return;
            }
        }
        cout<< 0 <<endl;
    }
    else if(a < 0){
        rep(i,N){
            if(X - cnt[i] <= 0){
                if((-(X-cnt[i])) % (-a) ==0){
                    ans++;
                }
            }
        }
        cout<< ans << endl;
    }
    else{
        rep(i,N){
        if(X - cnt[i] >= 0){
            if((X - cnt[i]) % a == 0)ans++;
            }
        }
        cout<<ans<<endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}