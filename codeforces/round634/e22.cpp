#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

/*
void solve(){
    int N,200;
    200 = 200;
    cin >> N;
    int a[N];
    int cum[200+1][N+1] = {};
    //vvec<int> cum(200, vec<int>(N+1,0));
    //idxの管理
    //vvec<int> idx(200);
    vec<int> idx[200];
    rep(i,N){
        cin >> a[i];
        a[i]--;
        idx[a[i]].push_back(i);
        rep(j,200){
            cum[j][i+1] = cum[j][i];
        }
        cum[a[i]][i+1]++;
    }
    //vec<int> r(200);
    int r[200];
    rep(j,200){
        r[j] = idx[j].size() - 1;
    }
    //vec<int> cnt(200,0);
    int cnt[200] = {};
    int ans = 0;
    rep(j,200)chmax(ans, cum[j][N]);
    rep(i,N){
        cnt[a[i]]++;
        if(idx[a[i]][r[a[i]]] <= i)continue;
        rep(j,200){
            if(j == a[i])continue;
            int r_idx = idx[a[i]][r[a[i]]];
            int l_idx = i;
            int tmp = cnt[a[i]]*2 + cum[j][r_idx] - cum[j][l_idx];
            chmax(ans, tmp);
        }
        r[a[i]]--;
    }
    cout << ans << endl;
}
*/
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        int N;
        cin >> N;
        int a[N];
        int cum[200][N+1];
        rep(j,200)rep(i,N+1)cum[j][i] = 0;
        int ans = 0;
        vec<int> idx[200];
        rep(i,N){
            cin >> a[i];
            a[i]--;
            idx[a[i]].push_back(i);
            rep(j,200){
                cum[j][i+1] = cum[j][i];
            }
            cum[a[i]][i+1]++;
            chmax(ans, cum[a[i]][i+1]);
        }
        int r[200];
        rep(j,200){
            r[j] = idx[j].size() - 1;
        }
        int cnt[200] = {};
        rep(i,N){
            cnt[a[i]]++;
            if(idx[a[i]][r[a[i]]] <= i)continue;
            rep(j,200){
                if(j == a[i])continue;
                int r_idx = idx[a[i]][r[a[i]]];
                int l_idx = i;
                int tmp = cnt[a[i]]*2 + cum[j][r_idx] - cum[j][l_idx];
                chmax(ans, tmp);
            }
            r[a[i]]--;
        }
        cout << ans << '\n';
    }
}