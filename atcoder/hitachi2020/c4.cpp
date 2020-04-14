#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi G;
vi even, odd;
void dfs(int v, int pre, int d){
    if(d & 1)odd.push_back(v);
    else even.push_back(v);
    for(auto nv: G[v]){
        if(pre == nv)continue;
        dfs(nv, v, d + 1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    G.resize(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1,0);
    vi nums[3];
    rep1(i,N+1){
        nums[i % 3].push_back(i);
    }
    //色塗りをする
    vi ans(N, -1);
    //evenのほうが小さい保証
    if(even.size() > odd.size()){
        swap(even, odd);
    }
    //両方入る場合
    if(even.size() >= max(nums[1].size(),  nums[2].size())){
        rep(i,nums[1].size()){
            ans[even[i]] = nums[1][i];
        }
        rep(i, nums[2].size()){
            ans[odd[i]] = nums[2][i];
        }
        int idx = 0;
        for(int i = 0; i < N; i++){
            if(ans[i] == -1){
                ans[i] = nums[0][idx];
                idx++;
            }
        }
    }
    else{
        //このとき、even.size() <= num[0].size()
        //evenを0埋めする
        rep(i, even.size()){
            ans[even[i]] = nums[0][i];
        }
        //残りの0をoddへ
        int idx = 0;
        for(int i = even.size(); i < (int)nums[0].size();i++){
            ans[odd[idx]] = nums[0][i];
            idx++;
        }
        rep(i, nums[1].size()){
            ans[odd[idx]] = nums[1][i];
            idx++;
        }
        rep(i,nums[2].size()){
            ans[odd[idx]] = nums[2][i];
            idx++;
        }
    }
    rep(i,N){
        cout<<ans[i];
        if(i == N-1)cout<<endl;
        else cout<<" ";
    }
}