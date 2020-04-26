#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

void solve(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int l = c - d;
    int r = c + d;
    if(n*(a+b) < l || r < n*(a-b))cout << "No" << endl;
    else cout << "Yes" << endl;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int Q;
    cin >> Q;
    while (Q--) {
        solve();
    }
}