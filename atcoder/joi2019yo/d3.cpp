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

    int N;
    cin >> N;
    set<int> st;
    vector<int> A(N+2,0);
    vector<bool> used(N+2,false);
    used[0] = used[N+1] = true;
    vector<i_i> B;
    rep1(i,N+1){
        cin >> A[i];
        st.insert(A[i]);
        B.push_back({A[i],i});
    }
    if(st.size() == 1){
        if(A[0] == 0)cout << 0 << endl;
        else  cout << 1 << endl;
        return 0;
    }
    sort(all(B));
    B.push_back({INF,-1});
    //print(B);
    int cnt = 0;
    int ans = 0;
    rep(i,N){
        int idx = B[i].second;
        if(not used[idx-1] && not used[idx+1])cnt++;
        if(used[idx-1] && used[idx+1])cnt--;
        used[idx] = true;
        if(B[i].first != B[i+1].first){
            //dump(idx);
            //dump(cnt);
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;
}