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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin>>a[i];
    }
    vec<ll> sums;
    for(int i = 0; i < N;i++){
        ll tmp = 0;
        for(int j = i; j < N; j++){
            tmp += a[j];
            sums.push_back(tmp);
        }
    }
    ll sz = sums.size();
    priority_queue<ll, vector<ll>, greater<ll>> q;
    vector<int> cnt(32, 0);
    rep(i,sz){
        q.push(sums[i]);
        rep(j,32){
            if(bit(j)&sums[i])cnt[j]++;
        }
    }
    //j bit目が立っている数がK以上なら、立っているだけpqに入れ直す。
    //cntの更新もする
    //j bit目が立っている数が
    for(int j = 31; j >= 0; j--){
        if(cnt[j] >= K){
            priority_queue<ll, vector<ll>, greater<ll>> nq;
            while(!q.empty()){
                ll tmp = 
            }
        }
    }
    ll ans = 0;
    cout << ans << endl;
}


//6/1 18:00 ~ 19:00