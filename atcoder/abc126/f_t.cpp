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
const ll MOD = 1'000'000'007;
// const ll MOD = 998244353;
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


    ll M;
    cin >> M;
    M = bit(M+1);
    vector<int> v;
    rep(i,M)v.emplace_back(i);
    vector<int> w;
    rep(i,M/2){
        w.emplace_back(i);
        w.emplace_back(i);
    }
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    sort(all(v));
    map<vector<int>, int> mp;
    auto calc = [&](const vector<int>&t) -> set<int>{
        set<int> res;
        rep(j,M){
            rep(i,j){
                if(t[i] == t[j]){
                    ll val = 0;
                    for(int k = i; k <= j; k++){
                        val ^= t[k];
                    }
                    res.insert(val);
                }
            }
        }
        return res;
    };
    ll cnt = 0;
    do{
        vector<int> tmp(M);
        rep(i,M)tmp[v[i]] = w[i];
        cnt++;
        if(cnt%100000000 == 0){
            dump(cnt);
        }
        if(mp[tmp] > 0)continue;
        mp[tmp]++;
        auto vals = calc(tmp);
        if(vals.size() == 1 && *vals.begin() != 0){
            print(vals);
            print(tmp);
        }
    }while(next_permutation(all(v)));
}
