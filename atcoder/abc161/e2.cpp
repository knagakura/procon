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

    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> v;
    rep(i,N){
        if(S[i] == 'o')v.emplace_back(i);
    }
    //前から見たときのやつ
    //map<int, int> mae;
    vector<int> mae(K+1);
    int sz = v.size();
    int pre = v[0];
    int cnt = 1;
    mae[cnt] = pre;
    while(cnt < K){
        int next = *lower_bound(all(v), pre + C+1);
        cnt++;
        mae[cnt] = next;
        pre = next;
    }

    //逆から
    //map<int, int> usi;
    vector<int> usi(K+1);
    pre = v[sz-1];
    cnt = K;
    usi[cnt] = pre;
    while(cnt > 1){
        int idx = upper_bound(all(v), pre - C - 1) - v.begin();
        int next = v[idx-1];
        cnt--;
        usi[cnt] = next;
        pre = next;
    }
    rep1(i,K+1){
        if(mae[i] == usi[i]){
            cout << mae[i]+1 << endl;
        }
    }
}