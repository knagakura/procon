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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    a.push_back(a[N-1]);
    //初期化
    ll cnt = 0;
    //0 ~ K-1まで
    deque<int> q;
    rep(i,K)q.push_back(a[i]);
    for(int i = 1; i <= K-2; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]){
            cnt++;
        }
    }
    ll ans = cnt;
    ll l = 0;
    for(ll i = K; i < N; i++){

        //i - K が抜ける
        if(a[i-K] < a[i-K+1] && a[i-K+1] > a[i-K+2]){
            cnt--;
            q.pop_front();
        }
        //iが入る
        if(a[i-2] < a[i-1] && a[i-1] > a[i]){
            cnt++;
            q.push_back(a[i]);
        }
        if(ans < cnt){
            ans = cnt;
            l = i - K + 1;
        }
    }
    cout << ans + 1 <<" " <<  l + 1 << endl;
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