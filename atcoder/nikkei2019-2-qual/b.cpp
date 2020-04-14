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
const ll MOD = 998244353;

const double PI = acos(-1.0);
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin>>N;
    vector<ll> D(N);
    rep(i,N){
        cin>>D[i];
    }
    if(D[0] !=  0){
        cout<<0<<endl;
        return 0;
    }
    rep1(i,N){
        if(D[i] == 0){
            cout<<0<<endl;
            return 0;
        }
    }
    //print(D);
    sort(all(D));
    rep(i,N-1){
        if(D[i+1]-D[i] >1){
            cout<<0<<endl;
            return 0;
        }
    }
    D.push_back(INF);
    int cnt = 1;
    vector<ll> CNT;
    rep(i,N){
        if(D[i] == D[i+1]){
            cnt++;
        }
        else{
            CNT.push_back(cnt);
            cnt = 1;
        }
    }
    //print(CNT);
    rep(i,CNT.size()){
        if(CNT[i] == 0){
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans = 1;
    rep(i,CNT.size()-1){
        ans *= modpow(CNT[i],CNT[i+1],MOD);
        ans %= MOD;
    }
    cout<<ans<<endl;
}