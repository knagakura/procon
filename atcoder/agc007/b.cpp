#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<int> p(N);
    rep(i,N){
        cin >> p[i];
        p[i]--;
    }
    ll d = N;
    vector<ll> a(N),b(N);
    a[0] = 1;
    rep(i,N-1)a[i+1] = a[i] + d;
    b.back() = 1;
    int start = 0;
    rep(i,N)if(p[i] == N - 1)start = i;
    for(int i = start; i+1 < N; i++){
        ll y = p[i];
        ll x = p[i+1];
        ll delta_a = abs(a[y] - a[x]);
        if(x < y) b[x] = b[y] + delta_a + 1;
        else b[x] = b[y] - delta_a + 1;
    }
    for(int i = start; i - 1 >= 0; i--){
        ll y = p[i-1];
        ll x = p[i];
        ll delta_a = abs(a[x] - a[y]);
        if(x < y)b[y] = b[x] - delta_a - 1;
        else b[y] = b[x] + delta_a - 1;
    }
    rep(i,N)cout << a[i] << " ";
    cout << endl;
    rep(i,N)cout << b[i] << " ";
    cout << endl;
}
