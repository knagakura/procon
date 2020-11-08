//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  (C)HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#include "Answer.hpp"
#include "Timer.hpp"
#include "Parameter.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
//--------------------------------my macro--------------------------------------
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
//--------------------------------debug functions-------------------------------
#define TOSTRING(x) string(#x)

ostream &operator<<(ostream &os, hpc::Vector2 &val) {os  << "{" << val.x << ", " << val.y << "}";return os; };
ostream &operator<<(ostream &os, hpc::Scroll &val) {os  << "{" << val.pos().x << ", " << val.pos().y << "}";return os; };
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto x: v) os << x << ", "; os << "]"; return os; };
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }


#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(move(tail)...); }

#ifdef DEBUG
#define dbg(...)  dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

//--------------------------------other functions----------------------------------------------




//------------------------------------------------------------------------------------------
namespace hpc {
// const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
// const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// 変数
const int StartPos = 0;
const int M = Parameter::MaxScrollCount;
const int H = Parameter::StageHeight;
const int W = Parameter::StageWidth;

const int n_Splits = 3; // 座標を何倍に拡大してみるか
float beki[M+5];
int scrollN; // ステージにある巻物の個数
Vector2 ini_pos;
vector<Scroll> anslist; // random_moveのときに使う、移動する順序
vector<int> scrollseq; // 巻物の周り順（本質情報）
int scrollseq_idx;
int cell_idx;
vector<Vector2> scrollPositions;
float distScroll2[M+5][M+5][M+5];
vector<int> dx2[100], dy2[100];
vector<float> cost2[100];
vector<vector<vector<Vector2>>> paths2;


struct Cell{
    float x, float y;
    int idx;
    Cell(){}
    Cell(float x_, float y_): x(x_), y(y_);
};
// chokudai search用のクラス。priority_queueに入れてコストを管理する
struct ScrollTour2{
    vector<int> seq;
    vector<bool> used;
    float cost = 0.0f;
    int getNum = 0;
    ScrollTour2(){
        cost = 0.0f;
        used.assign(scrollN, false);
        getNum = 0;
    }
    ScrollTour2(vector<int>& seq_): seq(seq_){
        used.assign(scrollN, false);
        for(auto x: seq){
            used[x] = true;
            getNum++;
        }
    }
    void add_scroll(int idx){
        if(seq.empty()){
            used[idx] = true;
            seq.emplace_back(idx);
            getNum++;
            return;
        }
        cost += distScroll2[getNum][seq.back()][idx];
        seq.emplace_back(idx);
        used[idx] = true;
        getNum++;
    }

    float added_cost_if(int idx){
        if(seq.empty())return 0;
        return cost + distScroll2[getNum][seq.back()][idx];
    }

    bool operator<(const ScrollTour2& b) const{
        return (*this).cost > b.cost;
    }
};

vector<priority_queue<ScrollTour2>> vpq2;




Vector2 cellnum2pos(int cellnum){
    return Vector2(float(cellnum/W)+0.5f, float(cellnum%W+0.5f));
}
//--------------------------------my libraries----------------------------------------------
constexpr double TL = 2.09;
constexpr long long CYCLES_PER_SEC = 2800000000;
struct MyTimer {
    long long start;

    MyTimer() { reset(); }

    void reset() { start = getCycle(); }

    inline double get() { return (double) (getCycle() - start) / CYCLES_PER_SEC; }

