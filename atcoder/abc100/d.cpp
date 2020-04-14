#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M;
    cin>>N>>M;
    vector<ll> x(N),y(N),z(N);
    rep(i,N){
        cin>>x[i]>>y[i]>>z[i];
    }
    /*
    ケーキN個中M個を食べて、
    |\sigma(x)| + |\sigma(y)| + |\sigma(z)|
    を最大化したい

    +と-で分けて考える？
    |x|の最大化と|y|の最大化を同時にやるのは、無理だろ
    最終的に+にしたいとき、そのままの符号で扱う
    最終的に-にしたいとき、-をかけて扱う
    こうすれば、x + y + zの大きいものから貪欲に選んでもいいんじゃない？
    */
    ll ans = 0;
    for(int i = 0; i < bit(3); i++){
        vector<ll> tmps;
        rep(j,N){
            ll tmp = 0;
            tmp += ((i & bit(0)) ? x[j]:-x[j]);
            tmp += ((i & bit(1)) ? y[j]:-y[j]);
            tmp += ((i & bit(2)) ? z[j]:-z[j]);
            tmps.push_back(tmp);
        }
        sort(all(tmps));
        reverse(all(tmps));
        //print(tmps);
        ll summ = 0;
        rep(j,M){
            summ += tmps[j];
        }
        chmax(ans,summ);
    }
    cout<<ans<<endl;
}