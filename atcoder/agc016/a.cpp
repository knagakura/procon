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

    string S;
    cin >> S;
    int N = S.size();
    map<int, int> mp;
    rep(i,N)mp[S[i]-'a']++;
    ll ans = INF;
    rep(i,26){
        if(!mp.count(i))continue;
        string pre = S;
        string nxt = "";
        ll cnt = 0;
        while(true){
            bool ok = true;
            nxt = "";
            int M = pre.size();
            rep(j,M-1){
                if(pre[j]-'a' != i || pre[j+1] - 'a' != i)ok = false;
                /*calc*/
                if(pre[j]-'a' == i || pre[j+1] - 'a' == i){
                    nxt.push_back(char('a'+i));
                }
                else nxt.push_back(pre[j]);
            }
            if(ok)break;
            cnt++;
            swap(pre, nxt);
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
}