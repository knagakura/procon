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
int N;
string s;
bool used[26];
void solve(){
    cin>>s;
    N = s.size();
    if(N == 1){
        cout<<YES<<endl;
        rep(i,26){
            cout<<char(i + 'a');
        }
        cout<<endl;
        return;
    }
    rep(i,26)used[i] = false;
    map<char, set<char>> rel; 
    deque<char> ans;
    //実際に構築しながら可否を確認していく
    ans.push_back(s[0]);
    ans.push_back(s[1]);
    used[s[0] - 'a'] = used[s[1] - 'a'] = true;
    rel[s[0]].insert(s[1]);
    rel[s[1]].insert(s[0]);
    bool ok = true;
    rep1(i,N-1){
        //使っていたら、一個前と繋がっていたかどうかを確認する
        if(used[s[i+1] - 'a']){
            if(rel[s[i]].find(s[i+1]) != rel[s[i]].end()){
                continue;
            }
            else{
                ok = false;
                break;
            }
        }
        else{
            //使っていないのに、一個前が埋まっていたら
            if(rel[s[i]].size() == 2){
                ok = false;
                break;
            }
            //埋まってない場合、必ず一個だけである
            else{
                rel[s[i]].insert(s[i+1]);
                rel[s[i+1]].insert(s[i]);
                ans.push_back(s[i+1]);
                used[s[i+1]-'a'] = true;
            }
        }
    }

    if(!ok){
        cout<<NO<<endl;
        return;
    }
    cout<<YES<<endl;
    for(auto x: ans){
        cout<<x;
    }
    rep(i,26){
        if(!used[i]){
            cout<<char(i + 'a');
        }
    }
    cout<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}