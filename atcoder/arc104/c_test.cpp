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

bool Mysolve(vector<int> &A, vector<int> &B){
    int N = A.size();
vector<ll> cnt(2*N, 0);
    int free = 0;
    bool ok = true;
    // vector<int> A(N), B(N);
    map<int, int> to_r, to_l;
    rep(i,2*N)to_r[i] = to_l[i] = INF;
    // rep(i,N)cin >> A[i] >> B[i];
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
    // dump(to_r);
    // dump(to_l);
    rep(i,N){
        if(A[i] >= 0 && B[i] >= 0){
            int len = B[i] - A[i] - 1;
            if(len < 0)ok = false;
            for(int l = A[i]+1; l < B[i]; l++){
                int r = l + len + 1;
                if(to_r[l] == INF)continue; //左端が固定されていない
                if(to_r[l] != r){
                    if(to_r[l] == -1){
                        to_r[l] = r;
                        to_l[r] = A[i];
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
                if(to_l[r] == INF)continue; //左端が固定されていない
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
    return ok;
    // cout << ((ok ? "Yes" : "No")) << endl;
}
int main() {
    int N;
    cin >> N;
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    auto inter = [&](int a, int b, int l, int r) -> bool{
        if(a > l){
            swap(a, l);
            swap(b, r);
        }
        return b > l;
    };
    auto check = [&](vector<int>&a, vector<int> &b) -> bool{
        vector<int> c(N);
        rep(i,N){
            c[i] = b[i] - a[i] - 1;
            if(c[i] < 0)return false;
        }
        rep(j,N)rep(i,j){
            if(inter(a[i],b[i],a[j],b[j])){
                if(c[i] != c[j])return false;
            }
        }
        return true;
    };
    vector<int> v;
    rep(i,2*N)v.emplace_back(i);
    map<vector<pair<int,int>>,int> mp;
    map<vector<int>, int> mp_c;
    int cnt = 0;
    do{
        vector<int> A(N), B(N), C(N);
        vector<pair<int, int>> vp;
        bool ok = true;
        rep(i,N){
            A[i] = v[2*i];
            B[i] = v[2*i+1];
            C[i] = B[i] - A[i] - 1;
            if(B[i] <= A[i])ok = false;
            vp.emplace_back(A[i], B[i]);
        }
        if(not ok)continue;
        sort(all(vp));
        sort(all(C));
        if(mp[vp] > 0)continue;
        if(mp_c[C])continue;
        mp[vp]++;
        mp_c[C]++;
        auto a = check(A, B);
        auto b = Mysolve(A, B);
        if(a != b){
            cerr << "dame" << endl;
            return 0;
        }
        if(check(A, B)){
            cnt++;
            dump(v);
            dbg("OK");
            dump(A);
            dump(B);
            dump(C);
        }
        // else dbg("NG");
        // cerr << endl;
    }while(next_permutation(all(v)));
    dump(cnt);
}
