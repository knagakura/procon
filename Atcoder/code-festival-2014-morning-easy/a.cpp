#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
    cout << fixed << setprecision(20);
    long double N;
    cin >> N;
    long double ans = 0;
    rep(i,(int)N){
        long double a;
        cin >> a;
        if(i == 0)ans -= a;
        if(i == N-1)ans += a;
    }
    ans /= (N - 1);
    cout << ans << endl;
}