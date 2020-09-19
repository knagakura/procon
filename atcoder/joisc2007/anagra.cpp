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

string S, T;
int N;
vector<int> used;
vector<ll> fact;
map<char,int> mp;
map<string, int> mp_st;
ll ans;
int check(string &tmp){
    int M = tmp.size();
    if(S[M-1] > tmp[M-1])return 0;
    else if(S[M-1] == tmp[M-1])return 1;
    else return 2;
}

ll calc(string &tmp){
    ll res = 1;
    auto mptmp = mp;
    for(auto c: tmp)mptmp[c]--;
    ll cnt = 0;
    for(auto p: mptmp)cnt += p.second;
    res *= fact[cnt];
    for(auto p: mptmp){
        res /= fact[p.second];
    }
    return res;
}
void dfs(string &tmp){
    if(mp_st[tmp] > 0)return;
    mp_st[tmp]++;
    int type = check(tmp);
    if(type == 0){ // 小さいことが確定したら、その後どう並べても小さいので、そこの場合の数を足す
        ans += calc(tmp);
        return;
    }
    if(type == 2)return; // 大きくなったら探索を終える（数える意味がないので）
    if((int)tmp.size() == N){
        dump(tmp);
        return;
    }
    rep(i,N){
        if(used[i])continue;
        tmp.push_back(T[i]);
        used[i] = true;
        dfs(tmp);
        tmp.pop_back();
        used[i] = false;
    }
}
int main() {
    cin >> S;
    T = S;
    N = S.size();
    used.assign(N, false);
    fact.resize(N+1);
    fact[0] = 1;
    rep(i,N){
        fact[i+1] = fact[i] * (i+1);
    }
    dump(fact);
    sort(all(T));
    rep(i,N)mp[S[i]]++;
    dump(T);
    dump(S);
    ans = 0;
    string tmp;
    dfs(tmp);
    cout << ans+1 << endl;
}
