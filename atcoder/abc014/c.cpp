#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    for(int i = 0; i < (int)v.size(); ++i){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    ll maxb = 0;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a[i]>>b[i];
        chmax(maxb, b[i]);
    }

    vector<ll> imos(maxb+5);
    rep(i,N){
        imos[a[i]]++;
        imos[b[i]+1]--;
    }
    auto cum = cumulative_sum(imos);

    ll ans = 0;
    rep(i,(int)cum.size()){
        chmax(ans, cum[i]);
    }
    cout<<ans<<endl;
}