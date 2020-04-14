#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int A[100][100];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N = 100;
    rep(i,N)rep(j,N){
        cin>>A[i][j];
    }
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> rand99(0, 99);
    uniform_int_distribution<> rand100(0, 100);
    cout<<1000<<endl;
    rep(loop, 1000){
        cout<<rand99(mt)<<" "<<rand99(mt)<<" "<<rand100(mt)<<endl;
    }
}