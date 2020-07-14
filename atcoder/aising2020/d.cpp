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
string int2stringbit(ll X){
    string res = "";
    for(int i = 0; i <= 63; i++){
        if(bit(i) > X)break;
        if(X & bit(i))res.push_back('1');
        else res.push_back('0');
    }
    return res;
}
ll longDivision(string &number, ll divisor, ll cnt = 0){
    //cerr << number <<  " " << divisor << " " << cnt << endl;
    string div = int2stringbit(divisor);
    reverse(all(div));
    if(number == "1" && divisor == 1){
        return cnt;
    }
    /* calc */
    //dump(div);
    for(int i = 0; i+div.size() <= number.size(); i++){
        int st = i;
        int len = div.size();
        int ed = st + len;
        if(i > 0){
            st--;
            len++;
        }
        string tmp = number.substr(st, len);
        ll x = stoll(tmp,nullptr,2);
        ll y = stoll(div,nullptr,2);
        /*
        cerr << endl;
        dump(tmp);
        dump(div);
        cerr << x << " " << y << endl;
        */
        if(x >= y){
            x-=y;
        }
        //cerr << x << " " << y << endl;
        // xをbit表現に直す
        string tmp2 = "";
        for(int j = st; j < ed; j++){
            if(bit(j - st)&x)tmp2.push_back('1');
            else tmp2.push_back('0');
        }
        reverse(all(tmp2));
        //dump(tmp2);
        for(int j = st; j < ed; j++){
            number[j] = tmp2[j-st];
        }
        //dump(number);
    }
    string rem = number.substr(number.size() - div.size(), div.size());
    int nxt_div = 0;
    int sz = rem.size();
    rep(i,sz)nxt_div += (rem[i] == '1');
    //dump(rem);
    if(nxt_div == 0)return cnt+1;
    return longDivision(rem, nxt_div, cnt+1);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    string X;
    cin >> N >> X;
    int cnt = 0;
    rep(i,N)cnt += (X[i] - '0');
    rep(i,N){
        string tmp = X;
        int div = cnt;
        if(X[i] == '1'){
            tmp[i] = '0';
            div--;
        }
        else {
            tmp[i] = '1';
            div++;
        }
        //if(i == 1)
        cout << longDivision(tmp, div) << endl;
    }
}
