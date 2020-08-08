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

    ll N;
    cin >> N;
    map<ll,int> mp;
    vector<ll> A(N);
    rep(i, N){
        cin >> A[i];
        mp[A[i]]++;
    }
    ll sq = 0;
    ll cnt = 0;
    for(auto p: mp){
        cnt += p.second / 2;
        sq += p.second / 4;
    }
    int Q;
    cin >> Q;
    vector<char> type(Q);
    vector<ll> x(Q);
    rep(i,Q){
        cin >> type[i] >> x[i];
        if(type[i] == '+'){
            mp[x[i]]++;
            if(mp[x[i]]%2 == 0)cnt++;
            if(mp[x[i]]%4 == 0)sq++;
        }
        else {
            mp[x[i]]--;
            if(mp[x[i]]%2 == 1)cnt--;
            if((mp[x[i]]+1)%4 == 0)sq--;
        }
        // dump(sq);
        // dump(cnt);
        // print(mp);
        if(sq == 0){
            cout << "NO" << endl;
            continue;
        }
        // sq >= 1なので正方形一個は作れる
        // 長方形がもう一個作れるかどうか
        if(cnt >= 4){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
