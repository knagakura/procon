#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
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

    int N,M;
    cin>>N>>M;
    vector<int> ans(N, -1);
    bool nott = false;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;
        if(ans[a] == -1){
            ans[a] = b;
        }
        else{
            if(ans[a] != b){
                nott = true;
            }
        }
    }
    //print(ans);
    if(nott){
        cout<<-1<<endl;
        return 0;
    }
    if(N != 1 && ans[0] == 0){
        cout<<-1<<endl;
        return 0;
    }
    if(N == 1){
        if(ans[0] == -1){
            cout<<0<<endl;
        }
        else{
            cout<<ans[0]<<endl;
        }
        return 0;
    }
    rep(i,N){
        if(ans[i] == -1){
            if(i == 0)cout<<1;
            else cout<<0;
        }
        else cout<<ans[i];
    }
    cout<<endl;
}