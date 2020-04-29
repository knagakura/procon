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

    int N;
    cin >> N;
    deque<ll> B,B2;
    rep(i, N) {
        ll a;
        cin >> a;
        B.push_back(a);
        B2.push_back(a);
    }
    sort(all(B));
    sort(all(B2));
    deque<ll> w,w2;
    w.push_front(B.front());
    B.pop_front();

    w2.push_front(B2.back());
    B2.pop_back();
    auto f = [&](deque<ll> &A, deque<ll>& v, int x) -> ll{
        ll res = 0;
        int sz = A.size();
        for (int i = 0; i < sz / 2; i++) {
            if ((i+x) & 1) {
                //最小を二つ入れる
                ll nax1 = A.front();
                A.pop_front();
                ll nax2 = A.front();
                A.pop_front();
                ll add1 = abs(nax1 - v.back()) + abs(nax2 - v.front());
                ll add2 = abs(nax1 - v.front()) + abs(nax2 - v.back());
                res += max(add1, add2);
                v.push_back(nax1);
                v.push_front(nax2);
            } else {
                //最大を二つ入れる
                ll nax1 = A.back();
                A.pop_back();
                ll nax2 = A.back();
                A.pop_back();
                ll add1 = abs(nax1 - v.back()) + abs(nax2 - v.front());
                ll add2 = abs(nax1 - v.front()) + abs(nax2 - v.back());
                res += max(add1, add2);
                v.push_back(nax1);
                v.push_front(nax2);
            }
        }
        if (A.size() == 1) {
            res += max(abs(v.back() - A[0]),
                       abs(v.front() - A[0]));
        }
        return res;
    };

    ll ans = max(f(B,w,0), f(B2,w2,1));
    cout << ans << endl;
}