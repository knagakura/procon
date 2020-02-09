#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

/*------------------------------------/
for library*/
template<typename T>
class TwoDimCumsum {
public:
    int H,W;
    vector<vector<T>> d;
    TwoDimCumsum(T _H, T _W):H(_H),W(_W),d(_H+1,vector<T>(_W+1,0)){}

    void add(int x, int y, int a){
        d[x][y]+= a;
    }
    void build(){
        for(int i = 1; i <= H; ++i){
            for(int j = 1; j <= W; ++j){
                d[i][j] += d[i-1][j];
                d[i][j] += d[i][j-1];
                d[i][j] -= d[i-1][j-1];
            }
        }
    }
    //[sx, gx] & [sy, gy]
    T query(int sx, int sy, int gx, int gy){
        return d[gx][gy] - d[sx-1][gy] - d[gx][sy-1] + d[sx-1][sy-1];
    }
    //confirm the 2d vector
    void debug(){
        for(int i = 0;i <= H;++i){
            for(int j = 0; j <= W; ++j){
                cerr<<d[i][j]<<((j == W) ? "\n":" ");
            }
        }
    }
};
/*
使い方
https://atcoder.jp/contests/abc106/submissions/9873594
1. インスタンス生成 縦横決める
TwoDimCumsum<int> Cumsum(H,W);
2. 座標に埋める
Cumsum.add(x, y, 1)
3. 二次元累積和計算
Cumsum.build()
4. 区間のクエリを受ける
Cumsumq.uery(p, q)
*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,M,Q;
    cin>>N>>M>>Q;
    TwoDimCumsum<int> d(N,N);
    rep(i,M){
        int l,r;
        cin>>l>>r;
        d.add(l,r,1);
    }
    d.build();
    while(Q--){
        int p,q;
        cin>>p>>q;
        cout<<d.query(p,p,q,q)<<endl;
    }
}