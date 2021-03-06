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

//const ll mod = 1000000007;

void solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> one, zero;
    ll num = 0;
    vector<ll> ans(N);
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            if(zero.size()) {
                auto idx = zero.back();
                zero.pop_back();
                ans[i] = idx;
                one.push_back(idx);
            } else {
                num++;
                ans[i] = num;
                one.push_back(num);
            }
        }
        if(S[i] == '1') {
            if(one.size()) {
                auto idx = one.back();
                one.pop_back();
                ans[i] = idx;
                zero.push_back(idx);
            } else {
                num++;
                ans[i] = num;
                zero.push_back(num);
            }
        }
        print(one);
        print(zero);
    }
    cout << num << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}
