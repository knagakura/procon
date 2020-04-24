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
void solve(){
    int N;
    cin >> N;
    vector<pair<pair<int, int>,int>> v;
    vector<int> imos(24 * 60 + 5);
    rep(i,N){
        int a, b;
        cin >> a >> b;
        imos[a]++;
        imos[b]--;
        v.push_back({{a,b},i});
    }
    //sort(all(v));
    rep(i,24*60+1){
        imos[i+1]+=imos[i];
    }
    //print(imos);
    print(v);
    bool ok = true;
    rep(i,24 * 60 + 1){
        if(imos[i] >= 3){
            ok = false;
        }
    }
    if(!ok){
          cout << "IMPOSSIBLE" << endl;
        return;
    }
    bool pairs[N][N];
    rep(i,N)rep(j,N)pairs[i][j] = false;
    /*
    rep(i,N)rep(j,N){
        if(i >= j)continue;
        int l1 = v[i].first.first;
        int r1 = v[i].first.second;
        int id1 = v[i].second;
        int l2 = v[j].first.first;
        int r2 = v[j].first.second;
        int id2 = v[j].second;
        pairs[id1][id2] = pairs[id2][id1] = !(r2 <= l1  || r1 <= l2);
    }*/
    //
    cout  << "" << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    rep1(i, t+1){
        cout  << "Case #" << i << ": ";
        solve();
    }
}