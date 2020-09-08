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
int N, K;
string S;
bool ok;
void calc(string &X){
    int M = N-K+1;
    vector<int> a(M,0), b(M,0), c(M,0);
    rep(i,M){
        string tmp = X.substr(i,K);
        rep(j,K){
            a[i] += tmp[j] == '1';
            b[i] += tmp[j] == '0';
            c[i] += tmp[j] == '?';
        }
    }
    cerr << endl;
    dump(K,X);
    dump(a);
    dump(b);
    dump(c);
    // すでに超えてたら無理、逆にどちらも以下なら可能な可能性がある
    rep(i,M){
        if(a[i] > K/2 || b[i] > K/2){
            ok = false;
            return;
        }
    }
    // 最初の配置
    vector<int> zero(M, -1), one(M, -1);
    zero[0] = K/2 - b[0];
    one[0] = K/2 - a[0];
    string Y = X;
    rep(i,M-1){
        char pre = Y[i];
        char nxt = Y[i+K];
        dump(pre, nxt);
        if(pre == nxt){
            zero[i+1] = zero[i];
            one[i+1] = one[i];
            continue;
        }
        if(pre == '?'){
            if(nxt == '0'){
                if(zero[i] > 0){
                    Y[i] = '0';
                    zero[i+1] = zero[i] - 1;
                    one[i+1] = one[i];
                }
                else{
                    ok = false;
                    break;
                }
            }
            if(nxt == '1'){
                if(one[i] > 0){
                    Y[i] = '1';
                    one[i+1] = one[i] - 1;
                    zero[i+1] = zero[i];
                }
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(nxt == '?'){
            if(pre == '1'){
                one[i+1] = one[i] + 1;
                zero[i+1] = zero[i];
                Y[i+K] = '1';
            }
            else{
                one[i+1] = one[i];
                zero[i+1] = zero[i] + 1;
                Y[i+K] = '0';
            }
        }
        if(pre == '0' && nxt == '1'){
            if(b[i+1] + zero[i] != a[i+1] + one[i]){
                ok = false;
            }
            else{
                zero[i+1] = zero[i];
                one[i+1] = one[i];
            }
        }
        if(pre == '1' && nxt == '0'){
            if(b[i+1] + zero[i] != a[i+1] + one[i]){
                ok = false;
            }
            else{
                zero[i+1] = zero[i];
                one[i+1] = one[i];
            }
        }
        if(zero[i] == 0){
            for(int j = i; j < i + K; j++){
                if(Y[j] == '?')Y[j] = '1';
            }
        }
        if(one[i] == 0){
            for(int j = i; j < i + K; j++){
                if(Y[j] == '?')Y[j] = '0';
            }
        }
        if(zero[i+1] == 0){
            for(int j = i+1; j < i+1 + K; j++){
                if(Y[j] == '?')Y[j] = '1';
            }
        }
        if(one[i+1] == 0){
            for(int j = i+1; j < i+1 + K; j++){
                if(Y[j] == '?')Y[j] = '0';
            }
        }
    }
    dump(a);
    dump(b);
    dump(one);
    dump(zero);
    dump(X, Y, ok);
    if(X != Y)calc(Y);
};
void solve(){
    cin >> N >> K >> S;
    ok = true;
    calc(S);
    cout << (ok ? "YES" : "NO" ) << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}

/*

7 4
1?0??1?
*/
