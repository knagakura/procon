#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = (ll)1e18+1;

void solve(){
    int n[3];
    rep(i,3)cin >> n[i];
    vec<i_i> v;
    rep(i,3)rep(j,n[i]){
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(all(v));
    //print(v);
    deque<i_i> q;
    int N = v.size();
    map<int, int> map;
    ll ans = INFLL * 3;
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    while(Q--){
        solve();
    }
}