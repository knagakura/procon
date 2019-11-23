#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
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

    int N,M;
    cin>>N>>M;
    vector<ll> s(M),t(M);
    rep(i,M){
        cin>>s[i]>>t[i];
        s[i]--;
        t[i]--;
    }
    vector<ll> imos(N+5);
    rep(i,M){
        imos[s[i]]++;
        imos[t[i]+1]--;
    }
    auto cum_imos = cumulative_sum(imos);
    
    vector<int> a(N+6);
    rep(i,N+6){
        if(cum_imos[i]==1)a[i]++;
    }
    auto cum_a = cumulative_sum(a);

    int cnt = 0;
    rep(i,M){
        if(cum_a[t[i]+2] - cum_a[s[i]+1] == 0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    rep(i,M){
        if(cum_a[t[i]+2] - cum_a[s[i]+1] == 0){
            cout<<i+1<<endl;
        }
    }
    /*
    print(imos);
    print(cum_imos);
    print(a);
    print(cum_a);
    */
}