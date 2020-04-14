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
template<typename T>
vector<T> divisor(T N) {
    vector<T> res;
    for(T i = 1; i * i <= N; i++){
        if(N % i == 0){
            res.push_back(i);
            if(i * i != N)res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    ll sum = accumulate(all(a), 0LL);
    auto check = [&](ll X){
        if(X == 0)return true;
        // a[i]をXの倍数にするのにかかる移動の回数
        vector<ll> b(N),mi(N),pl(N);
        rep(i, N)b[i] = a[i];
        rep(i, N){
            b[i] %= X;
            mi[i] = b[i];
            pl[i] = X - b[i];
        }
        ll sumod = accumulate(all(mi), 0LL);
        sort(all(mi));
        //cerr<<"X, sum_mod: "<<X << " "<<sumod << endl;
        //print(mi);
        if(sumod % X != 0)return false;
        ll lsum = 0;
        for(int i = 0; i < N; i++){
            lsum += mi[i];
            int r = N - 1 - i;
            ll rsum = X * r  - (sumod - lsum);
            if(lsum == rsum){
                return lsum <= K;
            }
            //cerr << lsum << " " << rsum << endl;
        }
        //cerr << endl;
        return false;
    };
    auto v = divisor(sum);
    ll ans = 1;
    for(auto x : v){
        if(check(x)){
            ans = x;
        }
    }
    cout << ans << endl;
}

/*
A全てのGCDの最大値。
sum(A)は不変。
K回まで、二要素を選んで+1, -1する権利がある。

考えたこと：単調性、なし
sumの約数にしかならないので、それを全て試せば終わりか？
それになれるかどうかのチェックに時間がかかるが、できそう

*/