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
string henkan(string s){
    //今まで出てきた文字数を確認する
    map<char, int> chars;
    map<char, char> char2char;
    string res = "";
    rep(i,s.size()){
        if(chars[s[i]] == 0){
            char bck = char('a' + chars.size()-1);
            res.push_back(bck);
            chars[s[i]]++;
            char2char[s[i]] = bck;
        }
        else{
            res.push_back(char2char[s[i]]);
        }
    }
    return res;
}
map<string, int> maps;
set<string> ans;
void dfs(string s){
    string x = henkan(s);
    if(maps[x])return;
    maps[x]++;
    if((int)x.size() == N){
        ans.insert(x);
        return;
    }
    for(int i = 0; i < N;i++){
        string nx = x;
        nx.push_back(char(i + 'a'));
        dfs(nx);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    dfs("");
    for(auto y:ans){
        cout << y << endl;
    }
}