    inline long long getCycle() {
        unsigned low, high;
        __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
        return ((long long) low) | ((long long) high << 32);
    }
};


// ダイクストラ法
template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
    vector<int> prev;
    Dijkstra(const int N_, T inf_) : N(N_), inf(inf_),cost(N_), edge(N_), prev(N_){
    }

    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }

    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
        for(int i = 0; i < N; ++i) prev[i] = -1;
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({ 0,start });

        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            if(cost[from] < v)continue;
            for (auto u : edge[from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]) {
                    cost[to] = w;
                    prev[to] = from;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
    vector<Vector2> get_path(int t){
        vector<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_back(cellnum2pos(t));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 素集合データ構造
struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
            Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
};
// 乱数発生
uint32_t XorShift(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
bool issame(const hpc::Scroll &a, const hpc::Scroll &b){
    return a.pos().x == b.pos().x && a.pos().y == b.pos().y;
}
float dist(float x, float y){
    return sqrt(x*x+y*y);
}
float dist(const Vector2& a,const Vector2& b){
    return dist(abs(a.x-b.x), abs(a.y-b.y));
}
//--------------------------------my libraries----------------------------------------------



void parametar_clear(){
    anslist.clear();
    // rep(i,M)rep(j,M)distScroll[i][j] = -1;
    scrollseq.clear();
    // paths.clear();
    // vpq.clear();
    vpq2.clear();
    rep(i,M)rep(j,M)rep(k,M)distScroll2[i][j][k] = -1;
    scrollPositions.clear();
    paths2.clear();
}
void parametar_ini(const Stage &aStage){
    scrollN = aStage.scrolls().count() + 1; // +1は最初の点
    ini_pos = aStage.rabbit().pos();
    scrollseq_idx = 0;
    cell_idx = 0;
    // paths.resize(scrollN*scrollN);
    // vpq.resize(scrollN);
    vpq2.resize(scrollN);
    paths2.resize(scrollN);
    rep(i,scrollN)paths2[i].resize(scrollN*scrollN);
    // 巻物
    rep(i,scrollN-1)scrollPositions.push_back(aStage.scrolls()[i].pos());
    // 最初のポジション
    scrollPositions.push_back(ini_pos);
}
// 処理
Vector2 random_move(const Stage& aStage){
    // // 前の目標に到達していなかったら
    vector<Scroll> notGottenList;
    for(auto scroll : aStage.scrolls()) {
        if(not anslist.empty() && issame(scroll, anslist.back())){
            if(not scroll.isGotten())return scroll.pos();
        }
        // まだ手に入れていない巻物を探して、そこに向かって飛ぶ
        if (!scroll.isGotten()) {
            notGottenList.push_back(scroll);
        }
    }
    int sz = notGottenList.size();
    int rand_idx = XorShift() % sz;
    Scroll res = notGottenList[rand_idx];
    anslist.push_back(res);
    return res.pos();
}


int idx_encode(int a, int b){
    return a * W + b;
}
int idx_encode(const Vector2 &v){
    return idx_encode(v.x, v.y);
}
float terrain_magni(const Terrain& t){
    int idx = 0;
    if(t == Terrain::Plain)idx = 0; // 平地
    if(t == Terrain::Bush)idx = 1; // 茂み
    if(t == Terrain::Sand)idx = 2; // 砂池
    if(t == Terrain::Pond)idx = 3; // 池
    if(t == Terrain::TERM)idx = 0; // 置物
    return Parameter::JumpTerrianCoefficient[idx];
}
float terrain_cost(const Terrain& t){
    int idx = 0;
    if(t == Terrain::Plain)idx = 0; // 平地
    if(t == Terrain::Bush)idx = 1; // 茂み
    if(t == Terrain::Sand)idx = 2; // 砂池
    if(t == Terrain::Pond)idx = 3; // 池
    if(t == Terrain::TERM)idx = 0; // 置物
    return float(1) / Parameter::JumpTerrianCoefficient[idx];
}
template<typename T>
void build_make_edges(const Stage& aStage, Dijkstra<T>& G){
    rep(i,H)rep(j,W){
            Vector2 from = {float(i), float(j)};
            Terrain from_tr = aStage.terrain(from);
            int from_idx = idx_encode(from);
            for(int k = StartPos; k > StartPos - 8; k--){
                int nx = i + dx[(k+8)%8];
                int ny = j + dy[(k+8)%8];
                if(aStage.isOutOfBounds(Vector2(nx, ny)))continue;
                Vector2 to = {float(nx), float(ny)};
                // Terrain to_tr = aStage.terrain(to);
                int to_idx = idx_encode(to);
                float cost = terrain_cost(from_tr) /*+ terrain_cost(to_tr)*/;
                cost *= dist(dx[(k+8)%8], dy[(k+8)%8]);
                G.make_edge(from_idx, to_idx, cost);
            }
        }
}
void dfs(int cur, int pre, const vector<vector<int>> &G, vector<int>& res){
    res.push_back(cur);
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        dfs(nxt, cur, G, res);
    }
}
template<typename T>
void build_make_edges2(const Stage& aStage, Dijkstra<T>& G, const int getNum){
    rep(i,H)rep(j,W){
            Vector2 from = {float(i), float(j)};
            Terrain from_tr = aStage.terrain(from);
            int from_idx = idx_encode(from);

            int idxx = (M+1)*(int)from_tr + getNum;
            vector<int> tmp_dx = dx2[idxx];
            vector<int> tmp_dy = dy2[idxx];
            vector<float> tmp_cost = cost2[idxx];
            int sz = tmp_dx.size();
            rep(k,sz){
                int nx = i + tmp_dx[k];
                int ny = j + tmp_dy[k];
                if(aStage.isOutOfBounds(Vector2(nx, ny)))continue;
                Vector2 to = {float(nx), float(ny)};
                // Terrain to_tr = aStage.terrain(to);
                int to_idx = idx_encode(to);
                // float cost = terrain_cost(from_tr) /*+ terrain_cost(to_tr)*/;
                G.make_edge(from_idx, to_idx, tmp_cost[k]);
            }
        }
}

// いくつ取った後なのかという情報を固定したときに、scroll -> scrollの距離を計算する　-> distScroll2[getNum]に格納される
void calc_distScroll2_getNum(const Stage& aStage, const int getNum){
    Dijkstra<float> G(H*W, 1e5);
    build_make_edges2(aStage, G, getNum);
    rep(i,scrollN){
        Vector2 scroll_from = scrollPositions[i];
        int start_idx = idx_encode(scroll_from);
        G.solve(start_idx);
        rep(j,scrollN){
            Vector2 scroll_to = scrollPositions[j];
            int to_idx = idx_encode(scroll_to);
            distScroll2[getNum][i][j] = G.cost[to_idx];
            paths2[getNum][i*scrollN+j] = G.get_path(to_idx);
        }
    }
}

void build_dist_matrix2(const Stage &aStage){
    // distScroll2[getNum]を埋めるための計算をする
    for(int getNum = 0; getNum < scrollN; getNum++){
        calc_distScroll2_getNum(aStage, getNum);
    }
}
vector<int> chokudai_search2(const Stage &aStage){
    // 定数
    MyTimer timer;
    ScrollTour2 ini_tour;
    ini_tour.add_scroll(scrollN-1);
    vpq2[0].push(ini_tour);
    timer.reset();
    int cnt = 0;
    double TIME_LIMIT = 0.20;
    int Chokudai_width = 1;
    long long maxtimes = 1;
    rep(i,scrollN)maxtimes *= (i+1);
    map<vector<int>, int> mp;
    while(true){
        cnt++;
        auto now_time = timer.get();
        if(now_time >= TIME_LIMIT || vpq2.back().size() > maxtimes) break;
        for(int t = 0; t < scrollN - 1; t++){
            rep(_,Chokudai_width){
                if(vpq2[t].empty())break;
                ScrollTour2 past = vpq2[t].top();
                vpq2[t].pop();
                if(mp[past.seq] > 0)continue;
                mp[past.seq]++;
                for(int l = 0; l < scrollN; l++){
                    if(not past.used[l]){
                        ScrollTour2 nxt = past;
                        nxt.add_scroll(l);
                        vpq2[t+1].push(nxt);
                    }
                }
            }
        }
        // break;
    }
    ScrollTour2 res = vpq2[scrollN-1].top();
    dbg(scrollN);
    // dbg(ini_tour.seq, ini_tour.cost);
    dbg(res.seq, res.cost);
    return res.seq;

}


float calc_cost2(const vector<int>& v){
    float cost = 0;
    int sz = v.size();
    rep(i,sz-1){
        int l = v[i], r = v[i+1];
        cost += distScroll2[i][l][r];
    }
    return cost;
}

void bluteforce2(int l, int r, vector<int>& scrollseq_){
    chmin(r, (int)scrollseq.size());
    float min_cost = 1e5;
    vector<int> tmp_changed, res;
    vector<int> tmp_prefix, tmp_suffix;
    for(int i = 0; i < l; i++)tmp_prefix.push_back(scrollseq_[i]);
    for(int i = l; i < r; i++)tmp_changed.push_back(scrollseq_[i]);
    for(int i = r; i < (int)scrollseq_.size(); i++)tmp_suffix.push_back(scrollseq_[i]);
    sort(tmp_changed.begin(), tmp_changed.end());
    do{
        vector<int> tmp2;
        for(auto x: tmp_prefix)tmp2.push_back(x);
        for(auto x: tmp_changed)tmp2.push_back(x);
        for(auto x: tmp_suffix)tmp2.push_back(x);
        if(chmin(min_cost, calc_cost2(tmp2))){
            scrollseq_ = tmp2;
        }
    }while(next_permutation(tmp_changed.begin(), tmp_changed.end()));

}


// void build_scrollseq(const Stage &aStage){
//     if(scrollN < 12){
//         scrollseq.resize(scrollN);
//         scrollseq[0] = scrollN-1;
//         rep(i,scrollN-1)scrollseq[i+1] = i;
//         bluteforce(1, scrollN, scrollseq);
//         // scrollseq = kuraskal();
//     }
//     else{
//         // scrollseq = kuraskal();
//         scrollseq = chokudai_search(aStage);
//     }
// }

void build_scrollseq2(const Stage &aStage){
    dump(scrollN);
    if(false && scrollN < 12){
        scrollseq.resize(scrollN);
        scrollseq[0] = scrollN-1;
        rep(i,scrollN-1)scrollseq[i+1] = i;
        bluteforce2(1, scrollN, scrollseq);
        // scrollseq = kuraskal();
    }
    else{
        scrollseq = chokudai_search2(aStage);
    }
}

void build_dxdycost2(){
    const int tmpdx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    const int tmpdy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int terra = 0; terra < 4; terra++){
        for(int seq_idx = 0; seq_idx <= M; seq_idx++){
            int idx = terra * (M+1) + seq_idx;
            float length = beki[seq_idx] * Parameter::JumpTerrianCoefficient[terra];
            rep(i,8){
                float d = dist(tmpdx[i], tmpdy[i]);
                dx2[idx].push_back(tmpdx[i]);
                dy2[idx].push_back(tmpdy[i]);
                cost2[idx].push_back(d/length); // ここ本当は例えば0.3のとき4回かかるので、ちょっと微妙
            }
            // dump(idx, idx/(M+1), idx % (M+1));
            // dump(length);
            // if(length < 1){
            //     // dump(dx2[idx]);
            //     // dump(dy2[idx]);
            //     // dump(cost2[idx]);
            //     continue;
            // }
            // all direction
            // for(int i = -6; i <= 6; i++){
            //     for(int j = -6; j <= 6; j++){
            //         if(i == 0 && j == 0)continue;
            //         float d = dist(i, j);
            //         if(d <= length){
            //             dx2[idx].push_back(i);
            //             dy2[idx].push_back(j);
            //             cost2[idx].push_back(1.0);
            //         }
            //     }
            // }
            // dump(dx2[idx]);
            // dump(dy2[idx]);
            // dump(cost2[idx]);
        }
    }
}

