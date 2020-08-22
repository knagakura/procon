#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,N) for(ll i=0;i<ll(N);++i)
#define rep1(i,N) for(ll i=1;i<ll(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
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
#define int long long

const int INF = (ll)1e9;
const ll INFLL = (ll)1e17;
const ll MOD = 1'000'000'007;
// const ll MOD = 998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
ll N,K;
vector<ll> P,C;
vvec<int> vs;
vector<bool> used;
void dfs(int cur, int pre, vector<int> &v){
    if(used[cur]){
        vs.emplace_back(v);
        return;
    }
    v.emplace_back(cur);
    used[cur] = true;
    dfs(P[cur], cur, v);
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> K;
    P.resize(N);
    C.resize(N);
    rep(i,N){
        cin >> P[i];
        P[i]--;
    }
    rep(i,N)cin >> C[i];
    used.assign(N,false);
    rep(i,N){
        if(used[i])continue;
        vector<int> v;
        dfs(i,-1,v);
    }

    auto calc = [&](vector<int> &v) -> ll{
        int M = v.size();
        ll v_sum = 0;
        rep(i,M)v_sum += C[v[i]];
        ll cycle_cnt = K / M;
        ll rem = K % M;
        vector<ll> c_tmp;
        vector<ll> cum(3*M+1,0);
        rep(_,3)rep(i,M)c_tmp.emplace_back(C[v[i]]);
        rep(i,3*M)cum[i+1] = cum[i] + c_tmp[i];
        if(v_sum < 0){
            // 長さK以下
            ll tmp = *max_element(all(c_tmp));
            rep(j,3*M+1)rep(i,j){
                if(j - i > min(M,K))continue;
                chmax(tmp, cum[j] - cum[i]);
            }
            return tmp;
        }
        // 長さrem以下
        else{
            ll res = cycle_cnt * v_sum;
            ll tmp;
            if(cycle_cnt > 0)tmp = 0;
            else tmp = *max_element(all(c_tmp));
            rep(j,3*M+1)rep(i,j){
                if(j - i > rem)continue;
                chmax(tmp, cum[j] - cum[i]);
            }
            res += tmp;
            if(cycle_cnt > 0){
                ll res2 = (cycle_cnt-1) * v_sum;
                ll tmp2 = 0;
                rep(j,3*M+1)rep(i,j){
                    if(j - i > M)continue;
                    chmax(tmp2, cum[j] - cum[i]);
                }
                res2 += tmp2;
                chmax(res, res2);
            }
            return res;
        }
    };
    ll ans = -INFLL;
    for(auto v: vs)chmax(ans, calc(v));
    cout << ans << endl;
}
