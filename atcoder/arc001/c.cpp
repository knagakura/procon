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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int H = 8;
const int W = 8;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
vvec<i_i> unused;
vec<i_i> dfs(int s, int d, vec<i_i> &v){
    print(v);
    if(v.size() == 5){
        return v;
    }
    for(int i = 0; i < unused[d].size();i++){
        v.push_back(unused[d][i]);
        dfs(s, d+1, v);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vec<string> S(H);
    vvec<bool> used(H,vec<bool>(W,false));
    rep(i,H)cin >> S[i];

    auto check = [&](int x, int y) -> bool{
        used[x][y] = true;
        rep(k,8){
            int nx = x + dx[k];
            int ny = y + dy[k];
            while(IsIn(nx,ny)){
                if(S[nx][ny] == 'Q'){
                    return true;
                }
                used[nx][ny] = true;
                nx += dx[k];
                ny += dy[k];
            }
        }
        return false;
    };
    rep(i,H)rep(j,W){
        if(S[i][j] == 'Q'){
            if(check(i,j)){
                cout << "No Answer" << endl;
                return 0;
            }
        }
    }
    rep(i,H)print(used[i]);
    rep(i,H){
        vec<i_i> tmp;
        rep(j,W){
            if(not used[i][j])tmp.push_back({i,j});
        }
        if(tmp.size())unused.push_back(tmp);
    }
    for(auto &v:unused)print(v);
    /*
    for(int i = 0; i < unused[0].size(); i++){
        vec<i_i> v;
        v.push_back(unused[0][i]);
        auto x = dfs(i, 0, v);
        print(x);
    }*/
    rep(i,H){
        cout << S[i] << endl;
    }
}