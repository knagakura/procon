#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
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
template<typename T>
vector<pair<T,long long>> RunLengthEncoder(vector<T> &v){
    vector<pair<T,long long>> RLE;
    long long cnt = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        if(i == (int)v.size()-1){
            RLE.push_back(make_pair(v[i], cnt));
            continue;
        }
        if(v[i] == v[i+1])cnt++;
        else{
            RLE.push_back(make_pair(v[i],cnt));
            cnt = 1;
        }
    }
    return RLE;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }
    sort(all(A), greater<ll>());
    auto v = RunLengthEncoder(A);
    int l = 0;
    for(auto p:v){
        l += p.second;
        if(l >= P)break;
    }
    l--;
    // M * V独立に選べる
    auto check = [&](int x){
        if(x <= l)return true;
        if(A[x] + M < A[l])return false;
        ll maxx = A[x] + M;
        ll res = 0;
        rep(i,N){
            //dump(i);dump(res);
            if(A[i] > A[l])res += M;
            else if(A[l] == A[i])res += min(M, maxx - A[i]);
            else if(A[i] > A[x]) res += min(M, maxx - A[i]);
            else if(A[x] >= A[i])res += M;
        }
        //dump(x);dump(res);
        return ll(M * V)<= res;
    };
    int ok = -1;
    int ng = N;
    while(ng - ok > 1){
        int mid = (ok + ng)>>1;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok+1 << endl;
}