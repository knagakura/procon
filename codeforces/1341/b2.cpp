#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    a.push_back(a[N-1]);
    //初期化
    ll cnt = 0;
    //0 ~ K-1まで
    for(int i = 1; i <= K-2; i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]){
            cnt++;
        }
    }
    ll ans = cnt;
    ll l = 0;
    for(ll i = K; i < N; i++){
        //i - K が抜ける
        if(a[i-K] < a[i-K+1] && a[i-K+1] > a[i-K+2]){
            cnt--;
        }
        //iが入る
        if(a[i-2] < a[i-1] && a[i-1] > a[i]){
            cnt++;
        }
        if(ans < cnt){
            ans = cnt;
            l = i - K + 1;
        }
    }
    cout << ans + 1 <<" " <<  l + 1 << endl;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;
    while(Q--){
        solve();
    }
}