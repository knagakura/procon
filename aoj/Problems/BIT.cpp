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

int N;
ll bit[200100];
void add(int a, int w){
    for(int x = a; x <= N; x += x & -x)bit[x] += w;
}
ll sum(int a){
    ll res = 0;
    for(int x = a; x > 0; x -= x & -x){
        res += bit[x];
    }
    return res;
}
int sum(int l, int r){
    return sum(r) - sum(l);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(all(b));
    map<ll, int> mp;
    rep(i,N)mp[b[i]] = i + 1;
    ll ans = 0;
    rep(i, N){
        ans += i - sum(mp[a[i]]);
        add(mp[a[i]], 1);
    }
    cout << ans << endl;
}