/// コンストラクタ
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます
Answer::Answer()
{
    beki[0] = 1.0f;
    rep(i,M)beki[i+1] = beki[i] * 1.1f;
    build_dxdycost2();
}

//------------------------------------------------------------------------------
/// デストラクタ
/// @detail 最後のステージ終了後に実行したい処理があればここに書きます
Answer::~Answer()
{
}

//------------------------------------------------------------------------------
/// 各ステージ開始時に呼び出される処理
/// @detail 各ステージに対する初期化処理が必要ならここに書きます
int stagenum = 0;
/// @param aStage 現在のステージ
void Answer::initialize(const Stage& aStage)
{

    int a = stagenum++ % 20 + 1;
    {
        auto bStage = aStage;
        Vector2 b(1.0f, 1.0f);
        auto now_terrain = (int)aStage.terrain(aStage.rabbit().pos());
        auto now = aStage.rabbit().pos();
        auto nxt = bStage.getNextPos(aStage.rabbit().pos(), 1.0f, b);
        dump(now, nxt, now_terrain);
    }

    dbg(stagenum, a);
    MyTimer t;
    t.reset();
    //
    parametar_clear();
    parametar_ini(aStage);

    // build_dist_matrix(aStage); // scroll x scrollの距離行列の構築
    // build_scrollseq(aStage); // scroll Tourの構築

    build_dist_matrix2(aStage); // scroll x scrollの距離行列の構築
    build_scrollseq2(aStage); // scroll Tourの構築

    //
    dbg(t.get());
}
float get_jumpdist(const Stage& aStage, const Rabbit& rabbit){
    return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
}


