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
int N;
vector<string> v;
void dfs(string x){
    if((int)x.size() == N){
        v.push_back(x);
        return;
    }
    rep1(i,4){
        string tmp = x;
        tmp.push_back(char('0' +  i));
        dfs(tmp);
    }
}
void  dfs2(string s, int cnt){
    if(s.size() == 0)return;
    string nxt = "";
    rep(i,cnt)cout<<" ";
    rep(i,s.size()-1){
        int dif = abs(s[i+1] - s[i]);
        cout << dif << " ";
        nxt.push_back(char('0' + dif));
    }
    cout << endl;
    dfs2(nxt, cnt+1);
}
void solve(string x){
    for(char c: x){
        cout << c << " ";
    }
    cout << endl;
    dfs2(x,1);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    dfs("");
    print(v);
    for(auto s: v){
        solve(s);
    }
}