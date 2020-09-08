#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> cnt(M);
    rep(i,M)cnt[i].second = -i-1;
    rep(i,N){
        rep(j,M){
            int a;
            cin >> a;
            cnt[j].first += a;
        }
    }
    sort(all(cnt), greater<pair<int, int>>());
    rep(i,M){
        cout << cnt[i].second * (-1);
        if(i == M - 1)cout << endl;
        else cout << ' ';
    }
}
