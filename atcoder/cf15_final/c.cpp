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
int ans;
vector<int> D,times;
map<int, int> mp;
void dfs(int cur){
    if(cur == N){
        int sz = times.size();
        int tmp = INF;
        rep(i,sz)rep(j,sz){
            if(i >= j)continue;
            int d = abs(times[i] - times[j]);
            chmin(tmp, min(d, 24-d));
        }
        chmax(ans, tmp);
        return;
    }
    rep(j,2){
        int add = (j ? 24 - D[cur]: D[cur]);
        times.push_back(add);
        mp[add]++;
        if(mp[add] == 1){
            dfs(cur+1);
        }
        mp[add]--;
        times.pop_back();
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    D.resize(N);
    rep(i,N)cin>>D[i];
    ans = 0;
    times.push_back(0);
    mp[0]++;
    dfs(0);
    cout << ans << endl;
}