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
template<typename T, typename U> 
T _pow(T a, U n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<ll> a(N);
    map<ll,int> mp;
    vector<map<ll,int>> vmp;
    rep(i,N){
        cin >> a[i];
        auto tmp = factorize(a[i]);
        vmp.push_back(tmp);
        for(auto &p:tmp){
            mp[p.first] += p.second;
        }
    }
    map<ll,ll> sosu2idx;
    map<ll,ll> idx2sisu;
    int idx = 0;
    for(auto &p: mp){
        sosu2idx[p.first] = idx;
        idx2sisu[idx] = p.first;
        idx++;
    }
    int sz = mp.size();
    vvec<int> b(sz, vec<int>());
    rep(i,N){
        for(auto &p: vmp[i]){
            b[sosu2idx[p.first]].push_back(p.second);
        }
    }
    rep(j,sz){
       sort(all(b[j])); 
    }
    ll ans = 1;
    //ある素数に対して、個数を数える
    rep(j,sz){
        ll sisu = 0;
        if(b[j].size() == N){
            sisu = b[j][1];
        }
        if(b[j].size() == N-1){
            sisu = b[j][0];
        }
        ans *= _pow(idx2sisu[j], sisu);
    }
    cout << ans << endl;
}