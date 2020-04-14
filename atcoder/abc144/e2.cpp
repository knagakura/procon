#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;

ll N,K;
vector<ll> A,F;

//成績をXに以下にできるかどうか
bool solve(ll X){
    ll cnt = 0;
    rep(i,N){
        cnt += max((ll)0, A[i] - X/F[i]);
    }
    return cnt <= K;
}

int main() {
    //入力
    cin>>N>>K;
    A.resize(N);
    F.resize(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>F[i];

    //AとFの対応関係
    sort(all(A));
    sort(all(F), greater<ll>());

    //めぐる式二分探索
    ll ng = -1;
    ll ok = 1e12 + 1;
    while(ok-ng > 1){
        ll mid = (ok + ng)/2;
        if(solve(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}