#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";

const int cardN = 100;
const int H = 20, W = 20;
int xin[cardN+5], yin[cardN+5];
struct Stage{
    int stage[H][W];
    vvec<int> stage_vec;
    pair<int,int> revCard[cardN];
    int num[H][W];
    pair<int, int> revNum[H*W];
    Stage(){
        rep(i,H)rep(j,W)stage[i][j] = -1;
        rep(i,cardN)revCard[i] = {-1, -1};
        stage_vec.resize(H);
        setNum();
    }
    void setNum(){
        int cnt = 0;
        rep(i,H/2){
            if(i&1){
                for(int j = W/2-1; j >= 0; j--){
                    num[i][j] = cnt;
                    revNum[cnt] = {i,j};
                    cnt++;
                }
            }
            else{
                rep(j,W/2){
                    num[i][j] = cnt;
                    revNum[cnt] = {i,j};
                    cnt++;
                }
            }
        }
    }
    void setCard(int x, int y, int Num){
        stage[x][y] = Num;
        stage_vec[x].push_back(y);
        revCard[Num] = {x, y};
    }
    void sortvec(){
        rep(i,H)sort(all(stage_vec[i]));
    }
    bool isExist(int x, int y){
        return stage[x][y] != -1;
    }
    void dumpCard(){
        rep(i,H){
            rep(j,W){
                DUMPOUT << stage[i][j] << " ";
            }
            DUMPOUT << endl;
        }
    }
    void dumpnum(){
        DUMPOUT << "num" << endl;
        rep(i,H){
            rep(j,W){
                DUMPOUT << num[i][j] << " ";
            }
            DUMPOUT << endl;
        }
        DUMPOUT << "revNum" << endl;
        rep(i,H*W){
            DUMPOUT << revNum[i] << " ";
        }
        DUMPOUT << endl;
    }
};
Stage aStage;
struct Player{
    int nowx, nowy;
    vector<int> tehuda;
    string ansStr;
    int cost = 4000;
    Player(){
        nowx = 0, nowy = 0;
        cost = 4000;
    }
    void nameru(){
        rep(i,H){
            if(i&1){
                for(int j = W-1; j >= 0; j--){
                    goIn(i, j);
                }
            }
            else{
                rep(j,W){
                    goIn(i, j);
                }
            }
        }
    }
    void nameru_short(){
        rep(i,H){
            int w_sz = aStage.stage_vec[i].size();
            if(i&1){
                for(int j = w_sz-1; j >= 0; j--){
                    int nxt_j = aStage.stage_vec[i][j];
                    if(aStage.isExist(i,nxt_j))goIn(i, nxt_j, true);
                }
            }
            else{
                rep(j,w_sz){
                    int nxt_j = aStage.stage_vec[i][j];
                    if(aStage.isExist(i,nxt_j))goIn(i, nxt_j, true);
                }
            }
        }
    }
    void goIn(int i, int j, bool existIn = false){
        goPos(i, j, existIn);
        cardIn();
    }
    void goOut(int i, int j){
        goPos(i, j);
        cardOut();
    }
    void cardIn(){
        if(not aStage.isExist(nowx, nowy))return;
        addCommand('I');
        tehuda.push_back(aStage.stage[nowx][nowy]);
        aStage.stage[nowx][nowy] = -1;
    }
    void cardOut(){
        if(aStage.isExist(nowx, nowy))return;
        if(tehuda.empty())return;
        addCommand('O');
        aStage.stage[nowx][nowy] = tehuda.back();
        tehuda.pop_back();
    }
    void goPos(int nxtx, int nxty, bool existIn = false){
        int nowdist = dist(nowx, nowy, nxtx, nxty);
        while(nowdist > 0){
            rep(i,4){
                int nxtdist = dist(nowx + dx[i], nowy + dy[i], nxtx, nxty);
                if(chmin(nowdist, nxtdist)){
                    nowx += dx[i];
                    nowy += dy[i];
                    addCommand(dir[i]);
                    if(existIn)cardIn();
                }
            }
        }
    }
    void addCommand(char c){
        ansStr.push_back(c);
        if(c != 'I' && c != 'O')cost--;
    }
    int dist(int ax, int ay, int bx, int by){
        return abs(ax - bx) + abs(ay - by);
    }
    
    void hidariuekaraOku(){
        // return;
        while(not tehuda.empty()){
            int cardNum = tehuda.back();
            auto [targetX, targetY] = aStage.revNum[cardNum];
            dump(cardNum, targetX, targetY);
            goOut(targetX, targetY);
        }
    }
    void hidariuekaraToru(){
        rep(i,H/2){
            if(i&1){
                for(int j = W/2-1; j >= 0; j--){
                    goIn(i,j);
                }
            }
            else{
                rep(j,W/2){
                    goIn(i, j);
                }
            }
        }
    }
    void Guchoku(){
        rep(i,cardN){
            auto [x, y] = aStage.revCard[i];
            goIn(x, y);
        }
    }
};
Player aPlayer;
void input(){
    rep(i,cardN){
        cin >> xin[i] >> yin[i];
        aStage.setCard(xin[i], yin[i], i);
    }
    aStage.sortvec();
}
void solve_NameteOku(){
    aStage.dumpnum();
    aPlayer.nameru();
    aPlayer.hidariuekaraOku();
    aPlayer.hidariuekaraToru();
    cout << aPlayer.ansStr << endl;
    dump(aPlayer.ansStr);
    dump(aPlayer.tehuda);
    aStage.dumpCard();
}
void solve_NameteOku_short(){
    aStage.dumpnum();
    aPlayer.nameru_short();
    aPlayer.hidariuekaraOku();
    aPlayer.hidariuekaraToru();
    cout << aPlayer.ansStr << endl;
    dump(aPlayer.ansStr);
    dump(aPlayer.tehuda);
    aStage.dumpCard();
}

void solve_Guchoku(){
    aPlayer.Guchoku();
    dump(aPlayer.tehuda);
}
int main() {
    input();
    // solve_Guchoku();
    solve_NameteOku_short();
    dump(aPlayer.cost);
}
