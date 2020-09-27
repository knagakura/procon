#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);
/*
int N,Q;
vector<ll> a,x;
ll solve(ll K){
    ll r = 0;
    ll sum = 0;
    ll res = 0;
    for(ll l = 0; l < N; l++){
        while(r < N && sum + a[r] <= K){
            sum += a[r];
            r++;
        }
        res += r - l;
        if(l == r)r++;
        else sum -= a[l];
    }
    return res;
}
*/
int main() {
    int N,Q;
    cin>>N>>Q;
    vector<ll> a(N),x(Q);
    rep(i,N)cin>>a[i];
    rep(i,Q)cin>>x[i];
    auto solve = [&](ll K){
        ll r = 0;
        ll sum = 0;
        ll res = 0;
        for(ll l = 0; l < N; l++){
            while(r < N && sum + a[r] <= K){
                sum += a[r];
                r++;
            }
            res += r - l;
            if(l == r)r++;
            else sum -= a[l];
        }
        return res;
    };
    rep(i,Q){
        cout<<solve(x[i])<<endl;;
    }
}