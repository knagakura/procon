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
ll N,K,Z;
vector<ll> A,F,T;
bool solve(ll x){
    ll sumb = 0;
    rep(i,N){
        ll B = min(A[i],x/F[i]);
        sumb += B;
    }
    //cerr<<x<<" "<<sumb<<endl;
    return sumb>=Z;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>K;
    A.resize(N);
    F.resize(N);
    ll suma = 0;
    rep(i,N){
        cin>>A[i];
        suma += A[i];
    }
    rep(i,N){
        cin>>F[i];
    }
    Z = suma - K;
    if(Z<=0){
        cout<<0<<endl;
        return 0;
    }
    sort(all(A),greater<ll>());
    sort(all(F));
    /*
    rep(i,N)T.push_back(A[i]*F[i]);
    print(A);print(F);print(T);
    */
    ll ok = 1e13;
    ll ng = -1;

    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(solve(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}