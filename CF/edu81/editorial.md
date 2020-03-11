 
[Educational Codeforces Round 1 (Rated for Div. 2)](https://codeforces.com/contest/1295)にVirtual参加しました。


[:contents]

### [A - Display The Number](https://codeforces.com/contest/1295/problem/A)

#### 問題概要
N個点灯させていいので、点灯した結果の数字を最大化する問題。
#### 解説
桁数を最大化するのが大事で、1を作るのが大事。偶数だったら全部1にすればいいけど、奇数だと余ってしまうので、3本使ってできる7を先頭に置くといいです。

#### [提出](https://codeforces.com/contest/1295/submission/72939961)

### [B - Infinite Prefixes](https://codeforces.com/contest/1295/problem/B)

#### 問題概要
01文字列が与えられ、それを無限につなげた文字列において、前から見ていて0と1の数の差がXになるのが何回かを数える問題。
#### 解説
周期的になるので、1周期終わったときの状態を繰り返す。
Xの正負があったりするので、気をつけると通ります。
#### [提出](https://codeforces.com/contest/1295/submission/72941888)

### [C - Obtain The String](https://codeforces.com/contest/1295/problem/C)
#### 問題概要
目標文字列を構成するためにある文字列から部分列（連続でなくてもよい）を取り出してつなげて最低何回でできるか数える問題。

#### 解説
無限回見たことあるけどアルファベットごとにindexを管理して二部探索して次にほしい文字がどこにあるかを高速に探す。

#### [提出](https://codeforces.com/contest/1295/submission/72942938)


### [D - Same GCDs](https://codeforces.com/contest/1295/problem/D)
#### 問題概要

#### 解説

#### [提出]()

### 参考

- [公式editorial](https://codeforces.com/blog/entry/73467)