#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> C(N);
    rep(i, N)cin >> C[i];
    vector<int> cnt(N,0);
    rep(i,N)rep(j,N){
        if(i == j)continue;
        if(C[j]%C[i] == 0)cnt[j]++;
    }

    long double kai = 1;
    for(int i = 1; i <= N; i++)kai /= i;
    vector<long double> fact(N+1);
    fact[0] = kai;
    rep(i,N)fact[i+1] = fact[i] * (i+1);

    auto comb = [&](int a, int b) -> long double{
        if(a == 0 || b == 0)return 1;
        if(b > a)return 0;
        return fact[a] / fact[a-b] / fact[b] * kai;
    };
    auto perm = [&](int a, int b) -> long double{
        if(a == 0 || b == 0)return 1;
        if(b > a)return 0;
        return fact[a] / fact[a - b];
    };

    long double ans = 0; 
    // あるコインiが場所jにいて
    // 自分より左にk個、右にcnt[i] - k個おくときの場合の数
    // kは偶数のみ
    rep(i,N)rep(j,N){
        for(int k = 0; k <= j && k <= cnt[i]; k+=2){
            int S = cnt[i];
            if(k > j)continue;
            if(S-k > N-1-j)continue;
            long double tmp = comb(S,k) * perm(j,k) * perm(N-1-j,S-k) * fact[N-1-S];
            ans += tmp;
        }
    }
    cout << ans << endl;
}