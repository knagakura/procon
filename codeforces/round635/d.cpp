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
    deque<i_i> q;
    int N = v.size();
    map<int, int> map;
    ll ans = INFLL * 3;
    rep(i,N){
        q.push_back(v[i]);
        map[v[i].second]++;
        while(q.size() > 1){
            if(q.front().second == q.back().second){
                map[q.front().second]--;
                q.pop_front();
            }
            else if(q.front().second == q[1].second){
                map[q.front().second]--;
                q.pop_front();
            }
            else break;
        }
        if(map[0] > 0 && map[1] > 0 && map[2] > 0){
            ll l = q.front().first;
            ll r = q.back().first;
            int id1 = q.front().second;
            int id2 = q.back().second;
            for(int j = 1; j <= q.size() - 2;j++){
                if(q[j].second == 3 - id1 - id2){
                    ll mid = q[j].first;
                    ll tmp = 0;
                    tmp += (l - mid) * (l - mid);
                    tmp += (r - mid) * (r - mid);
                    tmp += (l - r) *   (l - r);
                    chmin(ans, tmp);
                }
            }
            map[q.front().second]--;
            q.pop_front();
        }
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    while(Q--){
        solve();
    }
}