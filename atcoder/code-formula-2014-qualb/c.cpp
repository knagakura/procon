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

    string A, B;
    cin >> A >> B;
    int N = A.size();
    string S = A;
    string T = B;
    sort(all(S));
    sort(all(T));
    if(S != T){
        cout << "NO" << endl;
        return 0;
    }
    bool exist = false;
    rep(i,N-1){
        if(S[i] == S[i+1])exist = true;
    }
    //構成する文字数は同じ
    vec<int> v;
    rep(i,N){
        if(A[i] != B[i]){
            v.push_back(i);
        }
    }
    print(v);
    //巡回置換の次数を数える
    auto check = [&]()->bool{
        int m = v.size();
        if(m > 6)return false;
        //0,1,2回のswap
        if(exist){
            //0回で一致
            if(A == B)return true;
            //1回で一致
            rep(i,m)rep(j,m){
                if(i >= j)continue;
                string C = A;
                string D = B;
                swap(C[v[i]], C[v[j]]);
                swap(D[v[i]], D[v[j]]);
                if(C == D)return true;
            }
            //2回で一致
            rep(i,m)rep(j,m)rep(k,m)rep(l{
                if(i >= j)continue;
                string C = A;
                string D = B;
                swap(C[v[i]], C[v[j]]);
                swap(D[v[i]], D[v[j]]);
                if(C == D)return true;
            }
        }
        //3回ちょうどのswap

    };

    cout << (check() ? "YES" : "NO") << endl;
}