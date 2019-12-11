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

ll x[7]={};
ll y[7]={};
ll black[3];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep1(i,7)cin>>x[i]>>y[i];
    ll white = (x[2]-x[1])*(y[2]-y[1]);
    black[1] = (x[4]-x[3])*(y[4]-y[3]);
    black[2] = (x[6]-x[5])*(y[6]-y[5]);
    //そもそも合計が覆えるか
    //そもそも白の方が大きかったら
    if(white>(black[1] + black[2])){
        cout<<"YES"<<endl;
        return 0;
    }
    //単体で覆えるか
    if(black[1] >= white){
        if(x[3]<=x[1]&&y[3]<=y[1]&&x[2]<=x[4]&&y[2]<=y[4]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    else if(black[2]>=white){
        if(x[5]<=x[1]&&y[5]<=y[1]&&x[2]<=x[6]&&y[2]<=y[6]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    //２つ合わせて覆えるか
    //xが両方外側で、yがいい感じ
    if(x[3]<=x[1]&&x[2]<=x[4]){
        if(x[5]<=x[1]&&x[2]<=x[6]){
            if(y[3]<=y[1]&&y[2]<=y[6]){
                if(y[5]<=y[4]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else if(y[5]<=y[1]&&y[2]<=y[4]){
                if(y[3]<=y[6]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    //yが両方外側で、xがいい感じ
    if(y[3]<=y[1]&&y[2]<=y[4]){
        if(y[5]<=y[1]&&y[2]<=y[6]){
            if(x[3]<=x[1]&&x[2]<=x[6]){
                if(x[5]<=x[4]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else if(x[5]<=x[1]&&x[2]<=x[4]){
                if(x[3]<=x[6]){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}