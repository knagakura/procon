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

void solve(){
    int N;
    string S;
    cin >> N >> S;
    // vector<int> v[2];
    set<int> v[2];
    rep(i,N)v[S[i]-'0'].insert(i);
    if(*v[1].begin() == 0)swap(v[0],v[1]);
    // print(v[0]);
    // print(v[1]);
    vector<int> used(N,false);
    vector<int> ans(N);
    int cnt = 1;
    rep(i,N){
        if(used[i])continue;
        int tmp = 1;
        if(*v[1].begin() == i){
            tmp++;
        }
        ll a = i;
        ans[a] = cnt;
        used[a] = true;
        while(true){
            auto itr = v[tmp&1].lower_bound(a);
            if(itr == v[tmp&1].end())break;
            int b = *itr;
            v[tmp&1].erase(b);
            ans[b] = cnt;
            used[b] = true;
            a = b;
            tmp++;
        }
        cnt++;
    }
    cout << *max_element(all(ans)) << endl;
    rep(i,N){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
