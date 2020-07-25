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

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<pair<char,int>> T;
    rep(i,N)T.emplace_back(S[i],i);
    sort(all(T));
    // print(S);
    // print(T);
    vector<bool> moved(N,false);
    vector<bool> used(N,true);
    string ans = S;
    int cnt = 0; // 変更箇所総数
    rep(i,N){
        char s = S[i];
        char t = T[i].first;
        int idx = T[i].second;
        if(s == t){
            ans[i] = s;
            continue; // 同じなら変更しない
        }
        // 異なる場合、変更できるならする
        int add = 0;
        if(!moved[i])add++;
        if(!moved[idx])add++;
        if(cnt + add > K)continue; // 移動させると不可能
        cnt += add;
        ans[i] = t;
        used[i] = false;
        moved[i] = true;

        if(not moved[idx]){
            ans[idx] = ' ';
            used[idx] = true;
            moved[idx] = true;
        }
        // dump(i);
        // dump(cnt);
        // dump(ans);
    }
    rep(i,N){
        if(ans[i] == ' '){
            rep(j,N){
                if(not used[j]){
                    ans[i] = S[j];
                    used[j] = true;
                }
            }
        }
    }
    // dump(ans);
    cout << ans << endl;
}

/*
流石に貪欲では・・・？

*/
