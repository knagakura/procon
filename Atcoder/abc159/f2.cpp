#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;


const ll MOD = (ll)998244353;
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
/* dp[i][j][k]: 配列をi個見て、和がjで、
右端も決まってない(0), 
右端は決まっているが左端は決まっていない(1), 
両方決まっている(2)
*/
mint dp[3010][3010][3];
int N, S;
void debug(){
    rep(k,3){
        cerr <<"["<<k << "]" << endl;
        rep(i,N+1){
            rep(j,S+1){
                cerr << dp[i][j][k] <<" ";
            }
            cerr << endl;
        }
        cerr << endl;
    }
    cerr << endl;
}
int main() {
    cin >> N >> S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    //Lのスタート時に反映される遷移していく元となるものたち
    rep(i,N+1)dp[i][0][0] = 1;
    //debug();
    //2からは遷移させない。
    //0からの遷移は、和を取るかどうか*1にいくか（長さを伸ばすか）2にいくか（長さを1にするか）
    //1からの遷移は、和を取るかどうか * 1にいくか2にいくか
    rep(i,N){
            rep(j,S+1){
            //from 0
            {
                //to 1  Lを決めて和をとらない
                dp[i+1][j][1] += dp[i][j][0];
                //      Lを決めて和を取る
                dp[i+1][min(S+1, j+A[i])][1] += dp[i][j][0];
                //to 2
                //        Lを決めて和を取ってRも決める
                dp[i+1][min(S+1, j+A[i])][2] += dp[i][j][0];
            }
            //from 1
            {
                //to 1  iを使わないでRを決めない
                dp[i+1][j][1] += dp[i][j][1];
                //      iを使ってRを決めない
                dp[i+1][min(S+1, j+A[i])][1] += dp[i][j][1];
                //to 2  iを使わないでRを決める
                dp[i+1][j][2] += dp[i][j][1];
                //      iを使ってRを決める
                dp[i+1][min(S+1, j+A[i])][2] += dp[i][j][1];
            }
        }
    }
    mint ans = 0;
    rep(i,N+1)ans += dp[i][S][2];
    cout << ans << endl;
}