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
 
bool solve(vector<int> &A, vector<int>&B ){
    int N = A.size();
    vector<int> ans;
    multiset<int> st;
    rep(i,N)st.insert(B[i]);
    rep(i,N){
        auto it = st.upper_bound(A[i]);
        if(it == st.end())it = st.begin();
        ans.emplace_back(*it);
        st.erase(it);
    }
    // dump(ans);
    rep(i,N){
        if(ans[i] == A[i]){
            return false;
            // cout << "No" << endl;
            // return 0;
        }
    }
    return true;
    // cout << "Yes" << endl;
    // rep(i,N){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
}
int main() {
    int N = 10;
    ll cnt = 0;
    while(1){
        cnt++;
        vector<int> A(N), B(N);
        rep(i,N){
            A[i] = XorShift() % N + 1;
            B[i] = XorShift() % N + 1;
        }
        sort(all(A));
        sort(all(B));
        map<int, int> mpa, mpb;
        rep(i,N){
            mpa[A[i]]++;
            mpb[B[i]]++;
        }
        bool ok = true;
        for(int i = 1; i <= N; i++){
            ll cnta = mpa[i];
            ll cntb = mpb[i];
            if(cnta + cntb > N){
                ok = false;
            }
        }
        if(solve(A, B) != ok){
            dump(A);
            dump(B);
            break;
        }
        if(cnt % 100 == 0){
            dump(cnt);
        }
    }
    
}
