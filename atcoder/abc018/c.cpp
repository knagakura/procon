#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int H, W, K;
int cnt[555][555];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> H >> W >> K;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    // rep(i,H)rep(j,W)cnt[i][j] = 0;

    // (K-1,K-1)について計算
    int c = 0;
    rep(i,H)rep(j,W){
        if(abs(K-1-i) + abs(K-1-j) > K-1)continue;
        c++;
        cnt[K-1][K-1] += S[i][j] == 'o';
    }

    // 一番上の行を計算 (左から遷移)
    for(int j = K; j+K-1 < W; j++){
        cnt[K-1][j] = cnt[K-1][j-1];
        for(int dx = -(K-1); dx <= K-1; dx++){
            int dy = K-1-abs(dx);
            cnt[K-1][j] -= S[K-1+dx][j-1-dy] == 'o';
            cnt[K-1][j] += S[K-1+dx][j+dy] == 'o';
        }
    }

    // 二番目の行以降を計算 (上から遷移)
    for(int i = K; i+K-1 < H; i++){
        for(int j = K-1; j+K-1 < W; j++){
            cnt[i][j] = cnt[i-1][j];
            for(int dy = -(K-1); dy <= K-1; dy++){
                int dx = K-1-abs(dy);
                cnt[i][j] -= S[i-1-dx][j+dy] == 'o';
                cnt[i][j] += S[i+dx][j+dy] == 'o';
            }
        }
    }

    int ans = 0;
    rep(i,H)rep(j,W)ans += cnt[i][j] == c;
    cout << ans << endl;
}
