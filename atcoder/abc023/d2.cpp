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
const ll INFLL = 1LL << 60;
ll N;
vector<ll> H,S;

bool check(ll X){
    //cnt[t]:t秒以内に処理しろ！
    vector<ll> T;
    rep(i,N){
        ll t = (X-H[i])/S[i];
        if(X-H[i]<0)return false;
        //N-1秒以内のものだけ。それより後でもいいものはいつやってもいい
        T.push_back(t);
    }
    sort(all(T));
    rep(i,N){
        if(T[i]<i){
            return false;
        }
    }
    return true;
}
int main() {
    cin>>N;
    H.resize(N);S.resize(N);
    rep(i,N){
        cin>>H[i]>>S[i];
    }
    ll ng = 0, ok = INFLL;
    while(ok-ng>1){
        ll mid = (ok + ng)/2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}