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

    int t;
    cin >> t;
    while(t--){
        ll N;
        cin >> N;
        vector<l_l> cnt[2];
        rep(i,2*N){
            ll a;
            cin >> a;
            cnt[a%2].push_back({a,i+1});
        }
        //print(cnt[0]);
        //print(cnt[1]);
        if(cnt[0].size() % 2 == 1){
            cnt[0].pop_back();
            cnt[1].pop_back();
        }
        else{
            if(cnt[0].size() >= 2){
                cnt[0].pop_back();
                cnt[0].pop_back();
            }
            else{
                cnt[1].pop_back();
                cnt[1].pop_back();
            }
        }
        rep(i,cnt[0].size()){
            cout << cnt[0][i].second << " " << cnt[0][i+1].second << endl;
            i++;
        }
        rep(i,cnt[1].size()){
            cout << cnt[1][i].second << " " << cnt[1][i+1].second << endl;
            i++;
        }
    }
}