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

int N;
vector<string> S;

//s -> t
bool check(int dx, int dy) {
    //写す
    string tmp;
    rep(i,N)tmp.push_back('.');
    vector<string> t(N, tmp);
    rep(i, N)rep(j, N) {
            int nx = (i + dx) % N;
            int ny = (j + dy) % N;
            t[nx][ny] = S[i][j];
        }
    //check
    rep(i, N)rep(j, N) {
            if (t[i][j] != t[j][i]) {
                return false;
            }
        }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    S.resize(N);
    rep(i, N)cin >> S[i];
    ll ans = 0;
    //(0,0)でどうなるかが(i,i)と同じ
    if (check(0, 0)){
        ans += N;
    }
    //aのみを1~N-1まで全探索
    //(a,0)が(a+j,j)と同じ
    rep1(a, N) {
        if (check(a, 0)){
            ans += N - a;
        }
    }
    //bのみを1~N-1まで全探索
    //(0,b)が(i,i+b)と同じ
    //N = 4
    //(0,0), (1,1), (2,2), (2,3)
    //(0,1), (1,2), (2,3)
    //(0,2), (2,3)
    //(0,3)
    rep1(b, N) {
        if (check(0, b)){
            ans += N - b;
        }
    }
    cout << ans << endl;
}