#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, Q;
    cin >> N >> Q;
    vec<ll> x(N), w(N);
    vec<pair<ll, ll>> xw(N);
    rep(i,N){
        cin >> xw[i].first >> xw[i].second;
    }
    sort(all(xw));
    rep(i,N){
        x[i] = xw[i].first;
        w[i] = xw[i].second;
    }
    vec<ll> xq(Q);
    rep(i,Q){
        cin >> xq[i];
    }
    //print(x);print(w);print(xq);
    vec<ll> cumw(N+1, 0);
    rep(i,N)cumw[i+1] = cumw[i] + w[i];
    //print(cumw);
    //x[i]にいるときにかかる合計のコスト
    vec<ll> cost(N, 0);
    rep(i,N){
        cost[0] += abs(x[0] - x[i]) * w[i]; 
    }
    rep1(i,N){
        cost[i] = cost[i-1];
        //[0, i)
        ll lsum = cumw[i] - cumw[0];
        //[i, N)
        ll rsum = cumw[N] - cumw[i];
        //cerr << lsum << " " <<  rsum << endl;
        cost[i] -= abs(x[i-1] - x[i]) * rsum;
        cost[i] += abs(x[i-1] - x[i]) * lsum;
    }
    //print(cost);
    print(x);
    print(w);
    print(cumw);
    print(cost);
    rep(i,Q){
        int idx = lower_bound(all(x), xq[i]) - x.begin();
        //x[idx-1]より大きい、x[idx]以下
        //dump(idx);
        /*
        if(x[idx] == xq[i]){
            cout << cost[idx] << endl;
            continue;
        }
        */
        ll ans = cost[idx];
        if(idx == N){
            ans += cumw[idx] * abs(x[N-1] - xq[i]);
            cout << ans << endl;
        }
        else{
            ll diff = abs(x[idx] - xq[i]);
            //[0, idx)
            ll lsum = cumw[idx] - cumw[0];
            //[idx, N)
            ll rsum = cumw[N] - cumw[idx];
            ans += diff * rsum;
            ans -= diff * lsum;
            cout << ans << endl;
        }
    }
}