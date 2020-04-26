#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

//dp[i][j] := i個目までみて、K個使って作れるか
bool dp[2020][2020];
bool back[2020][2020];

int diff(string &x, string &y) {
    int res = 0;
    rep(i, x.size()) {
        if (x[i] == '1' && y[i] == '0')return -1;
        if (x[i] == '0' && y[i] == '1')res++;
    }
    return res;
}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<string> a(N);
    rep(i, N)cin >> a[i];
    string v[] = {
            "1110111", "0010010", "1011101",
            "1011011", "0111010", "1101011",
            "1101111", "1010010", "1111111",
            "1111011"
    };
    rep(i,N+1)rep(j,N+1){
        dp[i][j] = false;
        back[i][j] = false;
    }
    dp[0][0] = true;
    rep(i, N) {
        rep(j, K + 1) {
            if (!dp[i][j])continue;
            for (auto & k : v) {
                int cnt = diff(a[i], k);
                if (cnt == -1)continue;
                if (j + cnt > K)continue;
                dp[i + 1][j + cnt] = true;
            }
        }
    }
    if (!dp[N][K]) {
        cout << -1 << endl;
        return;
    }
    // 逆伝播
    back[N][K] = true;
    for (int i = N; i >= 1; i--) {
        // (i-1, j-cnt) <- (i, j)
        for (int j = 0; j <= K; ++j) {
            if (!back[i][j])continue;
            for (auto &k : v) {
                int cnt = diff(a[i - 1], k);
                if (cnt == -1)continue;
                if (j - cnt < 0)continue;
                if (!dp[i - 1][j - cnt])continue;
                back[i - 1][j - cnt] = true;
            }
        }
    }
    string ans;
    int pre = 0;
    for (int i = 0; i < N; i++) {
        for (int k = 9; k >= 0; k--) {
            int cnt = diff(a[i], v[k]);
            if (cnt == -1)continue;
            if (pre + cnt > K)continue;
            if (back[i + 1][pre + cnt]) {
                ans.push_back(char(k + '0'));
                pre = pre + cnt;
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    solve();
}