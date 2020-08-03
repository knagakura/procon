#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define printo(v) { cout<<#v<<": [ "; for(auto _ : v) cout<<_<<", "; cout<<"]"<<endl; }
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
    ll M = 2*N-1;
    vector<int> a;
    rep(i,M)a.emplace_back(i+1);
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    sort(all(a));
    set<int> st; 
    do{
        vvec<int> v(N,vec<int>(M,0));
        v[0] = a;
        rep1(i,N){
            for(int j = i; j < M-i;j++){
                vector<int> vv;
                for(int k = -1; k <= 1; k++){
                    vv.emplace_back(v[i-1][j+k]);
                }
                sort(all(vv));
                v[i][j] = vv[1];
            }
        }
        rep(i,N)printo(v[i]);
        cout << endl;
        st.insert(v.back()[N-1]);
    }while(next_permutation(all(a)));   
    printo(st);
}
