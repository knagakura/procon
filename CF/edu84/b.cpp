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

ll N, K;
void solve(){
    cin >> N;
    vvec<int> v(N);
    map<int, int> map;
    vector<bool> ok(N,false);
    set<int> se;
    rep(i,N)se.insert(i);
    rep(i,N){
        cin >> K;
        v[i].resize(K);
        rep(j, K){
            cin >> v[i][j];
            v[i][j]--;
            if(!ok[i]){
                if(map[v[i][j]] == 0){
                    ok[i] = true;
                    map[v[i][j]]++;
                    se.erase(v[i][j]);
                }
            }
        }
    }
    rep(i,N){
        if(!ok[i]){
            cout <<"IMPROVE" << endl;
            cout << i + 1 << " " <<*se.begin() + 1 << endl;
            return;
        }
    }
    cout << "OPTIMAL" << endl;
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    while(Q--){
        solve();
    }
}