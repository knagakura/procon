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
bool isprime(int v) {
    if (v == 1) return false;
    if (v == 2) return true;
    for (int i = 2; 1LL * i*i <= v; i++) if (v%i == 0) return false;
    return true;
}
vector<int> cumsum(1e5 + 1, 0);
int query(int l, int r){
    return cumsum[r+1] - cumsum[l];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    //前処理
    vector<bool> prime(1e5 + 1, false);
    vector<bool> islike(1e5 + 1, false);
    for(int i = 1; i <= 1e5; i++){
        if(isprime(i)){
            prime[i] = true;
            if(i % 2 == 0)continue;
            if(prime[(i + 1) / 2]){
                islike[i] = true;
            }
        }
    }
    rep(i,1e5){
        cumsum[i+1] += cumsum[i] + islike[i];
    }
    int Q;
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l, r)<<endl;
    }
}