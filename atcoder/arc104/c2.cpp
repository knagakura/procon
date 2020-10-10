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
    int N;
    cin >> N;
    vector<ll> cnt(2*N, 0);
    int free = 0;
    bool ok = true;
    vector<int> A(N), B(N);
    map<int, int> to_r, to_l;
    rep(i,2*N)to_r[i] = to_l[i] = INF;
    rep(i,N)cin >> A[i] >> B[i];
    rep(i,N){
        if(A[i] > 0 && B[i] > 0){
            A[i]--;
            B[i]--;
            cnt[A[i]]++;
            cnt[B[i]]++;
            to_r[A[i]] = B[i];
            to_l[B[i]] = A[i];
        }
        if(A[i] > 0 && B[i] == -1){
            A[i]--;
            cnt[A[i]]++;
            to_r[A[i]] = B[i];
        }
        if(A[i] == -1 && B[i] > 0){
            B[i]--;
            cnt[B[i]]++;
            to_l[B[i]] = -1;
        }
        if(A[i] == -1 && B[i] == -1){
            free += 2;
        }
    }
    dump(to_r);
    dump(to_l);
    rep(i,2*N){
        if(cnt[i] >= 2)ok = false;
    }
    rep(i,N){
        if(A[i] >= 0 && B[i] >= 0){
            int len = B[i] - A[i] - 1;
            if(len < 0)ok = false;
            for(int l = A[i]+1; l < B[i]; l++){
                int r = l + len + 1;
                if(to_r[l] == INF){
                    to_r[l] = r;
                    to_l[r] = l;
                }
                if(to_r[l] != r){
                    if(to_r[l] == -1){
                        to_r[l] = r;
                        to_l[r] = l;
                    }
                    else ok = false;
                }
            }
        }
    }
    rep(i,N){
        if(A[i] >= 0 && B[i] >= 0){
            int len = B[i] - A[i];
            for(int r = B[i]-1; r > A[i]; r--){
                int l = r - len;
                if(to_l[r] == INF){ // 左端が指定されていない
                    to_l[r] = l;
                    to_r[l] = r;
                }
                if(to_l[r] != l){
                    if(to_l[r] == -1){
                        to_l[r] = l;
                        to_r[l] = r;
                    }
                    else ok = false;
                }
            }
        }
    }
    set<int> st;
    for(auto [l, r]: to_r){
        if(l < INF && l >= 0)st.insert(l);
        if(r < INF && r >= 0)st.insert(r);
    }
    for(auto [r, l]: to_l){
        if(l < INF && l >= 0)st.insert(l);
        if(r < INF && r >= 0)st.insert(r);
    }
    set<int> stt;
    rep(i,2*N){
        if(st.find(i) == st.end())stt.insert(i);
    }
    dump(st);
    dump(stt);
    rep(i,N){
        if(to_r[A[i]] == INF){
            auto itr = stt.lower_bound(A[i]);
            if(itr != stt.end())stt.erase(itr);
            else ok = false;
        }
        if(to_l[B[i]] == INF){
            auto itr = stt.lower_bound(A[i]);
            if(itr != stt.begin()){
                stt.erase(--itr);
            }
            else ok = false;
        }
    }
    cout << ((ok ? "Yes" : "No")) << endl;
}
