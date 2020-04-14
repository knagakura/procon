#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

//DefaultInput
int N,S,K;
int x[1005],y[1005],c[1005];
int p[1005][22] = {};

//貼れない:0
//貼れる:1
//貼った:1
int can_edge[1005][1005];

//ユークリッド距離
double Udist(int a,int b,int c,int d){
    double res = sqrt((a-c)*(a-c) + (b-d)*(b-d));
    return res;
}
/*------------------------------------
for library
------------------------------------*/

//入力と初期化
void InputInit(){
    //Input
    cin >> N >> S >> K;
    rep(i,N){
        cin>>x[i]>>y[i]>>c[i];
    }


    rep(i,S)rep1(j,K){
        cin>>p[i][j];
        p[i][j]--;
    }

    //辺が貼れるかどうか
    //Init
    rep(i,N)rep(j,N)can_edge[i][j] = -1;
    auto check  = [&](int i,int j){
        if(i == j)return false;
        double d = Udist(x[i],y[i],x[j],y[j]);
        return d <= double(c[i] + c[j]);
    };
    rep(i,N)rep(j,N){
        if(check(i,j)){
            can_edge[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    InputInit();
    
}