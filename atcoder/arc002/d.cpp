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

    ll H, W;
    cin >> H >> W;
    vector<string> c(H);
    rep(i,H)cin >> c[i];
    vvec<pair<int, int>> v(H);
    rep(i,H)rep(j,W){
        if(c[i][j] == 'o')v[i].emplace_back(j, 0);
        if(c[i][j] == 'x')v[i].emplace_back(j, 1);
    }
    rep(i,H)print(v[i]);
    ll cnt[2] = {0,0}; // 距離1で向かう合うまでの余裕の回数
    ll len[2] = {INFLL,INFLL}; // 前に誰もいなくて、突入できる場合の距離の最小値

    rep(i,H){
        int sz = v[i].size();
        rep(j,sz){
            int x = v[i][j].first;
            int a = v[i][j].second;
            if(a == 0){ // 右向き
                if(j == sz-1){ // 右にいない
                    chmin(len[a], W-1-x);
                    continue;
                }
                int y = v[i][j+1].first;
                int b = v[i][j+1].second;
                if(a == b){
                    cnt[a] += y - x - 1;
                }
                else{
                    
                }
            }
        }
    }
}
