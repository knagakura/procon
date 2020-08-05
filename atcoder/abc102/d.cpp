#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = (ll)1e18+1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    vector<ll> cum(N+1,0);
    rep(i,N)cum[i+1] = A[i] + cum[i];
    ll ans = INFLL;
    auto calc = [&](int l, int mid, int r) -> ll{
        ll sums[] = {
            cum[l] - cum[0],
            cum[mid] - cum[l],
            cum[r] - cum[mid],
            cum[N] - cum[r]
        };
        ll maxx = 0;
        ll minn = INFLL;
        rep(j,4){
            chmax(maxx, sums[j]);
            chmin(minn, sums[j]);
        }
        return maxx - minn;
    };
    for(int i = 2; i < N-1; i++){
        int l[2], r[2];
        // [0, i)
        {
            ll sum = cum[i] - cum[0];
            int ok = 1;
            int ng = i-1;
            while(abs(ok - ng) > 1){
                int mid = (ok + ng) >> 1;
                ll tmp = cum[mid] - cum[0];
                if(2*tmp <= sum)ok = mid;
                else ng = mid;
            }
            l[0] = ok;
        }
        {
            ll sum = cum[i] - cum[0];
            int ng = 1;
            int ok = i-1;
            while(abs(ok - ng) > 1){
                int mid = (ok + ng) >> 1;
                ll tmp = cum[i] - cum[mid];
                if(2*tmp <= sum)ok = mid;
                else ng = mid;
            }
            l[1] = ok;
        }
        // [i, N)
        {
            ll sum = cum[N] - cum[i];
            int ok = i+1;
            int ng = N-1;
            while(abs(ok - ng) > 1){
                int mid = (ok + ng) >> 1;
                ll tmp = cum[mid] - cum[i];
                if(2*tmp < sum)ok = mid;
                else ng = mid;
            }
            r[0] = ok;
        }
        {
            ll sum = cum[N] - cum[i];
            int ng = i+1;
            int ok = N-1;
            while(abs(ok - ng) > 1){
                int mid = (ok + ng) >> 1;
                ll tmp = cum[N] - cum[mid];
                if(2*tmp < sum)ok = mid;
                else ng = mid;
            }
            r[1] = ok;
        }
        rep(j,2)rep(k,2){
            chmin(ans, calc(l[j], i, r[k]));
        }
    }
    cout << ans << endl;
}
