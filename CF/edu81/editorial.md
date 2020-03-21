 
[Educational Codeforces Round 81 (Rated for Div. 2)](https://codeforces.com/contest/1295)にVirtual参加しました。



### [A - Display The Number](https://codeforces.com/contest/1295/problem/A)

#### 問題概要
N個点灯させていいので、点灯した結果の数字を最大化する問題。
#### 解説
桁数を最大化すればよく、1を作るのがコストが最小。偶数だったら全部1にすればよいが、奇数だと余ってしまうので、3本使ってできる7を先頭に置けばよい。

#### [提出](https://codeforces.com/contest/1295/submission/72939961)

### [B - Infinite Prefixes](https://codeforces.com/contest/1295/problem/B)

#### 問題概要
01文字列が与えられ、それを無限につなげた文字列において、前から見ていて0と1の数の差がXになるのが何回かを数える問題。
#### 解説
周期的になるので、1周期終わったときの状態を繰り返す。
Xの正負があったりするので、気をつけましょう。
#### [提出](https://codeforces.com/contest/1295/submission/72941888)

### [C - Obtain The String](https://codeforces.com/contest/1295/problem/C)
#### 問題概要
目標文字列を構成するために、ある文字列から部分列（連続でなくてもよい）を取り出してつなげる。最低何回部分列を使えばできるか答える。

#### 解説
無限回見たことあるけどアルファベットごとにindexを管理して二部探索して次にほしい文字がどこにあるかを高速に探す。

#### [提出](https://codeforces.com/contest/1295/submission/72942938)


### [D - Same GCDs](https://codeforces.com/contest/1295/problem/D)
#### 問題概要
`gcd(a, m) == gcd(a + x, m)`となるxの個数を答える問題。
#### 解説
```
g = gcd(a, m)とすると
a = a' * g
m = m' * g
と表せる（ただしa'とm'は互いに素）

gcd(a + x, m) = gと仮定すると
a + x = k * g
と表される（ただし、kとm'は互いに素）
このとき、
a' * g + x = k * g　より
x = (k - a') * g
である。
つまり、k-a'の個数を求めればよい。
ここで、
0 <= x < m より
0 <= k-a' < m
kとa'はともにm'と互いに素なので、
k - a'もm'と互いに素。
よって、k-a'の個数は、m'以下でm'と互いに素な数の個数に等しい。
k - a'の個数がkの個数になり、xの個数になるので、これが答え。

```
n以下のnと互いに素な数の個数は、オイラーのファイ関数を用いればよい。
#### [提出](https://codeforces.com/contest/1295/submission/72956998)

### 参考

- [公式editorial](https://codeforces.com/blog/entry/73467)