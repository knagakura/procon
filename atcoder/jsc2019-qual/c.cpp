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

int main() {
    ll N;
    string S;
    cin>>N>>S;
    S.push_back('.');
    ll ans = 0;
    vector<P> v;
    //{'B',3},みたいなやつ
    //ランレングス圧縮だ！
    char nowchar = S[0];
    int nowcnt = 1;
    for(int i = 0; i < 2*N; ++i){
        if(S[i]!=S[i+1]){
            v.push_back({char(nowchar),nowcnt});
            if(nowchar == 'B'){
                nowchar = 'W';
            }
            else{
                nowchar = 'B';
            }
            nowcnt = 1;
        }
        else{
            nowcnt++;
        }
    }
    printpair(v);
    //ここまでランレングス圧縮
    //境界の数はv.size()

    //1回の操作で減らせる境界は最大で1つ
    //境界の数が一定の値以上だと実現できなくなる（N以上）
    //Nだった場合、貪欲
    //N以下だった場合、Nと偶奇が一致しているなら一回無駄な動きをすることで手数を2増やせるので実現可能
    //Nと偶奇が一致しないと、実現不可能

    //貪欲はキツそうなので、i回目の操作後に境界数がj個みたいなdpを考えてあげる
    //境界の数は最大でN+1個


    //逆から見よう
    //最初all W
    //そこからBWWB
    




    cout<<ans<<endl;

}