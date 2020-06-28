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

    int N;
    cin >> N;
    vector<int> v, v2;
    ll cnt_ = 0;
    for(int i = 0; i < bit(N+1); i++){
        v.push_back(i);
        v2.push_back(cnt_);
        if(i&1)cnt_++;
    }
    print(v);
    print(v2);
    sort(all(v));
    map<vector<int>, int> mp;
    auto calc = [&](vector<int> &w){
        set<int> res;
        for(int i = 0; i < bit(N);i++){
            int prod = 0;
            int cnt = 0;
            for(int j = 0; j < bit(N+1); j++){
                if(w[j] == i){
                    cnt++;
                }
                else if(cnt == 1)prod ^= w[j];
                if(cnt == 2)break;
            }
            res.insert(prod);
        }
        return res;
    };
    int count  = 0;
    int ans = 0;
    do{
        vector<int> tmp(bit(N+1));
        for(int i = 0; i < bit(N+1); i++){
            tmp[i] = v2[v[i]];
        }
        if(mp.count(tmp))continue;
        mp[tmp]++;
        auto st = calc(tmp);
        if(st.size() == 1 && *st.begin() != 0){
            print(tmp);
            print(st);
            ans++;
        }
        if(count % 1000 == 0){
            dump(count);
            dump(ans);
        }
        count++;
    }while(next_permutation(all(v)));
}
