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

    int N, Q;
    cin >> N >> Q;
    vec<int> top(N);
    rep(i,N)top[i] = i;
    //下上
    vec<i_i> conte(2*N);
    rep(i,2*N){
        if(i < N){
            conte[i] = {N+i, -1};
        }
        else{
            conte[i] = {-1, i-N};
        }
    }
    while(Q--){
        int f, t, x;
        cin >> f >> t >> x;
        f--;t--;x--;
        //fromの処理
        int tmp_topf = top[f];
        //topが下になる
        top[f] = conte[x].first;
        //その上はなし
        conte[top[f]].second = -1;

        //toの処理
        //移動先のtopが下になる
        conte[x].first = top[t];
        conte[top[t]].second = x;
        //移動前のtopが移動先のtopになる
        top[t] = tmp_topf;
    }
    vec<int> ans(N);
    rep(i,N){
        int from = N+i;
        while(1){
            int to = conte[from].second;
            if(to == -1)break;
            ans[to] = i+1;
            from = to;
        }
    }
    rep(i,N){
        cout << ans[i] << endl;
    }
}