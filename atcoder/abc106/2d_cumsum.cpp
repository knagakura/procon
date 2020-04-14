#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<typename T>
class TwoDimCumsum {
public:
    int H,W;
    vector<vector<T>> d;
    TwoDimCumsum(T inH, T inW):H(inH),W(inW),d(H+1,vector<T>(W+1,0)){}

    void set_xy(int x, int y){
        d[x][y]++;
    }
    void init(){
        for(int i = 1; i <= H; ++i){
            for(int j = 1; j <= W; ++j){
                d[i][j] += d[i-1][j];
                d[i][j] += d[i][j-1];
                d[i][j] -= d[i-1][j-1];
            }
        }
    }
    T Query(int p, int q){
        return d[q][q] - d[p-1][q] - d[q][p-1] + d[p-1][p-1];
    }
    void display(){
        for(int i = 0;i <= H;++i){
            for(int j = 0; j <= W; ++j){
                cerr<<d[i][j]<<((j == W) ? "\n":" ");
            }
        }
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M,Q;
    cin>>N>>M>>Q;
    TwoDimCumsum<int> Cumsum(N,N);
    rep(i,M){
        int l,r;
        cin>>l>>r;
        Cumsum.set_xy(l,r);
    }
    Cumsum.init();
    //Cumsum.display();
    for(int i = 0; i < Q; ++i){
        int p,q;
        cin>>p>>q;
        cout<<Cumsum.Query(p, q)<<endl;
    }
}