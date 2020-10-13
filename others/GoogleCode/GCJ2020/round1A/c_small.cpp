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
void solve_small(int N){
    vector<pair<int, int>> v;
    rep(i,N){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    //重なりがあるかどうか
    auto check = [&](vector<int>& w){
        int sz =  w.size();
        rep(i,sz)rep(j,sz){
            if(i >= j)continue;
            int l1 =  v[w[i]].first;
            int r1 = v[w[i]].second;
            int l2 = v[w[j]].first;
            int r2 = v[w[j]].second;
            if(max(l1,l2) < min(r1,r2))return false;
        }
        return true;
    };
    bool ok = false;
    int ansbit = 0;
    for(int k = 0; k < bit(N);k++){
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < N;i++){
            if(k & bit(i))v1.push_back(i);
            else v2.push_back(i);
        }
        if(check(v1) && check(v2)){
            ok = true;
            ansbit = k;
            break;
        }
    }
    if(!ok){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    string ans = "";
    rep(i,N){
        ans.push_back((ansbit & bit(i)) ? 'C':'J');
    }
    cout << ans << endl;
}
void solve_large(int N){
    vector<pair<int, int>> v;
    rep(i,N){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
}
void solve(){
    int N;
    cin >> N;
    if(N <= 10) solve_small(N);
    else solve_large(N);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    rep1(i, t+1){
        cout  << "Case #" << i << ": ";
        solve();
    }
}