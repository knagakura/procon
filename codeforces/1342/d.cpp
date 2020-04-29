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

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<int> a(N), c(K);
    rep(i,N)cin >> a[i];
    rep(i,K)cin >> c[i];
    //c_i以下のものがi+1個まで
    sort(all(a));
    print(a);
    vvec<int> ans(K);
    for(int i = 0; i < K; i++){
        if(a.size() == 0)break;
        print(a);
        int idx = upper_bound(all(a), c[i]) - a.begin();
        idx--;
        cerr << idx << endl;
        //それより右側全部とる
        int sz = a.size();
        int rcnt = (sz - idx - 1);
        while(rcnt--){
            if(a.empty())break;
            ans[i].push_back(a.back());
            a.pop_back();
        }
        int tmp = idx+1;
        while(tmp--){
            if(a.empty())break;
            ans[i].push_back(a.back());
            a.pop_back();
        }
    }
    rep(i,K){
        if(ans[i].size() == 0)break;
        cout << ans[i].size() << " ";
        rep(j,ans[i].size()){
            cout << ans[i][j] <<  " ";
        }
        cout << endl;
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    solve();
}