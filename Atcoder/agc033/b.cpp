#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir  = "DRUL";
const string dir2 = "ULDR";
int H,W,N;
int sx, sy;
string S,T;
int dp[200100][4];
int dp2[200100][4];

bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
void debug(){
    cerr<< "D R U L" << endl;
    rep(i,N+1){
        rep(j,4){
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    cerr<<endl;
    cerr<< "U L D R" << endl;;
    rep(i,N+1){
        rep(j,4){
            cerr << dp2[i][j] << " ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> H >> W >> N;
    cin >> sx >> sy;
    cin >> S >> T;
    rep(i,N)rep(j,4){
        dp[i][j] = 0;
    }
    rep(j,4){
        rep(i,N){
            if(dir[j] == S[i]){
                dp[i+1][j] = dp[i][j] + 1;
            }
            else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    rep(j,4){
        rep(i,N){
            if(dir2[j] == T[i]){
                dp2[i+1][j] = dp2[i][j] + 1;
            }
            else{
                dp2[i+1][j] = dp2[i][j];
            }
        }
    }
    debug();
    bool ok = true;
    //cerr<<"U L D R"<<endl;
    cerr<<H<<" "<<W<<endl;
    rep(i,N+1){
        rep(j,4){
            //青木くんの方が影響が大きいなら、問題なし
            int d = dp2[i][j] - dp[i][j];
            if(d >= 0)continue;
            d = -d;
            //"D R U L"を正とする
            int nx = sx + dx[j] * d;
            int ny = sy + dy[j] * d;
            cerr<<dir[j]<<"("<<dx[j]<<", "<<dy[j]<<")"<<": "<<d<<endl;
            cerr<<"("<<sx<<", "<<sy<<")"<<" -> ";
            cerr<<"("<<nx<<", "<<ny<<")"<<endl;
            if(nx<1||H<nx||ny<1||W<ny){
                cerr<<"dame!"<<endl;
                ok = false;
            }
        }
    }
    cout << (ok ? YES: NO) <<endl;
}

/*
多分上下と左右は独立に考えてよさそう
i回目までの部分問題が解ければその後も解けそう
dp[i][j]: i回目でj方向の移動の最大値
dp2[i][j]: i回目でj方向の移動と逆方向の最大値

dp[N][j] - dp[N][j]で移動の最大値が求まるので、
それと始点との関係を考えればよさそう。
*/