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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
        A[i]--;
    }
    vector<ll> S(N+1);
    rep(i,N){
        S[i+1] = S[i] + A[i];
        S[i+1] %= K;
    }
    map<int, int> map;
    ll ans = 0;
    queue<int> q;
    rep(i,N+1){
        ans += map[S[i]];
        map[S[i]]++;
        q.push(i);
        if((int)q.size() == K){
            int top = q.front();
            q.pop();
            map[S[top]]--;
        }
    }
    cout<<ans<<endl;
}