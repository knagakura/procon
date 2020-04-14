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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    vector<vector<pair<int,int>>> xy(N);
    rep(i,N){
        int A;
        cin>>A;
        while(A--){
            int x,y;
            cin>>x>>y;
            x--;
            xy[i].push_back({x,y});
        }
    }
    int ans = 0;
    for(ll k = 0; k < bit(N);k++){
        vector<int> f(N,-1);
        bool ng = false;
        for(int i = 0;i < N;i++){
            //iが正直正直者
            if(k & bit(i)){
                if(f[i] == -1){
                    f[i] = 1;
                }
                else{
                    if(f[i] == 0)ng = true;
                }
                for(auto p:xy[i]){
                    int idx = p.first;
                    int y = p.second;
                    if(f[idx] == -1){
                        f[idx] = y;
                    }else{
                        if(f[idx] !=y)ng = true;
                    }
                }
            }
            //iが嘘つき
            else{
                if(f[i] == -1){
                    f[i] = 0;
                }
                else{
                    if(f[i] == 1)ng = true;
                }
                for(auto p:xy[i]){
                    int idx = p.first;
                    int y = p.second;
                    if(f[idx] == -1){
                        if(y == 0)f[idx] = 1;
                        else f[idx] = 0;
                    }else{
                        if(f[idx] == y)ng = true;
                    }
                }
            }
        }
        
        if(ng)continue;
        int cnt = 0;
        rep(i,N){
            if(f[i] == 1)cnt++;
        }
        chmax(ans,cnt);
    }
    cout<<ans<<endl;
}