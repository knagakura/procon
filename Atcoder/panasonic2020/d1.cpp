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
set<string> xx;
map<string , int> mapz;
string int_2_string(int x){
    map<char, int> mapx;
    map<char, char> mapy;
    string ss = to_string(x);
    string res = "";
    int cnt = 0;
    rep(j, ss.size()){
        if(mapx[ss[j]] == 0){
            res.push_back(char(cnt + 'a'));
            mapy[ss[j]] = char(cnt + 'a');
            cnt++;
            mapx[ss[j]]++;
        }
        else{
            res.push_back(mapy[ss[j]]);
        }
    }
    cerr << x << " " << res << endl;
    return res;
}
void dfs(int i, int s){
    string ss = int_2_string(s);
    if(s !=0 &&mapz[ss] > 0){
        return;
    }
    if(s != 0)mapz[ss]++;
    if(i == N){
        string res = ss;
        //cerr<<s<<" "<<res<<endl;
        xx.insert(res);
        return;
    }
    for(int nxt = 0; nxt <= N;nxt++){
        int tmp = s * 10 + nxt;
        dfs(i+1,tmp);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    dfs(0, 0);
    //cerr << x.size() << endl;
    //cerr<<"ans"<<endl;
    /*
    for(auto y:xx){
        cout<<y<<endl;
    }*/
    cerr << int_2_string(111111233) << endl;
}
