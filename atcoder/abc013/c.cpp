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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    // Eの日数を二分探索
    // ll ok = -1, ng = N+1;
    // ll ans = INFLL;
    // // X回
    // auto check = [&](ll X) -> bool{
    //     ll rem = N - X;
    //     bool res = false;
    //     for(ll i = 0; i <= rem; i++){
    //         ll j = rem - i;
    //         // cerr << i << " " << j << endl;
    //         ll sumC = 0;
    //         sumC += i * A;
    //         sumC += j * C;
    //         ll sumH = H;
    //         sumH -= E * X;
    //         sumH += i * B;
    //         sumH += j * D;
    //         if(sumH > 0){
    //             res = true;
    //             chmin(ans, sumC);
    //         }
    //     }
    //     dump(X);
    //     dump(ans);
    //     dump(res);
    //     return res;
    // };
    // while(ng - ok > 1){
    //     ll mid = (ok + ng) >> 1;
    //     if(check(mid))ok = mid;
    //     else ng = mid;
    // }
    // cout << ans << endl;

    // // コスパの良い行動
    // ll mina = C;
    // ll minb = D;
    // if(B * C > D * A){
    //     mina = A;
    //     minb = B;
    // }
    // // コストが小さい方
    // ll minna = C;
    // ll minnb = D;
    // if(A < C){
    //     minna = A;
    //     minnb = B;
    // }
    // dump(mina);
    // dump(minb);
    // dump(minna);
    // dump(minnb);
    // // Xの上限にするとき、
    // auto check = [&](ll X) -> bool {
    //     // コスパの良い行動をXにギリギリ近づくまで行う
    //     ll cnt = X / mina;
    //     ll Xrem = X % mina;
    //     ll cnt2 = Xrem / minna;
    //     // ll Xrem2 = Xrem % minna;
    //     ll sumH = H;
    //     sumH += cnt * minb;
    //     sumH += cnt2 * minnb; 
    //     // 残りの日程は-E
    //     ll Nrem = N - cnt - cnt2;
    //     sumH -= E * Nrem;
    //     dump(X);
    //     cerr << cnt << " " << cnt2 << " " << Nrem << endl;
    //     dump(sumH);
    //     return sumH > 0;
    // };
    ll ans = INFLL;
    for(ll i = 0; i <= N; i++){
        ll sumH = H;
        // sumH > 0となるjの最小値を求める
        ll ng = -1, ok = N-i+1;
        while(ok - ng > 1){
            ll mid = (ok + ng) >> 1;
            ll j = mid;
            ll k = N - i - j;
            if(sumH+B*i+D*j-k*E > 0)ok = mid;
            else ng = mid;
        }
        cerr << i << " " << ok << endl;
        if(ok >= 0){
            chmin(ans, A*i+C*ok);
        }
    }
    cout << ans << endl;

}

/*
最小化, 初期値H 
+A,    +B
+C,    +D
0,     -E

N回の意識決定をHが0にならないように乗り切る
-Eの回数に単調性がある
-Eの回数を固定すると、残りの日数でAとBを割り振る
割り振りがO(1)でできる？

出費を固定すると、割合的に安い方で埋めて、
最後の調整を片方の小さい出費の方で行うという戦略が正しそう



*/