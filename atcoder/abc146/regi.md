# ABC146に参加しました

## A - Can't Wait for Holiday
mapで管理すると楽そうです。

[提出](https://atcoder.jp/contests/abc146/submissions/8606216)

## B - ROT N
アルファベットをN個スライドする問題。
```cpp
('S[i] - 'A' + N) % 26 + 'A'
```
をすると通ります。

[提出](https://atcoder.jp/contests/abc146/submissions/8608589)
## C - Buy an Integer
X円で買える数字の最大値を求める問題。

- ある数字が買える場合、それ以下の数字は全部買える
- ある数字が買えない場合、それ以上の数字は全部買えない

この境界を求めれば、最大値が求まる
解決めうち二分探索という問題になるけど、ABC-Cにしては難しいなあと思った。
ABCは教育だし、こういうのが出てもいいのかも

実装はめぐる式が楽。
okとngどっちが大きいのかは注意しようね・・・（abs使えばいい説はある）

```cpp

int main() {
    ll A,B,X;
    cin>>A>>B>>X;

    auto check = [&](ll N){
        int dN = to_string(N).size();
        ll okane = A * N + B * dN;
        return (okane<= X);
    };

    ll ok = 0;
    ll ng = INF+1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }

    cout<<ok<<endl;
}
```
[提出](https://atcoder.jp/contests/abc146/submissions/8611926)

## D - Coloring Edges on Tree
頂点を塗る問題はよく見ていたけど、辺を塗るのは初見だった。
とりあえず一番色が必要なのは、辺が最も貼られているところなので、
そこからDFSしていく。

親が降りてくる前に使った色と、兄弟の色以外で使えばいいので、それらをいい感じに塗る

辺に色の情報を持たせるのどうやってやんねん！と思ったけど、
重み付きみたいな感じでEdgeを

```cpp 
pair<int,int>
```

で管理するといい感じに実装できます。

思いついた時は感動したけど、よくある話っぽい？

ちょっとしたミスで失点した。2WA。

```cpp
int N;
vector<vector<pair<int,int>>> G;
vector<int> color;

void dfs(int i, int pre, int pre_c){
    int cnt = 1;
    for(auto ni: G[i]){
        if(ni.first == pre)continue;
        if(cnt == pre_c){
            cnt++;
        }
        color[ni.second] = cnt;
        dfs(ni.first, i, color[ni.second]);
        cnt++;
    }
}

int main() {
    cin>>N;
    G.resize(N);
    color.resize(N-1);
    rep(i,N-1){
        int a,b; cin>>a>>b;
        a--;b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    int maxc = 0;
    int start = 0;
    rep(i,N){
        if(maxc < (ll)G[i].size()){
            chmax(maxc, (ll)G[i].size());
            start = i;
        }
    }
    cout<<maxc<<endl;

    dfs(start, -1, -1);
    rep(i,N-1){
        cout<<color[i]<<endl;
    }
}

```
[提出](https://atcoder.jp/contests/abc146/submissions/8621890)

## E - Rem of Sum is Num
Fが解かれているなあと思いながら問題を見る。
親の顔より見た区間の特徴を考える問題だなあと思った。
とりあえずmod Kの世界で考えているので、A_iをmod Kする

尺取りかなあと思い、一個ずらしたときにどうなるかなどを実験していた。

Fが解かれているので、そっちもチラ見していた。

わからん〜をして終わり。

実際は、この性質を満たす区間は、次の数式を満たす
区間の和をsumとして、長さをlとすると
sum % K = l

つまりあるaが存在して
sum = a * K + l
となる
これを変形すると（aが定数でないので）
sum - l = a * K

つまり、sum - l　がaの倍数なら良い
sumはl個の要素の和なので、-lを一つ一つの要素に押し付け、新しい配列を定義して、
そのsumがKの倍数になれば良いということがわかる

これは実質 [Zero Sum Ranges](https://atcoder.jp/contests/agc023/tasks/agc023_a)なので、解けます。


## F - Sugoroku

無限人に解かれていたらしい。
まだわかっていない。



## まとめ
ABCD4完50分2WA パフォ1313
もっと早く解けたはずで、精進が足りないです。
Eは過去に類題があるが、式変形パートがあまり慣れてない。同様のことをしようとしていたので、ひとまず成長していると思ってもいいのかもしれないと思いました。

精進してください（はい）。

