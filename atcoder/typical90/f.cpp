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
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    string ans;
    rep(i,K+1)ans.push_back('-');
    // ans[j]をS[i]に変えてもansがK文字満たすことができるか判定する
    // iのとき、残りN-1-i文字ある
    // ans[j]を変更するとき、残り必要なのはK-1-j
    vector<int> alpha_min_idx(26, INF);
    int ansSz = -1;
    rep(i,N){
        int alphaIdx = S[i]-'a';
        int change_idx = ansSz+1;
        rep(j,26){
            if(alpha_min_idx[j] == INF)continue;
            if(ans[alpha_min_idx[j]] != char('a' + j)){
                alpha_min_idx[j] = INF;
            }
            if(alpha_min_idx[j] > ansSz){
                alpha_min_idx[j] = INF;
            }
        }
        for(int j = alphaIdx+1; j < 26; j++){
            if(alpha_min_idx[j] == INF)continue;
            if(N-1-i >= K-1-alpha_min_idx[j]){
                chmin(change_idx, alpha_min_idx[j]);
            }
        }
        ans[change_idx] = S[i];
        chmin(alpha_min_idx[S[i]-'a'], change_idx);
        ansSz = change_idx;
        dump(i, ans, ansSz);
        dump(alpha_min_idx);
        dump(change_idx);
    }
    while(ans.size() > K){
        ans.pop_back();
    }
    cout << ans << endl;
}
