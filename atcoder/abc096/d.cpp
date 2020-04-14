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
bool isprime(int v) {
    if (v == 1) return false;
    for (int i = 2; 1LL * i*i <= v; i++) if (v%i == 0) return false;
    return true;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    vector<int> prime;
    for(int i = 2; i < 55555; i++){
        if(isprime(i)){
            prime.push_back(i);
        }
    }
    vector<int> ans;
    rep(i,(int)prime.size()){
        if(prime[i]%5 == 1){
            ans.push_back(prime[i]);
        }
        if((int)ans.size() == N)break;
    }
    rep(i,N)cout<<ans[i]<<endl;
}