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

bool isbig(char c){
    return (0 <= c - 'A' && c-'A' < 26);
}
bool issmall(char c){
    return (0 <= c - 'a' && c - 'a' < 26);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;cin>>S;
    int N; N = S.size();
    string x = "";
    int cnt = 0;
    vector<string> ans;
    rep(i,N){
        if(isbig(S[i])){
            cnt++;

            S[i] = char((S[i] - 'A') + 'a');
        }
        x.push_back(S[i]);
        if(cnt == 2){
            ans.push_back(x);
            cnt = 0;
            x = "";
        }
    }

    sort(all(ans));

    /*
    rep(i,(int)ans.size()){
        cerr<<ans[i]<<endl;
    }*/
    rep(i,(int)ans.size()){
        rep(j,(int)ans[i].size()){
            if(j == 0 || j == (int) ans[i].size() - 1){
                cout<<char(ans[i][j] - 'a' + 'A');
            }
            else{
                cout<<ans[i][j];
            }
        }
    }
    cout<<endl;
}