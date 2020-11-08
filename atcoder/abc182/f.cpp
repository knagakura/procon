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
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    while(A.back() < X){
        A.emplace_back(A.back() + A[N-1]);;
    }
    auto fa = factorize(A.back());
    vector<ll> z;
    z.emplace_back(0);
    int szz = A.size();
    rep(i,szz)rep(j,szz){
        if(i >= j)continue;
        z.emplace_back(abs(A[j] - A[i]));
        z.emplace_back(abs(A[j] + A[i]));
    }
    rep(i,N+1)z.emplace_back(A[i]);
    for(auto p: fa)z.emplace_back(p.first);
    dump(z);
    ll ans = 0;
    auto calc = [N, A](ll a) -> map<ll, int>{
        map<ll,int> mp;
        int idx = N-1;
        while(a > 0){
            // dump(a, A[idx]);
            if(a >= A[idx]){
                a %= A[idx];
                mp[A[idx]]++;
            }
            idx--;
        }
        return mp;
    };
    auto check = [calc](ll z, ll y) -> bool{
        bool ok = true;
        map<ll, int> mpz, mpy;
        mpz = calc(z);
        mpy = calc(y);
        for(auto [val, cnt]: mpz){
            if(mpy.count(val))ok = false;
        }
        return ok;
    };
    int sz = z.size();
    map<pair<ll, ll>, int> mpis;
    rep(i,sz){
        ll zz = z[i];
        ll y = zz + X;
        dump(zz, y);
        if(mpis.count({zz, y}))continue;
        if(check(zz, y)){
            dump("Ok");
            ans++;
        }
        mpis[{zz, y}]++;
        if(zz - X > 0){
            ll zzz = zz - X;
            ll yy = zz;
            if(mpis.count({zzz, yy}))continue;
            if(check(zzz, yy)){
                ans++;
            }
            mpis[{zzz, yy}]++;
        }
    }
    cout << ans << endl;
}

/*

重要な考察として、最小枚数を達成するためには、上から貪欲に払っていく必要があります。

y-x = zとすると、x円払うのと、z円払うので同じコインを使わない選択肢となります。
また、xは固定なので、zを先に決めれば、y = z + x、つまり幅が同じx固定で動いていくということになります
*/