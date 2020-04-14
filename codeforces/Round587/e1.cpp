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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<ll> q(N);
    rep(i,N)cin>>q[i];
    vector<ll> v;
    for(ll i = 1; i < 1e5; ++i){
        int z = to_string(i).size();
        ll x = (i * (i+1)) / 2 + (z-1) * (i - pow(10,z-1) + 1);
        /*
        if(i<20){
            cerr<<i<<": "<<x<<endl;
        }
        */
        v.push_back(x);
    }
    print(v);
    //print(v);
    rep(i,N){
        auto position = lower_bound(all(v), q[i]);
        int idx_lower = distance(v.begin(), position);
        cerr<<"今求めたいやつ: " <<q[i]<<endl;
        cerr<<"それが含まれるブロック番号: "<<idx_lower + 1<<endl;
        cerr<<"最後の数字が何番目か: "<<v[idx_lower]<<endl;
    }
}