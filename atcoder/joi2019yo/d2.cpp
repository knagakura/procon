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

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N+1, 0);
    };
    
    // a is 1-indexed
    void add(int a, T w){
        for(int x = a; x <= N; x += x & -x)data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a){
        T res = 0;
        for(int x = a; x > 0; x -= x & -x)res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r){return sum(r) - sum(l-1);}

    // 0-indexed add
    void add0(int a, T w){add(a + 1, w);}
    // 0-indexed sum
    T sum0(int a){return sum(a + 1);}
    // 0-indexed sum of range
    T sum0(int l, int r){return sum0(r) - sum0(l-1);}
    // show the value
    void debug(){print(data);}
    void debug2(){
        vec<T> v;
        rep(i,N){
            v.push_back(sum0(i,i));
        }
        print(v);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<int> A;
    map<int,int> mp;
    A.push_back(0);
    mp[0]++;
    rep(i,N){
        int a;
        cin >> a;
        mp[a]++;
        if(A.back() == a)continue;
        A.push_back(a);
    }
    N = A.size();
    int cnt = 0;
    for(auto &p: mp){
        p.second = cnt;
        cnt++;
    }
    int sz = mp.size();
    vvec<int> v(sz, vec<int>());
    rep(i,N)v[mp[A[i]]].push_back(i);
    //print(mp);
    //for(auto v_:v)print(v_);
    //print(A);
    BIT<ll> Tree(N);
    vec<bool> used(N,false);
    ll ans = 0;
    rep(j,sz){
        /*check*/
        int szz = v[j].size();
        rep(i,szz){
            int idx = v[j][i];
            //右隣が自分より大きいなら、それが左端になる
            if(idx + 1 < N && not used[idx+1]){
                Tree.add0(idx+1,1);
            }
            //自分が左端になっていたら
            if(Tree.sum0(idx,idx) == 1)Tree.add0(idx,-1);
            used[idx] = true;
        }
        //Tree.debug2();
        chmax(ans, Tree.sum(N));
    }
    cout << ans << endl;
}