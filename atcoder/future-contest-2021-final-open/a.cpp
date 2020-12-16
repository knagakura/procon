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

const int INF = (ll)1e6;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

constexpr double TL = 1.95;
constexpr long long CYCLES_PER_SEC = 2800000000;
struct MyTimer {
    long long start;
    MyTimer() { reset(); }
    void reset() { start = getCycle(); }
    inline double get() { return (double) (getCycle() - start) / CYCLES_PER_SEC; }
    inline long long getCycle() {
        unsigned low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((long long) low) | ((long long) high << 32);
    }
};
uint32_t XorShift(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;
 
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
// 定数
constexpr int H = 50;
constexpr int W = 50;
int C;
int p[5][H][W];
bool IsIn(int i,int j){
    return 0 <= i && i < H && 0 <= j && j < W;
};
int dist(const pair<int,int> &a, const pair<int, int> &b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
struct Status{
    int cnt[H][W];
    bool visited[H][W];
    vector<pair<int,int>> ans;
    Status(){
        rep(i,H)rep(j,W){
            cnt[i][j] = 0;
            rep(k,4){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(not IsIn(nx, ny)){
                    cnt[i][j]++;
                }
                else if(visited[nx][ny]){
                    cnt[i][j]++;
                }
            }
        }
    }
    void out(){
        cout << ans.size() << endl;
        for(auto &pp: ans){
            cout << pp.first << " " << pp.second << endl;
        }
    }
    void donyoku(){
        vector<pair<int, pair<int, int>>> v;
        rep(i,H){
            rep(j,W){
                v.push_back({p[0][i][j], {i,j}});
            }
        }
        sort(all(v));
        reverse(all(v));
        rep(i,50){
            auto cost = v[i].first;
            auto tar = v[i].second;
            auto [x, y] = tar;
            if(visited[x][y])continue;
            if(cost < 500)break;
            pair<int,int> a[4] = {
                {0, y},
                {H-1, y},
                {x, 0},
                {x, W-1}
                };
            int startIdx = 0;
            int minCost = INF;
            rep(j,4){
                if(chmin(minCost, dist(a[j], tar))){
                    startIdx = j;
                }
            }
            auto st = a[startIdx];
            for(auto &pp: ans){
                if(chmin(minCost, dist(pp, tar))){
                    st = pp;
                }
            }
            if(not visited[st.first][st.second]){
                visited[st.first][st.second] = true;
                ans.emplace_back(st);
            }
            while(st != tar){
                rep(j,4){
                    pair<int, int> nxt = {st.first+dx[j], st.second+dy[j]};
                    if(not IsIn(nxt.first, nxt.second))continue;
                    if(dist(nxt, tar) < dist(st, tar)){
                        if(not visited[nxt.first][nxt.second]){
                            ans.push_back(nxt);
                            visited[nxt.first][nxt.second] = true;
                        }
                        swap(nxt, st);
                        break;
                    }
                }
            }
            rep(j,8){
                int nx = tar.first + dx[j];
                int ny = tar.second + dy[j];
                if(not IsIn(nx, ny))continue;
                if(p[0][nx][ny] < 500)continue;
                bool ok = false;
                rep(k,4){
                    int nnx = nx+dx[k];
                    int nny = ny+dy[k];
                    if(not IsIn(nnx, nny)){
                        ok = true;
                    }
                    if(visited[nnx][nny]){
                        ok = true;
                    }
                }
                if(not ok)continue;
                if(not visited[nx][ny]){
                    ans.emplace_back(nx, ny);
                    visited[nx][ny] = true;
                }
            }
            priority_queue<pair<int, pair<int, int>>> pq;
            auto nxtPush = [&](int x, int y){
                rep(j,4){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(not IsIn(nx, ny))continue;
                    if(visited[nx][ny])continue;
                    int cnt = 0;
                    rep(k,4){
                        int nnx = nx + dx[k];
                        int nny = ny + dy[k];
                        if(not IsIn(nnx, nny))cnt++;
                        else if(visited[nnx][nny])cnt++;
                    }
                    if(cnt == 0)continue;
                    pq.push({p[cnt][nx][ny], {nx, ny}});
                }
            };
            for(const auto &pp: ans){
                auto [x, y] = pp;
                nxtPush(x, y);
            }
            while(not pq.empty()){
                auto topp = pq.top();
                pq.pop();
                int cost = topp.first;
                auto [x, y] = topp.second;
                if(cost > 0){
                    if(not visited[x][y]){
                        ans.emplace_back(x, y);
                        visited[x][y] = true;
                        nxtPush(x, y);
                    }
                }
            }
        }
    }
};
Status aStatus;
void in(){
    cin >> C;
    rep(i,H)rep(j,W){
        int tmp;
        cin >> tmp;
        p[0][i][j] = tmp;
        for(int k = 1; k <= 4; k++){
            p[k][i][j] = tmp - C / k;
        }
    }
}
int main() {
    in();
    aStatus.donyoku();
    aStatus.out();
}
