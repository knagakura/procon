#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    //積がX未満の数がK個未満かどうか
    auto check = [&](ll X){
        ll res = 0;
        vector<ll> cnt(N,0);
        rep(i,N){
            if(A[i] > 0){
                // 昇順の単調性
                int l = -1;
                int r = N;
                while(r - l > 1){
                    //cerr<<l<<" "<<r<<endl;
                    int mid = (l + r) / 2;
                    if(A[i] * A[mid] < X)l = mid;
                    else r = mid;
                }
                if(i <= l)l--;
                cnt[i] += l+1;
            }
            else{
                //降順の単調性
                int l = -1;
                int r = N;
                while(r - l > 1){
                    //cerr<<l<<" "<<r<<endl;
                    int mid = (l + r) / 2;
                    if(A[i] * A[mid] < X)r = mid;
                    else l = mid;
                }
                if(r <= i)r++;
                cnt[i] += N - r;
            }
            res += cnt[i];
        }
        
        //cerr<<X<<"未満の数は"<<res/2<<"個"<<endl;
        //print(cnt);
        return res/2 < K;
    };
    ll ok = -INFLL - 1;
    ll ng = INFLL + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    //print(A);
    cout<<ok<<endl;
}