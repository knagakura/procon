#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
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

    ll N,K;
    cin>>N>>K;
    vector<ll> A(N),B(N);
    rep(i,N){
        cin>>A[i];
        B[i] = - A[i];
    }
    sort(all(A));
    sort(all(B));
    //X未満の数がK個未満かどうか
    auto check = [&](ll X){
        ll res = 0;
        //vector<ll> cnt(N, 0);
        rep(i,N){
            ll cnt = 0;
            //Aの左側を数える
            if(A[i]>=0){
                //indexの二分探索
                int ok = -1;
                int ng = N;
                while(ng - ok > 1){
                    int mid = (ok + ng) / 2;
                    if(A[i] * A[mid] < X)ok = mid;
                    else ng = mid;
                }
                //0-indexedなので
                cnt = ok + 1;
                if(A[i] * A[i] < X)cnt--;
            }
            
            //Bの左側を数える
            else if(A[i]<0){
                //indexの二分探索
                int ok = -1;
                int ng = N;
                while(ng - ok > 1){
                    int mid = (ok + ng) / 2;
                    if(B[N-1-i] * B[mid] < X)ok = mid;
                    else ng = mid;
                }
                cnt = ok + 1;
                if(B[N-1-i] * B[N-1-i] < X)cnt--;
            }
            res += cnt;
        }
        return res/2 < K;
    };

    ll ok = - INFLL -1;
    ll ng = INFLL + 1;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout<<ok<<endl;
}