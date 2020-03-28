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

    ll X, Y, A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<pair<ll, int>> v;
    rep(i,A){
        ll p;
        cin >> p;
        v.push_back({p, 0});
    }
    rep(i,B){
        ll p;
        cin >> p;
        v.push_back({p, 1});
    }
    rep(i,C){
        ll p;
        cin >> p;
        v.push_back({p, 2});
    }
    sort(all(v));
    reverse(all(v));
    //printpair(v);
    ll cnt[] = {0,0,0};
    /*
    ll dp[v.size()+1][2];
    rep(i,v.size()+1)rep(j,2){
        dp[i][j] = -1;
    }*/
    ll ans = 0;
    ll sum = 0;
    rep(i,v.size()){
        int id = v[i].second;
        int cost = v[i].first;
        if(id == 0){
            if(cnt[id] == X)continue;
            if(sum == X + Y)continue;
            cnt[id]++;
            sum++;
            ans += cost;
        }
        if(id == 1){
            if(cnt[id] == Y)continue;
            if(sum == X + Y)continue;
            cnt[id]++;
            sum ++;
            ans += cost;
        }
        if(id == 2){
            if(sum == X + Y)continue;
            cnt[id]++;
            sum++;
            ans += cost;
        }
    }
    cout << ans << endl;
}