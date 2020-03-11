
# 
参加しました。
結果は散々だったので割愛します。

[:contents]

## A - Hitachi String
### 感想
- 長さの偶奇でわかるのでやるだけなんですが、焦って3WA出しました・・・
```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    
    string S;
    cin>>S;
    if(S.size()%2 == 1){
        cout<<"No"<<endl;
        return 0;
    }
    rep(i, (int)S.size()-1){
        if(S[i] == 'h' && S[i+1] == 'i'){
            i++;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
```
## B - Nice Shopping
### 解説
- クーポンを使わない最小の組み合わせが自由に決められる。
- クーポンを使った場合にそれより安くなるなら、そちらを採用する。

```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

template<class T>
bool chmin(T& a, T b){
    if (a > b) {
        a = b; 
        return true;
    } 
    return false; 
}
const long long INFLL = (long long)1e18+1;

int main() {

    int A,B,M;
    cin>>A>>B>>M;
    vector<long long> a(A);
    long long mina = INFLL;
    rep(i,A){
        cin>>a[i];
        chmin(mina, a[i]);
    }
    vector<long long> b(B);
    long long minb = INFLL;
    rep(i,B){
        cin>>b[i];
        chmin(minb, b[i]);
    }
    long long ans = mina+minb;
    rep(i,M){
        int x,y,c;
        cin>>x>>y>>c;
        x--;y--;
        chmin(ans, a[x] + b[y] - c);
    }
    cout<<ans<<endl;
}
```
## C - ThREE

### コンテスト中
- ある頂点から距離3の頂点を全て書き出すみたいなことをしたかったけど、最悪ケースでTLE。Google先生に「datastucture tree distance 3」とか聞いてたけどわからず。ネットサーフィンで椅子を温めて終了。

### 解説
- まず、問題の条件の言い換えで、
    - 「piとpjの和または積が3の倍数である」とは
    - 「pi, pj = 1, 1 or 2, 2」となることに気付けるかどうか


- 解説通りだが、二部グラフの異なる集合間の組み合わせの中のみに距離3のペアが表れる
    - 経験とかもないと見えなさそう

- 無駄に最適化してしまうが、組み合わせが大量にあるため雑にやっても構築できてしまう
- 二つの集合をeven, oddとし、evenのほうが要素数が少ないとする
- このとき、1 (mod 3)と2(mod 3)が完全に別々に分けられれば、埋められなかった部分を0 (mod 3)で埋めて構築完了である

- 別々に分けられないのはどのような時かと言えば、1 (mod 3) or 2 (mod 3)がevenの要素数を超える場合である。
    - このとき、evenの要素数以上の0 (mod 3)があることがわかる（0は1,2より一個少ないか同じ数なので）ので、evenを0で埋めて、oddにその他を埋め込むと題意を満たす構築が完了する

### 実装
- やや方針に迷うが、evenとoddの大小を固定すると実装量が減ったり、ifとelseのみで条件を言い換えられたりする

```cpp
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
    //input
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

    //二部グラフの構築
    dfs(0,-1,0);

    //数字の分類
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
```