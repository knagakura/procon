#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int A[111][111];
void solve(int t){
    int N;
    cin >> N;
    int trace = 0, r = 0, l = 0;
    rep(i,N)rep(j,N){
        cin >> A[i][j];
    }
    rep(i,N)trace+=A[i][i];
    rep(i,N){
        bool ok = false;
        rep(j,N)rep(k,N)if(j != k){
            if(A[i][j] == A[i][k])
                ok = true;
        }
        if(ok)r++;
    }
    rep(j,N){
        bool ok = false;
        rep(i,N)rep(k,N)if(i != k){
            if(A[i][j] == A[k][j])
                ok = true;
        }
        if(ok)l++;
    }
    cout  << "Case #" << t << ": ";
    cout << trace << " " << r << " " << l << endl;

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    rep(i,t){
        solve(i+1);
    }
}