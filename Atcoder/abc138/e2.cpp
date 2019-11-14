#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
const int INF =1e9;

string S,T;
vector<vector<int>> alpha(30);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>S>>T;
    int N = S.size();
    int M = T.size();
    rep(i,N){
        alpha[S[i]-'a'].push_back(i);
    }
    rep(i,N)alpha[S[i]-'a'].push_back(INF);
    ll ans = 0;
    int preidx = -1;
    rep(i,M){
        vector<int> &v = alpha[T[i]-'a'];
        if((int)v.size() == 0){
            ans = -1;
            break;
        }
        auto x = upper_bound(all(v),preidx) - alpha[T[i]-'a'].begin();
        if(v[x] == INF){
            ans += N-preidx-1;
            ans += v[0] + 1;
            preidx = v[0];
            continue;
        }
        ans += v[x] - preidx;
        preidx = v[x];
    }
    cout<<ans<<endl;
}