//------------------------------------------------------------------------------
Vector2 MygetTargetPos2(const Stage& aStage){
    auto player = aStage.rabbit();
    Vector2 now_pos = player.pos();
    float length = get_jumpdist(aStage, player);
    while(scrollseq_idx+1 < (int)scrollseq.size() && aStage.scrolls()[scrollseq[scrollseq_idx+1]].isGotten()){ // 2
        scrollseq_idx++;
        cell_idx = 0;
    }
    // return scrollseq_idx+1 < scrollseq.size() ? aStage.scrolls()[scrollseq[scrollseq_idx+1]].pos() : aStage.rabbit().pos(); //2

    int scroll_l = scrollseq[scrollseq_idx];
    int scroll_r = scrollseq[scrollseq_idx+1];
    int getNum = scrollseq_idx;
    int path_idx = scroll_l* scrollN + scroll_r;
    while(cell_idx+1 < (int)paths2[getNum][path_idx].size() && length > dist(now_pos, paths2[getNum][path_idx][cell_idx])){
        cell_idx++;
    }
    auto res = paths2[getNum][path_idx][cell_idx];
    return res;
}

/// 毎フレーム呼び出される処理
/// @detail 移動先を決定して返します
/// @param aStage 現在のステージ
/// @return 移動の目標座標
Vector2 Answer::getTargetPos(const Stage& aStage){
    // return MygetTargetPos(aStage);
    return MygetTargetPos2(aStage);
}

//------------------------------------------------------------------------------
/// 各ステージ終了時に呼び出される処理
/// @detail 各ステージに対する終了処理が必要ならここに書きます
/// @param aStage 現在のステージ
void Answer::finalize(const Stage& aStage)
{
}
} // namespace

///
// EOF