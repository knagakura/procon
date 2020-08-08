#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

const ll MOD = 1000000007;

struct mint {
    long long x;
    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint modpow(long long t) const {
        if (!t) return 1;
        mint a = modpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return modpow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};

// mint dp[200010];

template<typename T>
class LazySegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    vector<T> lazy;//遅延評価
    void _add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += x * (r - l);
            eval(k, l, r);
        }
        else{
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }
    }
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return c1 + c2;
    }
    //コンストラクター
    LazySegTree(vector<T> v){
        int sz = v.size();
        N = 1;
        while(N < sz)N *= 2;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];
        for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];
    }
    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k].x == 0)return;
        data[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x){
        _add(a, b, x, 0, 0, N);
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};

ll N,M;
// void debug(){
//     rep(i,N+1)cerr << dp[i] << " ";
//     cerr << endl;
// }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<ll> f(N);
    rep(i, N)cin >> f[i];
    vector<ll> cnt(M+1,0);
    vector<mint> dp(N+1,0);
    dp[0] = 1;
    LazySegTree<mint> Seg(dp);
    int r = 0;
    for(int l = 0; l < N; l++){
        while(r < N){
            if(cnt[f[r]] > 0)break;
            cnt[f[r]]++;
            r++;
        }
        // 区間に足し算
        // [l,r)にdp[l]を足し算
        /*
        for(int i = l; i < r; i++){
            dp[i+1] += dp[l];
        }*/
        mint add = Seg.query(l,l+1);
        Seg.add(l+1,r+1,add);
        if(l == r)r++;
        else {
            cnt[f[l]]--;
        }
        // rep(i,N+1){
        //     cerr << Seg[i] << " ";
        // }
        // cerr << endl;
    }
    cout << Seg.query(N,N+1) << endl;
}