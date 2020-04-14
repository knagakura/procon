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
void Case(int t){
    cout << "Case #" << t << ": ";
}
int N;
vec<string> P;

void debug(vvec<string>& x){
    rep(i,N){
        rep(k,2){
            cerr << x[k][i] << " ";
        }
        cerr << endl;
    }
}
void solve1(){
    vvec<string> lr(2, vec<string>(N));
    rep(i,N){
        int k = 0;
        rep(j, P[i].size()){
            if(P[i][j] == '*'){
                k++;
                continue;
            }
            lr[k][i].push_back(P[i][j]);
        }
    }
    rep(i,N)reverse(all(lr[1][i]));
    string ans[2] = {"", ""};
    bool ok = true;
    rep(k,2){
        int maxsize = 0;
        rep(i,N)chmax(maxsize, (int)lr[k][i].size());
        rep(j,maxsize){
            set<char> se;
            rep(i,N){
                if(j >= (int)lr[k][i].size())continue;
                se.insert(lr[k][i][j]);
            }
            if(se.size() > 1){
                ok = false;
                break;
            }
            ans[k].push_back(*se.begin());
        }
    }
    reverse(all(ans[1]));
    if(!ok){
        cout << "*" <<  endl;
    }
    else{
        cout << ans[0] << ans[1] << endl;
    }
}
void solve2(){

}
void input(){
    cin >> N;
    P.resize(N);
    rep(i,N)cin>>P[i];
}
void solve(){
    input();
    bool ok = true;
    rep(i,N){
        int cnt = 0;
        rep(j,P[i].size()){
            cnt += P[i][j] == '*';
        }
        if(cnt != 1)ok = false;
    }
    if(ok)solve1();
    else solve2();
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    rep1(i, t+1){
        Case(i);
        solve();
    }
}