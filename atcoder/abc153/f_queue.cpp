#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
using pll = pair<long long, long long>;
int N;
long long D, A;
vector<long long> X, H;

long long solve() {
    vector<int> ids(N);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
            return X[i] < X[j];});

    long long res = 0;
    queue<pll> que;
    long long num = 0;
    for (auto i : ids) {
        while (!que.empty() && que.front().first < X[i]) {
            num -= que.front().second;
            que.pop();
        }
        H[i] -= num;
        if (H[i] <= 0) continue;
        res += H[i];
        que.push({X[i] + D*2, H[i]});
        num += H[i];
    }
    return res;
}

int main() {
    while (cin >> N >> D >> A) {
        X.resize(N); H.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> X[i] >> H[i];
            H[i] = (H[i] + A - 1) / A;
        }
        cout << solve() << endl;
    }
}