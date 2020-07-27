#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

void Case(int t){
    cout << "Case #" << t << ":" << endl;
}
vvec<int> G;
void dfs(int cur, int pre, vector<int> &v){
    v.push_back(cur);
    for(auto nxt: G[cur]){
        //if(nxt == pre)continue;
        dfs(nxt, cur, v);
    }
}
void solve(int t){
    int N;
    cin >> N;
    string I,O;
    cin >> I >> O;
    Case(t);
    G.clear();
    G.resize(N);
    rep(i,N){
        rep(j,N){
            if(i == j)continue;
            if(abs(i - j) != 1)continue;
            if(I[j] == 'N' || O[i] == 'N')continue;
            G[i].push_back(j);
        }
    }
    vvec<bool> ans(N,vec<bool>(N,false));
    rep(i,N){
        vector<int> v;
        dfs(i,-1,v);
        for(auto j:v)ans[i][j] = true;
    }
    rep(i,N){
        rep(j,N){
            cout << ((ans[i][j]) ? 'Y' : 'N');
        }
        cout << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    rep1(i,t+1)solve(i);
}
