#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int H,W;
int A,B;
int cnt[1005][1005] = {};
int field[1005][1005] = {};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>H>>W>>A>>B;
    int X,Y;
    X = Y = -1;
    rep(x,H+1)rep(y,W+1){
        ll a = (W-2*A)*x + A*H;
        ll b = (H-2*B)*y + B*W;
        if(a == b){
            X = x;
            Y = y;
            break;
        }
    }
    //A個を1にするのがX行
    //B個を1にするのがY列
    //cerr<<X<<" "<<Y<<endl;
    if(X==-1&&Y==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    //最初のX行をA個にする
    //A個にするのは、スタート位置はずらす
    for(int i = 0; i < X; ++i){
        for (int j = i; j < i+A; j++){
            field[i][j%W] = 1;
        }



        
    }
    //次のH-X行は、H-A個にするが、
    //どこにおくかは縦が関わるので、累積和を定義して確認する
    rep(j,W){
        cnt[0][j] = field[0][j];
    }
    rep(j,W)rep1(i,X){
        cnt[i][j] = field[i][j] + cnt[i-1][j];
    }
    for(int i = X; i < H; ++i){
        int cnt1 = 0;
        for (int j = X; j < X+W; j++){
            int maxcol= B;
            if(j%W>=Y){
                maxcol = W-B;
            }
            if(cnt[i-1][j%W]<maxcol&&cnt1<H-A){
                field[i][j%W] = 1;
                cnt1++;
                cnt[i][j%W] = cnt[i-1][j%W]+1;
            }
            else{
                cnt[i][j%W] = cnt[i-1][j%W];
            }
        }
    }
    /*
    rep(i,H)rep(j,W){
        cerr<<field[i][j];
        if(j == W-1)cerr<<endl;
        else cerr<<" ";
    }
    cerr<<endl;
    rep(i,H)rep(j,W){
        cerr<<cnt[i][j];
        if(j == W-1)cerr<<endl;
        else cerr<<" ";
    }
    */
    rep(i,H)rep(j,W){
        cout<<field[i][j];
        if(j == W-1)cout<<endl;
        else cout<<" ";
    }
}