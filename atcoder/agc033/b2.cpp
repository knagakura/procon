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
int H,W,N;
string S,T;
bool solve(int t, int mx, int sx){
    //Nターン後は、
    //[0, N-1]の区間に入っていられるかどうか
    char plus = 'D';
    char minu = 'U';
    if(t == 1){
        plus = 'R';
        minu = 'L';
    }
    // [l, r)の区間
    int l = 0, r = mx;
    //cerr<<endl;
    for(int i = N-1;i >= 0;i--){
        //cerr << "start: " <<l << " " << r <<endl;
        if(l == r)return false;
        if(T[i] == minu){
            r++;
            chmin(r, mx);
        }
        else if(T[i] == plus){
            l--;
            chmax(l, 0);
        }
        //cerr << l << " " << r << endl;
        if(S[i] == plus){
            r--;
        }
        else if(S[i] == minu){
            l++;
        }
        //cerr << l << " " << r << endl;
    }
    //cerr << "finished" << endl;
    //cerr << sx << endl;
    if(sx < l || r <= sx){
        return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int sx, sy;
    cin >> H >> W >> N;
    cin >> sx >> sy;
    sx--;sy--;
    cin >> S >> T;
    bool ok = true;
    if(!solve(0, H, sx)){
        ok = false;
    } 
    if(!solve(1, W, sy)){
        ok = false;
    }
    cout << (ok ? YES :NO) << endl;
}