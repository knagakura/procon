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
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) mp[x]++;
    return mp;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A,B;
    cin>>A>>B;
    ll g = gcd(A,B);
    vector<ll> cd;
    auto map = factorize(g);
    map[1]++;
    cout<<map.size()<<endl;
}