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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        cin>>S;
        N = S.size();
        map<char,int> map;
        rep(i,N){
            map[S[i]]++;
        }
        int gx = 0;int gy = 0;
        for(auto p:map){
            cerr<<p.first<<" "<<p.second<<endl;
            if(p.first == 'L')gx-=p.second;
            if(p.first == 'R')gx+=p.second;
            if(p.first == 'U')gy+=p.second;
            if(p.first == 'D')gy-=p.second;
        }
        cerr<<gx<<" "<<gy<<endl;
        if(gx == 0 && gy == 0){
            cout<<S.size()<<endl;
            cout<<S<<endl;
            continue;
        }
        string ans = "";
        rep(i,N){
            if(S[i] == 'L'&&gx < 0){
                gx++;
                continue;
            }
            if(S[i] == 'R'&&gx > 0){
                gx--;
                continue;
            }
            if(S[i] == 'U'&&gy > 0){
                gy--;
                continue;
            }
            if(S[i] == 'D'&&gy < 0){
                gy++;
                continue;
            }
            ans.push_back(S[i]);
        }
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
}