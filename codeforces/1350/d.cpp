#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    ll ok = 0;
    ll ng = N;
    auto xxx = [&](map<int,int> & mp, ll x) -> bool{
        if(mp[-1] >= x)return false;
        else{
            return mp[-1] + mp[0] >= x;
        }
    };
    auto check = [&](ll len) -> bool{
        map<int, int> mp;
        rep(i,len){
            if(a[i] < K)mp[-1]++;
            if(a[i] == K)mp[0]++;
            if(a[i] > K)mp[1]++;
            if(xxx(mp, (len+1)/2))return true;
        }
        for(int l = 1, r = len; r < N; l++,r++){
            if(a[l-1] < K)mp[-1]--;
            if(a[l-1] == K)mp[0]--;
            if(a[l-1] > K)mp[1]--;
            if(a[r] < K)mp[-1]++;
            if(a[r] == K)mp[0]++;
            if(a[r] > K)mp[1]++;
            if(xxx((mp), (len+1)/2))return true;
        }
        return false;
    };
    while(ng - ok > 1){
        ll mid = (ok + ng) /2;
        if(check(mid)) {
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout << (ok == 0 ? "no": "yes") << endl;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--) solve();
}