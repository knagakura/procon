#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef pair<int, int> i_i;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int N;
bool IsIn(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    vec<int> P(N * N);
    vvec<int> S(N, vec<int>(N));
    vvec<bool> isexist(N, vec<bool>(N, true));
    rep(i, N * N) {
        cin >> P[i];
        P[i]--;
    }
    rep(i, N)rep(j, N)S[i][j] = min({N - 1 - j, j, N - 1 - i, i});
    auto debug = [&]() -> void {
        rep(i, N) print(S[i]);
    };
    debug();
    auto update = [&](int si, int sj) -> void {
        queue<i_i> q;
        q.push(make_pair(si, sj));
        while (not q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop();
            rep(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not IsIn(ni, nj))continue;
                if (chmin(S[ni][nj], S[i][j] + isexist[i][j])) {
                    q.push(make_pair(ni, nj));
                }
            }
        }
    };
    int ans = 0;
    rep(k, N * N) {
        int si = P[k] / N;
        int sj = P[k] % N;
        /*update*/
        ans += S[si][sj];
        isexist[si][sj] = false;
        update(si, sj);
        /*
        dump(P[k] + 1);
        cerr << si << " " << sj << endl;
        debug();
        dump(ans);
         */
    }
    cout << ans << endl;
}