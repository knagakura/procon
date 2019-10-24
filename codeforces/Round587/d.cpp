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
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<ll> a(N);
    rep(i,N){
        cin>>a[i];

    }
    sort(all(a));
    vector<ll> d(N);
    rep(i,N){
        d[i] = a[N-1]-a[i];
    }
    ll z = d[0];
    rep(i,N){
        if(d[i]>0){
            z = gcd(z, d[i]);
        }
    }
    ll y = 0;
    rep(i,N){
        y += d[i]/z;
    }
    cout<<y<<" "<<z<<endl;

}