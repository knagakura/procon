#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int H, W, K, N;
int x, y;
int mpy[100050];
vector<pair<int, int>> v[100050], vv[100050];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> K;
    cin >> N;
    rep(i,N){
        cin >> x >> y;
        x--;
        y--;
        v[x].emplace_back(x,y);
        vv[y].emplace_back(x,y);
    }
    rep(j,W)mpy[vv[j].size()]++;
    long long ans = 0;
    rep(i,H){
        int r = v[i].size();
        int add = mpy[K-r];
        for(auto p: v[i]){
            int cnty = vv[p.second].size();
            if(cnty == K-r)add--;
            if(cnty == K-r+1)add++;
        }
        ans += add;
    }
    cout << ans << endl;
}
