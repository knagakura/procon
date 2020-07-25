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
template<class T> inline bool chmin(T& a, T b) { if (a >= b) { a = b; return true; } return false; }

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

    int N, K;
    string S;
    cin >> N >> K >> S;
    auto diff = [&](string a, string b){
        int res = 0;
        rep(i,a.size())res += a[i] != b[i];
        return res;
    };
    vector<string> ans;
    string a = S;
    string sorted_a = S;
    sort(all(sorted_a));
    rep(i,N){
        // i文字目を変更するかどうか
        if(sorted_a[i] == a[i])continue;
        string tmp = S;
        char nxt = S[i];
        int idx = i;
        for(int j = i + 1; j < N; j++){
            if(sorted_a[j] == a[j])continue;
            if(chmin(nxt, S[j])){
                idx = j;
            }
        }
        swap(tmp[i], tmp[idx]);
        if(diff(a,tmp) <= K){
            ans.push_back(tmp);
        }
        swap(S,tmp);
    }
    sort(all(ans));
    if(ans.empty()){
        cout << a << endl;
    }
    else{
        cout << ans[0] << endl;
    }
}

/*

*/