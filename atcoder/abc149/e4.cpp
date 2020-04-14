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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    // X以上のものだけを使ったときの個数がM以下か
    auto check = [&](ll X){
        ll cnt = 0;
        rep(i,N){
            int add = A.end() - lower_bound(all(A), X - A[i]);
            cnt += add;
        }
        return cnt < M;
    };
    ll ng = 0;
    ll ok = INFLL;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cerr << ng << " " << ok << endl;
    //累積和で高速化パート
    vec<ll> cum(N+1, 0);
    rep(i, N)cum[i+1] = cum[i] + A[i];
    //ok以上のものだけ使えばM個以内に収まる
    //ngを何個か入れることを考える
    //ngが入る余地があるときがある
    //ok以上でM以下だが、Mピッタリとは限らない
    //ngにすると超えるということである。
    //余りがあるはずなので、それを加えよう。
    ll ans = 0;
    rep(i,N){
        int idx = lower_bound(all(A), ok - A[i]) - A.begin();
        int cnt = N - idx;
        ans += cum[N] - cum[idx] + A[i] * cnt;
        M -= cnt;
    }
    ans += M * (ok - 1);
    cout << ans << endl;
}