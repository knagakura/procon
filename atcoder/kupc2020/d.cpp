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
template<typename T>
vector<T> divisor(T N) {
    vector<T> res;
    for(T i = 1; i * i <= N; i++){
        if(N % i == 0){
            res.push_back(i);
            if(i * i != N)res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N;
    cin >> N;
    if(N == 2 || N == 3){
        cout << "impossible" << endl;
        return 0;
    }
    vector<ll> a;
    rep(i,N){
        a.push_back(i*2+1);
    }
    if(N % 2 == 0){
        cout << N / 2 << endl;
        rep(i,N/2){
            cout << 2 << " " << a[i] << " " << a[N-1-i] << endl;
        }
        return 0;
    }
    cout << "impossible" << endl;
    ll sum = SUM(a);
    if(a.size() <= 50){
        dump(a);
    }
    dump(sum);
    auto divs = divisor(sum);
    dump(divs);
    for(auto div: divs){
        rep(i,N)a[i] -= div;
        dump(div);
        dump(a);
        rep(i,N)a[i] /= 2;
        dump(a);
        rep(i,N)a[i] *= 2;
        rep(i,N)a[i] += div;
        dump(a);
    }
}
