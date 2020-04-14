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
const string dir = "DRUL";


int H,W,K;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W >> K;
    vector<int> sx(K), sy(K),fx(K), fy(K);
    rep(i,K){
        cin >> sx[i] >> sy[i];
        sx[i]--;sy[i]--;
    }
    rep(i,K){
        cin >> fx[i] >> fy[i];
        fx[i]--;fy[i]--;
    }
    //print(sx);print(sy);print(fx);print(fy);
    /*
    vec<bool> ok(K,false);
    rep(i,K){
        if(sx[i] == fx[i] && sy[i] == fy[i])ok[i] = true;
    }
    map<char, int> map;
    rep(k, 4)map[dir[k]] = k;
    */
    string ans = "";
    auto step = [&](char d){
        ans.push_back(d);/*
        int dir_idx = map[d];
        rep(i,K){
            int nx = sx[i] + dx[dir_idx];
            int ny = sy[i] + dy[dir_idx];
            if(!IsIn(nx, ny))continue;
            sx[i] = nx;
            sy[i] = ny;
            if(sx[i] == fx[i] && sy[i] == fy[i])ok[i] = true;
        }
        */
        return 0;
    };
    /*
    auto move = [&](int x, int y, int gx, int gy){
        rep(_, abs(gx - x)){
            if(gx - x > 0){
                step('D');
            }
            else{
                step('U');
            }
        }
        rep(_, abs(gy - y)){
            if(gy - y > 0){
                step('R');
            }
            else{
                step('L');
            }
        }
    };*/
    rep(i,H-1){
        step('D');
    }
    rep(j,W-1){
        step('R');
    }
    //H行
    rep(i,H){
        rep(j,W-1){
            if(i%2 == 0){
                step('L');
            }
            else{
                step('R');
            }
        }
        step('U');
    }
    /*
    if((int)ans.size() > 2 * H * W){
        cout << -1 << endl;
        return 0;
    }*/
    cout << ans.size() << endl;
    cout << ans << endl;
}