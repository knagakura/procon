#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
int N;
vector<long long> A;
vector<int> ans;
vvec<int> G;
vec<bool> visited;
bool dfs(int cur){
    visited[cur] = true;
    ans.push_back(cur);
    if((int)ans.size() == N){
        rep(i,N){
            cout << A[ans[i]] << " ";
        }
        cout <<endl;
        return true;
    }
    bool res = false;
    for(auto nxt: G[cur]){
        if(visited[nxt])continue;
        res |= dfs(nxt);
        ans.pop_back();
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    G.resize(N);
    rep(i,N)cin>>A[i];
    rep(i,N)rep(j,N){
        if(A[i] % 3 == 0 &&  A[i] / 3 == A[j]){
            G[i].push_back(j);
        }
        if(A[i] * 2 == A[j]){
            G[i].push_back(j);
        }
    }
    rep(i,N){
        visited.assign(N, false);
        if(dfs(i)){
            return 0;
        }
        ans.clear();
    }
}