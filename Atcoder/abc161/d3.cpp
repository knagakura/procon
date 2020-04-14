#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

int main() {

    ll K;
    cin >> K;
    // Xを桁ごとのvectorに変換
    auto ll2vec = [&](ll X){
        vector<int> res;
        ll tmp = X;
        while(tmp > 0){
            res.push_back(tmp%10);
            tmp/=10;
        }
        reverse(all(res));
        return res;
    };
    auto check = [&](ll X){
        vector<int> vx = ll2vec(X);
        //桁数
        int N = vx.size();
        // dp[i][smaller][0以外を一度でも取ったか][最後の数字]
        ll dp[N+1][2][2][10];
        rep(i,N+1)rep(j,2)rep(k,2)rep(l,10)
            dp[i][j][k][l] = 0;
        dp[0][0][0][0] = 1;
        //dpの遷移
        for(int i = 0; i < N; i++)rep(j,2)rep(k,2)rep(l,10){
            int min_nxt = max(0, l-1);
            int max_nxt = min(l+1, (j ? 9:vx[i]));
            if(!k)max_nxt = j ? 9:vx[i];
            for(int nxt = min_nxt; nxt <= max_nxt; nxt++){
                dp[i+1][j || nxt < vx[i]][k || nxt][nxt] +=  dp[i][j][k][l];
            }
        }
        ll cnt = 0;
        rep(j,2)rep(l,10)cnt += dp[N][j][1][l];
        return cnt >= K;
    };

    ll ng = 0;
    ll ok = 3234566667;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}