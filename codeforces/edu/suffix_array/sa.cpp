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

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


int main() {
    string S;
    cin >> S;
    S.push_back('$');
    int N = S.size();
    S += S;
    int beki = 1;
    while(beki < N)beki *= 2;
    vector<int> res(N), sya(N);
    rep(i,N)res[i] = i;
    auto calc = [&](int k) -> void{
        // 最初は単純にソートするだけ
        // 同じものは同じと判定したい
        if(k == 0){
            sort(all(res), [&](int a, int b){
                return S[a] < S[b];
            });
            sya[res[0]] = 0;
            int num = 0;
            rep1(i,N){
                if(S[res[i-1]] == S[res[i]])sya[res[i]] = num;
                else sya[res[i]] = ++num;
            }
            return;
        }
        auto r_idx = [&](int idx) -> int{
            return (idx + bit(k-1)) % N;
        };
        // i回目(i >= 1)はi-1回目を活用する
        // res2の構築
        vector<int> res2(N), sya2(N);
        rep(i,N)res2[i] = i;
        sort(all(res2), [&](int a, int b){
            if(sya[a] == sya[b])return sya[r_idx(a)] < sya[r_idx(b)];
            return sya[a] < sya[b];
        });
        // sya2の構築
        sya2[res2[0]] = 0;
        int num = 0;
        rep1(i,N){
            if(sya[res2[i-1]] == sya[res2[i]] && 
            sya[r_idx(res2[i-1])] == sya[r_idx(res2[i])]){
                sya2[res2[i]] = num;
            }
            else sya2[res2[i]] = ++num;
        }
        swap(res, res2);
        swap(sya, sya2);
    };
    // O(logN)
    for(int k = 0; bit(k) <= beki; k++){
        calc(k); // O(NlogN)
    }
    rep(i,N){
        cout << res[i] << (i == N-1 ? "\n": " ");
    }
}
