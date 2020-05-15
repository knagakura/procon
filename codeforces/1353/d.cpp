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

void solve(){
    int N;
    cin >> N;
    vector<int> a(N,0);
    priority_queue<i_i, vector<i_i>> pq;
    //長さと左端
    pq.push({N, 0});
    int cnt = 0;
    while(not pq.empty()){
        auto tmp = pq.top();
        cnt++;
        pq.pop();
        //[l,r)
        int l = -tmp.second;
        int r = l + tmp.first;
        if(l == r)continue;
        if(cnt > N)break;
        int mid = ((r-l)&1) ? (l+r)/2 : (l+r)/2-1;
        //cerr <<"(" << l << " " << r << "): " << mid << endl;
        a[mid] = cnt;
        //cerr << "add: " << "(" << l << " " << mid << ")" << endl;
        //cerr << "add: " << "(" << mid+1 << " " << r << ")" << endl;
        pq.push({mid-l, -l});
        pq.push({r-mid-1, -mid-1});
    }
    rep(i,N){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}