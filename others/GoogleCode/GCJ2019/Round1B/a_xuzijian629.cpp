#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p, q;
    cin >> p >> q;
    vector<int> up(q + 1), down(q + 1), left(q + 1), right(q + 1);
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        char c;
        cin >> c;
        if (c == 'N') {
            up[b]++;
        } else if (c == 'S') {
            down[b]++;
        } else if (c == 'W') {
            left[a]++;
        } else if (c == 'E') {
            right[a]++;
        }
    }
    for (int i = 1; i < q + 1; i++) {
        up[i] += up[i - 1];
        down[i] += down[i - 1];
        left[i] += left[i - 1];
        right[i] += right[i - 1];
    }
    vector<int> cnth(q + 1), cntv(q + 1);
    for (int i = 0; i < q + 1; i++) {
        cnth[i] = (i == 0 ? 0 : right[i - 1]) + left[q] - left[i];
        cntv[i] = (i == 0 ? 0 : up[i - 1]) + down[q] - down[i];
    }
    int maxh = *max_element(cnth.begin(), cnth.end()), maxv = *max_element(cntv.begin(), cntv.end());
    for (int i = 0; i < q + 1; i++) {
        if (cnth[i] == maxh) {
            cout << i << ' ';
            break;
        }
    }
    for (int i = 0; i < q + 1; i++) {
        if (cntv[i] == maxv) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}