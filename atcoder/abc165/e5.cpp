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

    int N, M;
    cin >> N >> M;
    vector<i_i> ans;
    //奇数は単純
    if(N&1){
        for(int l = 1, r = N;l < r;l++,r--){
            ans.emplace_back(l, r);
        }
    }
    //偶数は途中で変えないといけない
    else{
        bool f = false;
        map<i_i, int> map;
        for(int l = 1,r = N; l < r; l++, r--){
            int a = r - l;
            int b = N - a;
            if(a > b)swap(a,b);
            if(!f&&(map[{a,b}]>0||a==b)){
                f = true;
                r--;
            }
            a = r-l;
            b = N-a;
            if(a > b)swap(a,b);
            ans.emplace_back(l, r);
            map[{a,b}]++;
        }
        print(map);
    }
    rep(i,M){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}