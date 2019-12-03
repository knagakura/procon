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
ll pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

/*------------------------------------*/
void solve(){
    ll n;cin>>n;
    ll tmp = n;
    string S;
    while(tmp > 0){
        S.push_back(char(tmp%3 + '0'));
        tmp /= 3;
    }
    reverse(all(S));
    int M = S.size();
    bool f = true;
    rep(i,M){
        if(S[i]-'0'==2){
            f = false;
        }
    }
    if(f){
        cout<<n<<endl;
        return;
    }
    int idxz = -1;
    rep(i,M){
        if(S[i]-'0'==0)idxz = i;
        if(S[i]-'0'==2){
            if(idxz == -1){
                cout<<(ll)pow(3,(ll)S.size())<<endl;
                return;
            }
            break;
        }
    }
    S[idxz] = char('1');
    ll ans = 0;
    for(int i = 0; i <= idxz;i++){
        if(S[i] == '1'){
            ans += pow(3,M-1-i);
        }
    }
    cout<<ans<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;cin>>q;
    while(q--){
        solve();
    }
}