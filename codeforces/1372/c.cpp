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


void solve(){
    int N;
    cin >> N;
    vector<ll> A(N);
    int cnt = 0;
    bool exist = false;
    int l = 0;
    rep(i, N){
        cin >> A[i];
        A[i]--;
        if(i != A[i]){
            cnt++;
            if(not exist){
                l = i;
                exist = true;
            }
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
        return;
    }
    // 連続する区間だけで全部異なるところなら1, 不連続なら2
    bool ok = true;
    for(int i = l; i < l+cnt; i++){
        if(i == A[i])ok = false;
    }
    if(ok){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    cin >> t;
    while(t--)solve();
    
}
