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
template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    map<int, int> fac;
    rep1(y,N+1){
        int x = y;
        for(int i = 2; i * i <= x; i++){
            while (x%i == 0) {
                x /= i;
                fac[i]++;
            }
            if (x == 1) break;
        }
        if (x != 1) fac[x]++;
    }
    vector<int> fap;
    for(auto p: fac){
        fap.push_back(p.second);
    }
    ll ans = 0;
    int sz = fap.size();
    sort(all(fap));
    print(fap);
    //74
    rep(i,sz){
        if(fap[i] >= 74)ans++;
    }
    //2 * 24
    rep(i,sz)rep(j,sz){
        if(i >= j)continue;
        if(fap[i] >= 2 && fap[j] >= 24)ans++;
    }
    //4 * 14
    rep(i,sz)rep(j,sz){
        if(i >= j)continue;
        if(fap[i] >= 4 && fap[j] >= 14)ans++;
    }
    rep(i,sz)rep(j,sz)rep(k,sz){
        if(i < j && j < k){
            if(fap[i] >= 2 && fap[j] >= 4 && fap[k] >= 4)ans++;
        }
    }
    cout << ans << endl;
}
//f[i]: i乗以上のものがいくつあるか

//74乗
/*
75 = 1 * 75 = 3 * 25 = 5 * 15 = 3 * 5 * 5
     0 * 74 = 2 * 24 = 4 * 14 = 2 * 4 * 4
*/