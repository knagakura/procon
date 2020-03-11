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
string s,t;


void debug(vector<vector<int>>& vv){
    rep(i,26){
        if(vv[i].size() == 0)continue;
        cerr<<char('a'+i)<<": ";;print(vv[i]);
    }
    cerr<<endl;
}
void solve(){
    cin >> s >> t;
    set<char> sset, ttset;

    string ss = s + s;
    vector<vector<int>> nxtidx(26);
    rep(i, ss.size()){
        nxtidx[ss[i] - 'a'].push_back(i);
    }
    //debug(nxtidx);
    ll ans = 1;
    int nowidx = -1;
    rep(i,t.size()){
        auto nxtitr = upper_bound(all(nxtidx[t[i] - 'a']), nowidx);
        if(nxtitr == nxtidx[t[i] - 'a'].end()){
            cout<< -1 <<endl;
            return;
        }
        //cerr<<t[i]<<" "<<*nxtitr<<endl;
        nowidx = *nxtitr;
        if(nowidx >= (int)s.size()){
            nowidx %= int(s.size());
            ans++;
        }
    }
    cout<< ans << endl;
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