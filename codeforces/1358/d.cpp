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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, x;
    cin >> N >> x;
    vec<ll> d(N);
    rep(i, N)cin >> d[i];
    rep(i,N)d.push_back(d[i]);
    int r = 0;
    ll sum = 0;
    ll ans = 0;
    rep(l, 2*N) {
        while (r < 2*N && sum + d[r] <= x) {
            sum += d[r];
            r++;
        }
        if (sum == x)chmax(ans, sum);
        else {
            ll diff = x - sum;
            ll tmp = sum;
            if(l == 0)chmax(ans, tmp);/*usironodiffこ*/
            else{
                if(d[l-1] >= diff){
                    tmp += d[l-1] * (d[l-1]+1)/2 - (d[l-1]-diff) * (d[l-1]-diff+1) / 2;
                }
                else{
                    tmp += d[l-1] * (d[l-1]+1)/2;
                }
                chmax(ans, tmp);
            }
        }
        sum -= d[l];
    }
    cout << ans << endl;

}