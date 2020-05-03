#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
int N, K;
string S;

void solve() {
    cin >> N >> K >> S;
    sort(all(S));
    //最初のK個のみを見る
    map<char, int> m;
    rep(i, K)m[S[i]]++;
    if (m.size() >= 2) {
        cout << S[K - 1] << endl;
        return;
    } else {
        map<char, int> m2;
        for (int i = K; i < N; i++) {
            m2[S[i]]++;
        }
        bool only_one = (m2.size() == 1);
        cout << S[0];
        for (int i = K; i < N; i++) {
            if (only_one) {
                if (i % K == 0)cout << S[i];
            } else cout << S[i];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) solve();
}