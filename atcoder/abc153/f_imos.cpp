#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
using pll = pair<long long, long long>;

int N;
long long D, A;
vector<long long> X, H;

long long solve() {
    // モンスターを X が小さい順に
    vector<int> ids(N);
    for (int i = 0; i < N; ++i) ids[i] = i;
    sort(ids.begin(), ids.end(), [&](int i, int j) {
            return X[i] < X[j]; });
    vector<long long> nX(N), nH(N);
    for (int i = 0; i < N; ++i) nX[i] = X[ids[i]], nH[i] = H[ids[i]];
    X = nX, H = nH;
    cerr<<"(N, D, A): "<<N<<" "<<D<<" "<<A<<endl;
    print(X);
    print(H);
    // imos 法で処理していく
    vector<long long> S(N+1, 0);
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] < H[i]) {
            // モンスター i を倒すのに必要な回数
            long long need = (H[i] - S[i] + A - 1) / A;
        
            // X[i] を左端とした爆発が届く範囲を求める
            long long right = X[i] + D * 2;
            int id = upper_bound(X.begin(), X.end(), right) - X.begin();
            
            // imos しながら爆発させる
            S[i] += need * A;
            S[id] -= need * A;
            res += need;
            cerr<<"id: "<<id<<endl;
        }

        // imos の累積和をとる操作
        S[i+1] += S[i];
        cerr<<"res: "<<res<<endl;
        print(S);

    }
    return res;
}

int main() {
    cin >> N >> D >> A;
    X.resize(N); H.resize(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> H[i];
    cout << solve() << endl;
}