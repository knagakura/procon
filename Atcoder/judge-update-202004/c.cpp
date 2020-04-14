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
int N;
int A[3][3];
bool B[3][3];
int a[3];

void debug(){
    rep(i,3){
        rep(j,3){
            cerr << A[i][j];
            cerr << " ";
        }
        cerr << endl;
    }
}
bool check(vector<int>& v){
    rep(i,3)rep(j,3)A[i][j] = -1;
    rep(k,N){
        rep(i,3)rep(j,3)
        if(A[i][j] == -1 && B[i][j]){
            A[i][j] = v[k];
            i = j = 5;
        }
    }

    rep(i,3)rep(j,3){
        if(A[i][j] == -1)continue;
        if(i-1 >= 0&&B[i-1][j]){
            if(A[i][j] <= A[i-1][j])return false;
        }
        if(j-1 >= 0&&B[i][j-1]){
            if(A[i][j] <= A[i][j-1])return false;
        }
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> a[0] >> a[1] >> a[2];
    N = a[0]+a[1]+a[2];
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < a[i];j++){
            B[i][j] = true;
        }
    }
    vector<int> v;
    rep1(i,N+1)v.push_back(i);
    sort(all(v));
    int ans = 0;
    do{
        if(check(v)){
            ans++;
        }
    }while(next_permutation(all(v)));
    cout << ans << endl;
}