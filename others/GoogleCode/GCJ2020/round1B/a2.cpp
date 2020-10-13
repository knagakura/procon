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

void Case(int t){
    cout << "Case #" << t << ": ";
}

void solve(){
    ll x, y;
    cin >> x >> y;
    ll ax = abs(x);
    ll ay = abs(y);
    if(ax % 2 == ay % 2){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    //偶奇が異なる
    string ans[] = {"",""};
    string dx = "WE";
    string dy = "SN";
    bool swaped = false;
    if(ax % 2 == 1 && ay % 2 == 0){
        swap(ax, ay);
        swap(x, y);
        swaped = true;
    }
    //偶数、奇数の順
    vec<bool> ng(2, false);
    //ax, ay
    rep(d,2)for(int i = 0; i <= 62;i++){
        if(bit(i) > ax && bit(i) > ay + d)break;
        if(d && i == 0){
            ans[d].push_back('S');
            continue;
        }
        if((bit(i)&ax) == (bit(i)&(ay+d))){
            ng[d] = true;
            ans[d] = "";
            break;
        }
        if((bit(i)&ax)){
            ans[d].push_back(dx[1]);
        }
        else if((bit(i)&(ay+d))){
            ans[d].push_back(dy[1]);
        }
        else{
            ng[d] = true;
            break;
        }
    }
    if(ng[0] && ng[1]) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    rep(d,2){
        int sz = ans[d].size();
        if(x < 0){
            rep(i,sz){
                if(ans[d][i] == 'E')ans[d][i] = 'W';
                else if(ans[d][i] == 'W')ans[d][i] = 'E';
            }
        }
        if(y < 0){
            rep(i,sz){
                if(ans[d][i] == 'N')ans[d][i] = 'S';
                else if(ans[d][i] == 'S')ans[d][i] = 'N';
            }
        }
        if(swaped){
            rep(i,sz){
                if(ans[d][i] == 'E')ans[d][i] = 'N';
                else if(ans[d][i] =='W')ans[d][i] = 'S';
                else if(ans[d][i] == 'N')ans[d][i] = 'E';
                else if(ans[d][i] == 'S')ans[d][i] = 'W';
            }
        }
    }
    string res = ans[1];
    if(!(ng[0])){
        res = ans[0];
        if(!ng[1] && ans[0].size() > ans[1].size()){
            res = ans[1];
        }
    }
    cout << res << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        Case(i);
        solve();
    }
}