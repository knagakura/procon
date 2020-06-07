#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);
const int dx[] = {1,0,-1,1,-1,0};
const int dy[] = {1,1,1,0,0,-1};
const int H = 410;
const int W = 410;

bool IsIn(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    char S[H][W];
    rep(i, H)rep(j, W)S[i][j] = '.';
    int N, X, Y;
    cin >> N >> X >> Y;
    X += 200;
    Y += 200;
    S[X][Y] = 'G';
    S[200][200] = 'S';
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        x += 200;
        y += 200;
        S[x][y] = '#';
    }
    ll dist[H][W];
    rep(i, H)rep(j, W)dist[i][j] = INF;
    queue<i_i> Q;
    Q.push({200, 200});
    dist[200][200] = 0;
    while (not Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        rep(k, 6) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(not IsIn(ni,nj))continue;
            if(S[ni][nj] == '#')continue;
            //if(dist[ni][nj] != -1)continue;
            if(dist[ni][nj] > dist[i][j] + 1){
                dist[ni][nj] = dist[i][j] + 1;
                Q.push({ni,nj});
            }
        }
    }
    /*
    for(int i = -4; i <= 4; i++){
        for(int j = -4; j <= 4; j++){
            cerr << S[200+i][200+j] << " ";
        }
        cerr << endl;
    }
    for(int i = -4; i <= 4; i++){
        for(int j = -4; j <= 4; j++){
            if(dist[200+i][200+j] == INF){
                cerr << "." << " ";
            }
            else cerr << dist[200+i][200+j] << " ";
        }
        cerr << endl;
    }*/
    
    if(dist[X][Y] == INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dist[X][Y] << endl;
}
