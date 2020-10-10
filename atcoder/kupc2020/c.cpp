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
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


int main() {
    const int N = 13;
    map<string, int> mp;
    vvec<char> c(N,vec<char>(N, '?'));
    auto IsIn = [&](int i,int j) -> bool{
        return 0 <= i && i < N && 0 <= j && j < N;
    };
    // priority_queue<
    //     pair<int, char>,
    //     vector<pair<int, char>>,
    //     greater<>()
    //     > pq;
    // rep(l,26){
    //     pq.push(make_pair(0, char('a'+l)));
    // }
    vector<int> cnt(26, 0); // その文字が先頭のやつが何回使われたか
    c[0][0] = 'a';
    rep(i,N)rep(j,N){
        // c[i][j] = lにしたときに、両方まだ出ていないか
        if(i == 0 && j == 0)continue;
        int minn = INF;
        int to = -1;
        vector<string> tmps_s;
        rep(l,26){
            int ok = 0;
            vector<string> tmps;
            rep(k,2){
                int nx = i - dx[k];
                int ny = j - dy[k];
                if(not IsIn(nx, ny)){
                    ok++;
                    continue;
                }
                string tmp;
                tmp.push_back(c[nx][ny]);
                tmp.push_back(char('a' + l));
                if(mp.count(tmp) <= 0){
                    ok++;
                    tmps.push_back(tmp);
                }
            }
            if(ok == 2){
                if(chmin(minn, cnt[l])){
                    to = l;
                    swap(tmps_s, tmps);
                }
                // for(auto &tmp: tmps)mp[tmp]++;
                // c[i][j] = char('a' + l);
                // break;
            }
        }
        if(to == -1){
            dump(i, j);
        }
        else{
            for(auto &tmp: tmps_s){
                mp[tmp]++;
                cnt[tmp[0] - 'a']++;
                c[i][j] = char('a' + to);
            }
        }
    }
    dump(mp);
    dump(mp.size());
    cout << N << endl;
    rep(i,N)rep(j,N){
        cout << c[i][j];
        if(j == N-1)cout << endl;
    }
}
