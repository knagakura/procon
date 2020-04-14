#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

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

    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector<ll> F(N);
    rep(i,N)cin>>F[i];
    sort(all(A));
    sort(all(F));
    reverse(all(F));
    //print(A);print(F);

    auto check = [&](ll X){
        //最小値をXにするために必要な修行の回数cnt
        //これがK以下かどうか
        ll cnt = 0;
        rep(i,N){
            //dif
            cnt += max(0LL, A[i] - X/F[i]);
        }
        return cnt <= K;
    };
    //成績の最小値を求める
    ll ng = -1;
    ll ok = 1e13 + 1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}