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
const ll INFLL = (ll)1e18 + 1;
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

    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    print(A);
    auto check = [&](ll X){
        ll res = 0;
        vector<int> cnt(N, 0);
        //A[i] * A[j]がX未満の数がK個未満かどうか
        rep(i,N){
            if(A[i] == 0){
                if(X > 0){
                    cnt[i] = N - 1;
                    res += cnt[i];
                }
            }
            else if(A[i] > 0){
                //右が大きい
                //indexの二分探索を行う
                int ok = -1;
                int ng = N;
                while(ng - ok > 1){
                    int mid = (ok + ng) / 2;
                    if(A[i] * A[mid] < X)ok = mid;
                    else ng = mid;
                }
                cnt[i] = ok + 1;
                if(A[i] * A[i] < X)cnt[i]--;
                res += cnt[i];
            }
            //A[i] < 0
            else{
                //左が大きい
                int ng = -1;
                int ok = N;
                while(ok - ng > 1){
                    int mid = (ok + ng) / 2;
                    if(A[i] * A[mid] < X)ok = mid;
                    else ng = mid;
                }
                cnt[i] = N - ok;
                if(A[i] * A[i] < X)cnt[i]--;
                res += cnt[i];
            }
        }
        return res/2 < K;
    };
    ll ok = -INFLL-1;
    ll ng = +INFLL+1;

    while(ng - ok > 1){
        ll mid = (ok + ng)/2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout<<ok<<endl;
}