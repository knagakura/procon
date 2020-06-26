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
    vector<string> v;

    rep(i,26){
        string tmp;
        tmp += char(i + 'a');
        v.push_back(tmp);
    }
    rep(i,26)rep(j,26){
        string tmp;
        tmp += char('a' + i);
        tmp += char('a' + j);
        v.push_back(tmp);
    }
    
    rep(i,26)rep(j,26)rep(k,26){
        string tmp;
        tmp += char('a' + i);
        tmp += char('a' + j);
        tmp += char('a' + k);
        v.push_back(tmp);
    }
    auto comp = [](string &a, string &b){
        if(a.size() == b.size())return a < b;
        else{
            return a.size() < b.size();
        }
    };
    sort(all(v), comp);
    print(v);
    int size = v.size();
    int cnt = 0;
    rep(i,size){
        cout << cnt << " " << v[i]<< endl;
        cnt++;
        if(v[i].size() != v[i+1].size())cnt = 0;
    }

}