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
template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    for(int i = 0; i < (int)v.size(); ++i){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}
/*使うとき
vector<int> a(N);
auto cum = cumlative_sum(a)
とするとvector<int> cumが生成される

i番目までの仕切りの和
cum[i]: [0,i)の和（半開区間）

要素i~jの和が欲しい時
j+1 ~ i番目の仕切りまで数えればよい
int sum = cum[j+1]-cum[i]
*/
/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,M;
    cin>>N>>M;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A),greater<ll>());
    print(A);
    auto check = [&](int i,int x){
        //cerr<<i<<" "<<x<<" "<<A[i]+A[x]<<" "<<A[x-1] * 2<<endl;
        return ((A[i] + A[x]) <= (A[x - 1] * 2));
    };
    vector<bool> doublee(N,false);
    auto cumsum = cumulative_sum(A);
    ll ans = 0;
    rep(i,N){
        for(int j = i+1;j+1 < N;j++){
            if(A[i] + A[j+1] > A[j] * 2){
                doublee[j] = true;
                ans +=  A[j] * 2;
                break;
            }
        }
    }
}