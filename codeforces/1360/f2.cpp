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
void solve() {
    int N, M;
    cin >> N >> M;
    vec<string> a(N);
    rep(i, N)cin >> a[i];
    auto diff = [&](string &x, string &y) {
        int res = 0;
        rep(i, M) {
            if (x[i] != y[i])res++;
        }
        return res;
    };
    auto check = [&](string &s)->bool{
        vec<int> cnt(N,0);
        rep(i,N){
            cnt[i] = diff(s, a[i]);
        }
        int mx = *max_element(all(cnt));
        return mx <= 1;
    };
    for (int k = 0; k < 26; k++) {
        rep(i, M) {
            //a[0]のi文字目をkに変えて、満たされるか確認
            string tmp = a[0];
            tmp[i] = char('a' + k);
            if(check(tmp)){
                cout << tmp << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while (t--) solve();
}