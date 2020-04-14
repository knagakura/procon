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
    vector<P> a;
    rep(i,N){
        int b;
        cin>>b;;
        a.push_back({b,i+1});
    }
    sort(all(a));
    ll ans = 0;
    vector<int> v;
    for (int i = N-1; i >= 0; --i){
        int x = N-i-1;
        ans += a[i].first * x + 1;
        v.push_back(a[i].second);
    }
    cout<<ans<<endl;
    rep(i,N){
        cout<<v[i];
        if(i == N-1){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
    }
}