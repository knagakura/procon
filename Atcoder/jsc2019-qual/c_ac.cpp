#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<char(_.first)<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int INF = 1e9;
class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 1e9+7;
    static vector<modint> factorial;
    modint(): num(0) {};
    modint(ll _n): num((_n + MOD) % MOD) {}
    modint(const modint &r): num(r.num) {}
    operator ll() const { return (num+MOD)%MOD; }
    friend istream& operator>>(istream& is, modint &r){
        ll num_;
        is >> num_;
        r = num_;
        return is;
    }
    modint operator+(const modint &r) const { return modint(num + r.num); }
    modint operator-(const modint &r) const { return modint(num - r.num); }
    modint operator*(const modint &r) const { return modint(num * r.num); }
    template<typename T>
    modint operator^(const T &r) const {
        if(r == 0) return 1;
        return (((*this)*(*this)) ^ (r/2)) * modint(r&1 ? num : 1);
    }
    modint operator/(const modint &r) const { return num * (r^(MOD-2)); }
    modint operator+=(const modint &r) { return *this = *this + r; }
    modint operator-=(const modint &r) { return *this = *this - r; }
    modint operator*=(const modint &r) { return *this = *this * r; }
    modint operator/=(const modint &r) { return *this = *this / r; }
    template<typename T>
    modint operator^=(const T &r) { return *this = *this ^ r; }
    static modint fact(int n){
        if((int)factorial.size() <= n) factorial.resize(n+1);
        if(factorial[n]) return factorial[n];
        if(n == 0) return 1;
        return factorial[n] = modint(n) * fact(n-1);
    }
    static modint C(ll n,ll r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }
};
vector<modint> modint::factorial;
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define H(a,b) C(a+b, a)

//https://twitter.com/tempura_cpp/status/1165292041779073029

/*Cで僕が考えたこと
・累積的な何かを考えるとよさそう
・[L, R]の反転は、[0, R]の反転と[0, L-1]の反転に分解できる
・つまりそれぞれの頂点xは[0, x]の反転として使う(Rにする)か[0,x-1]の反転として使う(Lにする)かのどちらか
・ある点yを見たとき、yより小さいやつについてはどっちの選択をしてもyには影響しない
・yより大きいやつについてはどっちを選択してもyを反転することになる
・つまり点yを反転するかしないかの選択肢は頂点yをLで使うかRで使うかのみで決まる
・したがってそれぞれの頂点についてLかRかが定まる
・LかRかが決まったあとはRと組み合わせられるのは自分より小さいやつなので順番に数えていけばいい
・操作の順番は自由なので最後にN!かけてできあがり
*/
int main() {
    ll N;
    string S;
    cin>>N>>S;
    modint cntl = 0;
    modint ans = 1;
    rep(i,2*N){
        if(cntl%2 == 0){
            if(S[i] == 'W'){//偶数回ひっくり返したい
            //今Rにすればちょうど良い
            ans *= cntl;
            cntl-=1;
            if(cntl<0){
                break;
                }
            }
            else{//奇数回ひっくり返したい
            //Lにしておけばよくね
            cntl+=1;
            }
        }
        else{
            if(S[i] == 'W'){//偶数回ひっくり返したい
            cntl+=1;
            }
            else{//奇数回ひっくり返したい
            //今Rにすれば、ちょうど良い
            //Rにしたときは、その前のK個のLとの組み合わせがあるので、
            ans *= cntl;
            cntl-=1;
            if(cntl<0){
                break;
                }   
            }
        }
    }
    if(cntl!=0){
        cout<<0<<endl;
        return 0;
    }
    ans*=fact(N);
    cout<<ans<<endl;
}