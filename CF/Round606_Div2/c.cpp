#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
string S;
int N;
void solve(){
    cin>>S;
    N = S.size();
    vector<int> ans;
    rep(i,N-2){
        string t = S.substr(i,3);
        //cerr<<i<<" "<<t<<endl;
        if(t == "one" || t ==  "two"){
            if(S.substr(i,5) == "twone"){
                ans.push_back(i + 3);
                i+= 2;
            }
            else{
                ans.push_back(i+2);
                i+=1;
            }
        }
    }
    cout<<ans.size()<<endl;
    if(ans.size()==0)cout<<endl;
    rep(i,int(ans.size())){
        cout<<ans[i];
        if(i == (int)ans.size()-1)cout<<endl;
        else cout<<" ";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}