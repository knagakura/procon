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
    cout << fixed << setprecision(20);
    ll N;
    cin>>N;
    vector<pair<ll,ll>> list;
    for(ll i = 1; i*i <= N; ++i){
        if(N%i == 0){
            list.push_back({i,N/i});
            list.push_back({N/i,i});
        }
    }
    int M = list.size();
    ll ans = 1e12;;
    rep(i,M){
        ll x = list[i].first;
        ll y = list[i].second;
        ll d = abs(x-1) + abs(y - 1);
        ans = min(ans, d);
    }
    cout<<ans<<endl;
}