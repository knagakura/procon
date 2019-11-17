#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    vector<double> x(N),y(N),r(N);
    rep(i,N)r[i] = i;
    rep(i,N)cin>>x[i]>>y[i];
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    double ans = 0;
    double cnt = 0;
    do{
        cnt++;
        rep(i,N-1){
            double x1 = x[r[i]];
            double y1 = y[r[i]];
            double x2 = x[r[i+1]];
            double y2 = y[r[i+1]];
            double d2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
            double d  = sqrt(d2);
            ans += d;
        }
    }while(next_permutation(all(r)));
    cout<<ans/cnt<<endl;
}