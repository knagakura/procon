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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,K;
    cin>>N>>K;
    vector<ll> a(N),b(N);
    rep(i,N)cin>>a[i];
    rep(i,N)cin>>b[i];
    sort(all(a));
    sort(all(b));
    //x以下の数がK個以上か
    auto check = [&](ll x){
        ll cnt = 0;
        for(int i = 0; i < N; ++i){
            ll ok = -1;
            ll ng = N;
            while(ng-ok > 1){
                ll mid = (ok + ng)/2;
                if(a[i] * b[mid] <= x){
                    ok = mid;
                }
                else ng = mid;
            }
            cnt += ok + 1;
        }
        return cnt >= K;
    };
    ll ng = -1;
    ll ok = INFLL;
    while(ok-ng > 1){
        ll mid = (ok+ng)/2;
        if(check(mid)){
            ok = mid;
        }
        else ng = mid;
    }
    cout<<ok<<endl;
}