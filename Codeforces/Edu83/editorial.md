
参加しました。


[:contents]

### [A Two Regular Polygons](https://codeforces.com/contest/1312/problem/A)
#### 解説

- `N % M == 0`

#### 提出

```cpp

#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


void solve(){
    int n,m;
    cin>>n>>m;
    cout<<((n % m == 0) ? YES:NO)<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin>>Q;
    while(Q--){
        solve();
    }
}

```

### [B Bogosort](https://codeforces.com/contest/1312/problem/B)

#### 解説

降順にソートすれば題意を満たす数列になります。

#### 提出

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

void solve(){
    int N;
    cin>>N;
    vector<int> a(N);
    rep(i,N){
        cin>>a[i];
    }
    sort(all(a));
    reverse(all(a));
    rep(i,N){
        cout<<a[i];
        if(i == N-1)cout<<'\n';
        else cout<<" ";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
```
### [C Adding Powers](https://codeforces.com/contest/1312/problem/C)

#### 解説
これかなり悩んだけど、コンテスト中に発明した方法はK進数にする操作に対応していた。なんで思いつかなかったのだろう。

要素がK進数において0と1のみで構成され、その桁の被りがないことが条件です。

#### 提出
```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define YES "YES"
#define NO "NO"
typedef long long ll;

void solve(){
    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    vector<int> beki(60);
    bool ok = true;
    //k進数に変換する
    rep(i,N){
        cin>>A[i];
        int cnt = 0;
        while(A[i] > 0){
            if(A[i] % K > 1){
                ok = false;
            }
            if(A[i] % K == 1){
                beki[cnt]++;
            }
            A[i] /= K;
            cnt++;
        }
    }
    rep(i,60){
        if(beki[i] > 1){
            ok = false;
        }
    }
    cout<<(ok ? YES : NO)<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;

    cin>>q;
    while(q--){
        solve();
    }
}

```

### [D Count the Arrays](https://codeforces.com/contest/1312/problem/D)
#### 解説
- コンテスト中に考えたこと

`O(NM)`ならできるなあ（それはそう）
最大値とその置く場所を全探索し、左右をいい感じに割り当てればよいと思った


- コンテスト後

最大値を全探索はするが、位置は全探索しないでよい。
というのも、最大値の左右に数字を割り当てることを考えればよいからである。

最大値をkとすると

- k-1個の数字から左右にペアになるように割り振る数字を選ぶ（k-1通り）
    - ペアの数字は割り振る必要がない
- 残りのk-2通りから埋まっていない要素数n-3通りを選ぶ（`k-2Cn-3`通り)
- それぞれの数字を左右どちらに割り振るかがあるので`2^n-3`通り。

これを全てのk(1 ~ M)について足し合わせればよい。

`O(M)`。

#### 提出

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
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
};
struct combination {
    vector<mint> fact, ifact;
    //constructor(initiation)
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint Comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
    mint H(int n, int m){
        return Comb(n + m - 1, m);
    }
};
combination Comb(1e6);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N,M;
    cin>>N>>M;
    if(N == 2){
        cout<<0<<endl;
        return 0;
    }
    mint ans = 0;
    //極大値mを全探索両端の状態は何かしらで計算できそう
    //両端の状態を別に扱う必要がなかった、右が左に割り当てればよい
    for(int k = 2; k <= M; ++k){
        mint tmp = (k-1);
        tmp *= Comb.Comb(k-2, N-3);
        tmp *= mint(2).modpow(N-3);
        ans += tmp;
    }
    cout<<ans.x<<endl;
}
```