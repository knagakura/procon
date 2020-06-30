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

    ll N, K;
    cin >> N >> K;
    vector<pair<ll, i_i>> v;
    vector<ll> va,vb, vv;
    rep(i,N){
        ll t,a,b;
        cin >> t >> a >> b;
        if(a & b)vv.push_back(t);
        else if(a)va.push_back(t);
        else if(b)vb.push_back(t);
    }
    sort(all(va));
    sort(all(vb));
    sort(all(vv));
    /*
    print(va);
    print(vb);
    print(vv);
    */
    vector<ll> ansa,ansb,ansvv;
    for(int i = 0; i < K; i++){
        if(i < va.size())ansa.push_back(va[i]);
        if(i < vb.size())ansb.push_back(vb[i]);
    }
    int sizes[] = {(int)ansa.size(), (int)ansb.size()};
    int idx = 0;
    while(sizes[0] < K || sizes[1] < K){
        if(idx >= vv.size()){
            cout << -1 << endl;
            return 0;
        }
        if(sizes[0] < K && sizes[1] < K){
            ansvv.push_back(vv[idx]);
            sizes[0]++;
            sizes[1]++;
            idx++;
        }
        else if(sizes[0] < K){
            ansvv.push_back(vv[idx]);
            sizes[0]++;
            ansb.pop_back();
            idx++;
        }
        else if(sizes[1] < K){
            ansvv.push_back(vv[idx]);
            sizes[1]++;
            ansa.pop_back();
            idx++;  
        }
    }

    for(int i = idx; i < vv.size(); i++){
        if(ansa.size() == 0 || ansb.size() == 0)continue;
        if(ansa.back() + ansb.back() > vv[i]){
            ansa.pop_back();
            ansb.pop_back();
            ansvv.push_back(vv[i]);
        }
    }
    /*
    print(ansa);
    print(ansb);
    print(ansvv);
    */
    ll ans = 0;
    for(auto a: ansa)ans += a;
    for(auto b: ansb)ans += b;
    for(auto vv: ansvv)ans += vv;
    cout << ans << endl;
}
