#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    vector<i_i> v(N*M+1,{-1,-1});
    bool ok = true;
    rep(i,N){
        cin >> A[i];
        if(v[A[i]].first != -1)ok = false;
        v[A[i]].first = i;
    }
    rep(j,M){
        cin >> B[j];
        if(v[B[j]].second != -1)ok = false;
        v[B[j]].second = j;
    }
    if(!ok){
        puts("0");
        return 0;
    }
    //print(v);
    //N*Mから決めていく
    mint ans = 1;
    if(v[N*M].first == -1 || v[N*M].second == -1)ans = 0;
    //iより大きい数で埋まっている行, 列の数
    ll cnt[2] = {1,1};
    //iより大きい数で埋まっている行列の交差している座標の数
    ll cnt_cross = 0;
    //i未満の数が最大にならなければならないがために埋められない行、列の数
    for(ll i = N * M - 1; i >= 1; i--){
        /*
        dump(i);
        dump(v[i]);
        dump(ans);
        dump(cnt_cross);
        print(cnt);
        cerr << endl;
        */
        //{-1, -1}
        if(v[i].first == -1 && v[i].second == -1){
            ans *= cnt_cross;
            cnt_cross--;
            continue;
        }
        //{-1, X}
        if(v[i].first == -1 && v[i].second >= 0){
            ans *= cnt[0];
            cnt_cross += cnt[0]-1;
            cnt[1]++;
            continue;
        }
        //{X, -1}
        if(v[i].first >=  0 && v[i].second == -1){
            ans *= cnt[1];
            cnt_cross += cnt[1]-1;
            cnt[0]++;
            continue;
        }
        //{X, X} OK
        if(v[i].first >= 0 && v[i].second >= 0){
            cnt_cross += cnt[0] + cnt[1];
            cnt[0]++;
            cnt[1]++;
            continue;
        }
    }
    cout << ans << endl;
}
