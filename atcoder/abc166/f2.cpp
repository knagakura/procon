#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printo(v) { cout<<#v<<": [ "; for(auto _ : v) cout<<_<<", "; cout<<"]"<<endl; }
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

    ll N;
    ll A[3];
    cin >> N;
    rep(i,3)cin >> A[i];
    vector<string> S(N);
    vector<pair<int,int>> v;
    rep(i,N){
        cin >> S[i];
        if(S[i] == "AB")v.emplace_back(0,1);
        if(S[i] == "AC")v.emplace_back(0,2);
        if(S[i] == "BC")v.emplace_back(1,2);
    }
    ll sum = A[0] + A[1] + A[2];
    int x0 = v[0].first;
    int y0 = v[0].second;
    if(A[x0] + A[y0] == 0 || sum == 0){
        cout << "No" << endl;
        return 0;
    }
    // 初回はできる
    // sum > 0
    string t = "ABC";
    vector<char> ans;
    auto add = [&](int a, int b){
        A[a]++;
        A[b]--;
        ans.emplace_back(t[a]);
    };
    if(sum == 1){
        rep(i,N){
            int x = v[i].first;
            int y = v[i].second;
            if(A[x] + A[y] == 0){
                cout << "No" << endl;
                return 0;
            }
            if(A[x] > 0)add(y,x);
            else add(x,y);
        }
    }
    else if(sum == 2){
        v.emplace_back(0,1);
        // 一手先読みすれば最適な行動がわかる
        rep(i,N){
            int x = v[i].first;
            int y = v[i].second;
            // [2,0]
            if(max(A[x],A[y]) == 2){
                if(A[x] == 2)add(y,x);
                else add(x,y);
            }
            // [1,0]
            else if(max(A[x],A[y]) == 1 && min(A[x],A[y]) == 0){
                if(A[x] > A[y])add(y,x);
                else add(x, y);
            }
            // [1,1]
            else{
                int nx = v[i+1].first;
                int ny = v[i+1].second;
                if(x == nx && y == ny)add(x,y);
                else{
                    // 重なっている方に集める
                    if(x == nx || x == ny)add(x,y);
                    else add(y,x);
                }
            }
        }
    }
    // sum > 2
    else{
        // 少ない方に数を移すのでOK
        rep(i,N){
            int x = v[i].first;
            int y = v[i].second;
            if(A[x] < A[y])add(x,y);
            else add(y,x);
        }
    }
    cout << "Yes" << endl;
    rep(i,N){
        cout << ans[i] << endl;
    }
}
