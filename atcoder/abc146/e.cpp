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

    int N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
        A[i] %= K;
    }
    print(A);

    auto cum = cumulative_sum(A);
    print(cum);
    for(int l = 0; l < N+1; l++){
        for(int r = l+1; r < N+2; r++){
            ll sum = cum[r] - cum[l] % K;
            ll length = r - l;
            if(sum == length){
                cerr<<l<<" "<<r<<" "<<sum<<endl;
            }
        }
    }
}