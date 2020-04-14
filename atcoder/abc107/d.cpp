#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef long long ll;
const ll INFLL = (ll)1e18+1;

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N, 0);
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
};

int main() {

    ll N;
    cin >> N;
    ll half = (N+1) * N / 4;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    if(N == 1){
        cout << a[0] << endl;
        return 0;
    }
    ll ok = 0;
    ll ng = INFLL;

    // 中央値がX以上になる区間が半分以上あるか？
    auto check = [&](ll X){
        vector<ll> b(N);
        rep(i,N)b[i] = ((a[i] >= X) ? 1: -1);
        vector<ll> cum(N+1);
        rep(i,N)cum[i+1] = cum[i] + b[i];
        BIT<ll> Tree(2 * N + 10);
        ll cnt = 0;
        rep(i,N+1){
            cnt += Tree.sum(cum[i]+N+1);
            Tree.add(cum[i]+N+1, 1);
        }
        return half  <= cnt;
    };

    while(ng - ok  > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}