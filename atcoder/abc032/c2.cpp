#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,K;
    cin>>N>>K;
    vector<ll> s(N);
    bool flag = false;
    ll mins = INFLL;
    rep(i,N){
        cin>>s[i];
        if(s[i] == 0){
            flag = true;
        }
        chmin(mins, s[i]);
    }
    if(flag){
        cout<<N<<endl;
        return 0;
    }
    if(mins > K){
        cout<<0<<endl;
        return 0;
    }
    ll sum = s[0];
    ll ans = 0;
    int r = 1;
    rep(l,N){
        while(r < N && sum <= K){
            cerr<<sum<<endl;
            cerr<<sum<<"*="<<s[r]<<endl;
            sum *= s[r];
            r++;
        }
        chmax(ans, (ll)r-l-1);
        cerr<<l<<" "<<r<<" "<<sum<<endl;
        sum /= s[l];
    }
    cout<<ans<<endl;
}