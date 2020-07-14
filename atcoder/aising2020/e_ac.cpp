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

ll N;
ll calc(vector<l_l> &v){
    ll res = 0;
    int sz = v.size();
    priority_queue<ll> pq;
    sort(all(v));
    //大きい方から
    int idx = sz-1;
    for(int i = N - 1; i >= 0; i--){
        while(idx >= 0 && v[idx].first == i){
            pq.push(v[idx].second);
            idx--;
        }
        if(pq.empty())continue;
        res += pq.top();
        pq.pop();
    }
    return res;
}
void solve(){
    cin >> N;
    vector<l_l> lefts;
    vector<l_l> rights;
    ll base = 0;
    rep(i,N){
        ll K, L, R;
        cin >> K >> L >> R;
        K--;
        if(L >= R){
            base += R;
            lefts.emplace_back(K, L-R);
        }
        else{
            base += L;
            K++;
            rights.emplace_back(N-1-K, R-L);
        }
    }
    ll ans = base + calc(lefts) + calc(rights);
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)solve();
}
