#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

template<typename T>
vector<T> divisor(T N) {
    vector<T> res;
    for(T i = 1; i * i <= N; i++){
        if(N % i == 0){
            res.push_back(i);
            if(i * i != N)res.push_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


void solve(){
    int N;
    cin >> N;
    vector<ll> v(N);
    vector<l_l> vidx;
    rep(i,N){
        cin >> v[i];
        vidx.emplace_back(v[i], i+1);
    }
    sort(all(vidx));
    vector<ll> cnt(N+1, -1);
    rep(i,N){
        ll idx = vidx[i].second;
        if(idx == 1){
            cnt[idx] = 1;
            continue;
        }
        auto _divisor = divisor(idx);
        cnt[idx] = 1;
        for(auto &p: _divisor){
            if(cnt[p] == -1)continue;
            if(v[p-1] == v[idx-1])continue;
            chmax(cnt[idx], cnt[p]+1);
        }
    }
    ll ans = *max_element(all(cnt));
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
}