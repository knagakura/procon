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
    vector<ll> cnt(N,0);
    rep(i,N){
        ll t = (X-H[i])/S[i];
        if(X-H[i]<0)return false;
        //N-1秒以内のものだけ。それより後でもいいものはいつやってもいい
        if(t<N)cnt[t]++;
    }
    //累積和を取ることでt秒以内の数を数え上げられる
    //cum[t]:t秒以内に処理するべき個数
    //1秒で一個しか処理できないので、それがt+1を越えるとき、false
    vector<ll> cum(N,0);
    cum[0] = cnt[0];
    for(int i = 0; i < N-1; ++i){
        cum[i+1] = cnt[i+1]+cum[i];
    }
    //cerr<<X<<endl;
    //print(cnt);print(cum);
    rep(t,N){
        if(cum[t]>t+1){
            //cerr<<"false"<<endl;
            return false;
        }
    }
    //cerr<<"true"<<endl;
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