#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


int main() {
    ll sx, sy;
    ll gx, gy;
    cin >> sx >> sy >> gx >> gy;
    if(sx == gx && sy == gy){
        cout << 0 << endl;
    }
    // 最初の1手で距離3以内にいく
    else if(abs(sx-gy) + abs(sy - gy) <= 3){
        cout << 1 << endl;
    }
    // 最初の1手で斜めに行ける
    else if(sx + sy == gx + gy || sx - sy == gx - gy){
        cout << 1 << endl;
    }
    // これでいけないなら2手以上
    // 両方long move
    else if((sx + sy + gx + gy) % 2 == 0){
        cout << 2 << endl;
    }
    // 片方long, もう片方shortのとき、先にshortをやると確定させて良い
    // else{
    //     bool ok = false;
    //     for(int dx = -3; dx <= 3; dx++){
    //         for(int dy = -3; dy <= 3; dy++){
    //             if(abs(dx) + abs(dy) > 3)continue;
    //             int nx = dx + sx;
    //             int ny = dy + sy;
    //             dump(nx, ny);
    //             if(abs(nx-gx) + abs(ny-gy) <= 3)ok = true;
    //             if(nx + ny == gx + gy || nx - ny == gx - gy)ok = true;
    //         }
    //     }
    //     if(ok){
    //         cout << 2 << endl;
    //     }
    //     else{
    //         cout << 3 << endl;
    //     }
    // }

    else if(abs(sx-gx) + abs(sy-gy) <= 6){
        cout << 2 << endl;
    }
    else if(abs((sx+sy)-(gx+gy)) <= 3){
        cout << 2 << endl;
    }
    else if(abs((sx-sy)-(gx-gy)) <= 3){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }
}
