#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<ll> L(N);
    rep(i,N)cin>>L[i];
    sort(all(L));
    //print(L);
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            int a = L[i];
            int b = L[j];
            //cの範囲は、l<c<r;
            /*
            int r = a+b;
            int l = b-a;
            */
            for(int k = j+1; k < N; ++k){
                if(a+b<=L[k]){
                    break;
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}