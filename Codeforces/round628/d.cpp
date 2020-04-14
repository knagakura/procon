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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll u,v;
    cin >> u >> v;
    /*
    if(u > v){
        cout << -1 << endl;
        return 0;
    }*/
    /*
    if(u == v){
        if(u == 0){
            cout << 0 <<endl;
            return 0;
        }
        cout << 1 <<endl;
        cout << u << endl;
        return 0;
    }*/
    vector<ll> beki(62,0);
    rep(i,62){
        if(v & bit(i)){
            beki[i] = 1;
        }
    }
    /*
    print(beki);
    cerr << "u: ";
    for(int i = 60; i >= 0;i--){
        if(u & bit(i))cerr<<1;
        else cerr<<0;
    }
    cerr << endl;
    cerr << "v: ";
    for(int i = 60; i >= 0;i--){
        if(v & bit(i))cerr<<1;
        else cerr<<0;
    }
    cerr << endl;
    */
    for(int i = 60; i >= 1; i--){
        //xorのほうで立って
        if(u & bit(i)){
            /*1
              1*/
            if(beki[i] & 1)continue;
            /*1
              0*/
            else{
                if(beki[i] == 0){
                    cout << -1 << endl;
                    return 0;
                }
                beki[i]--;
                beki[i-1] += 2;
            }
        }
        else{
            /*0
              1*/
            if(beki[i] & 1){
                beki[i]--;
                beki[i-1] += 2;
            }
            /*0
              0*/
            else continue;
        }
    }
    //print(beki);
    if(beki[0] % 2 == 0 && u % 2 == 1){
        cout << -1 << endl;
        return 0;
    }
    if(beki[0] % 2 == 1 && u % 2 == 0){
        cout << -1 << endl;
        return 0;
    }
    ll n = 0;
    rep(i,61){
        chmax(n, beki[i]);
    }
    vector<ll> ans(n,0LL);
    rep(i,61){
        rep(j,beki[i]){
            ans[j] += bit(i);
        }
    }
    cout << n <<endl;
    rep(i,n){
        cout<<ans[i];
        if(i == n-1)cout<<endl;
        else cout << " ";
    }
}