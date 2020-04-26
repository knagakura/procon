#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
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
//上からi桁で、j本使ったときの最大値

void chmax(string &a, string b){
    if(a.size() > b.size())return;
    if(a.size() < b.size()){
        a = b;
        return;
    }
    if(a.size() == b.size()){
        int sz = a.size();
        rep(i,sz){
            if(a[i] > b[i])return;
            if(a[i] == b[i])continue;
            if(a[i] < b[i]){
                a = b;
                return;
            }
        }
    }
    return;
}
string dp[2020][2020];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;
    vector<string> v(N);
    rep(i,N)cin>>v[i];
    string minn = "";
    minn.push_back('0'-1);
    rep(i,N+1)rep(j,K+1)dp[i][j] = minn;
    dp[0][0] = "";
    string s[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    // x->yに変えるときに
    auto sa = [&](string x, string y){
        int res = 0;
        rep(i,x.size()){
            if(x[i] == y[i])continue;
            if(x[i] > y[i])return -1;
            if(x[i] < y[i])res++;
        }
        return res;
    };
    rep(i,N){
        rep(j,K){
            rep(k,10){
                string tmp = dp[i][j];
                tmp.push_back(char(k + '0'));
                int cnt = sa(v[i], s[k]);
                if(cnt < 0)continue;
                chmax(dp[i+1][j+cnt], tmp);
            }
        }
    }
    if(dp[N][K] == "")cout << -1 << endl;
    else cout << dp[N][K] << endl;
}