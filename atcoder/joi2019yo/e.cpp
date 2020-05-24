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
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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

    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    vector<i_i> LR;
    rep(i,M){
        int l, r;
        cin >> l >> r;
        l--;r--;
        LR.emplace_back(l,r);
    }
    sort(all(LR));
    vector<i_i> v;
    v.push_back(LR[0]);
    map<int,int> mp;
    rep1(i,M){
        int x = v.back().first;
        int y = v.back().second;
        int nx = LR[i].first;
        int ny = LR[i].second;
        //次が包含されるなら
        if(x <= nx && ny <= y)continue;
        //既に入ってるやつが包含されるなら
        else if(nx <= x && y <= ny){
            v.pop_back();
        }
        v.emplace_back(nx, ny);
    }

    for(auto &p: v){
        mp[p.first]++;
        mp[p.second]++;
    }
    vector<int> imos(N+1,0);
    for(auto &p: v){
        imos[p.first]++;
        imos[p.second+1]--;
    }
    rep(i,N)imos[i+1]+=imos[i];
    imos.back() = -1;
    ll dp[N+1][3];
    rep(i,N+1)rep(j,3)dp[i][j] = 0;
    ll range_max = 0;
    //print(LR);
    //print(v);
    //print(imos);
    //print(mp);
    rep(i,N){
        if(imos[i] == 0){
            chmax(dp[i+1][0],dp[i][0]+A[i]);
            chmax(dp[i+1][0],dp[i][1]+A[i]);
            chmax(dp[i+1][0],dp[i][2]+A[i]);
            //continue;
        }
        chmax(range_max, A[i]);
        chmax(dp[i+1][0],dp[i][0]);
        chmax(dp[i+1][1],dp[i][1]);
        chmax(dp[i+1][2],dp[i][2]);
        //区間の終わり
        if(imos[i] != imos[i+1] || mp[i+1] > 0){
            //if(imos[i] == 0 && imos[i+1] == 1){}
            if(imos[i] == 1 && imos[i+1] == 1){
                //dump(i);
                chmax(dp[i+1][1], dp[i][0]+range_max);
                chmax(dp[i+1][0],dp[i][1]);
            }
            if(imos[i] == 1 && imos[i+1] == 0){
                chmax(dp[i+1][1], dp[i][0]+range_max);
                chmax(dp[i+1][0],dp[i][1]);
            }
            if(imos[i] == 1 && imos[i+1] == 2){
                chmax(dp[i+1][1], dp[i][0]+range_max);
                chmax(dp[i+1][0],dp[i][1]);
            }
            if(imos[i] == 2 && imos[i+1] == 1){
                chmax(dp[i+1][1], dp[i][0]+range_max);
                chmax(dp[i+1][0],dp[i][1]);
            }
            if(imos[i] == 1 && imos[i+1] == -1){
                //dump(i);
                //dump(range_max);
                chmax(dp[i+1][1], dp[i][0]+range_max);
                chmax(dp[i+1][0],dp[i][1]);
            }
            range_max = 0;
        }
    }
    //rep(i,N+1)print(dp[i]);
    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << endl;
}
