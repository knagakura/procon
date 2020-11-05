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
//--------------------------------my macro----------------------------------------------

#define rep(i,N) for(int i=0;i<int(N);++i)
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//--------------------------------debug functions----------------------------------------------
#define TOSTRING(x) std::string(#x)

std::ostream &operator<<(std::ostream &os, hpc::Vector2 &val) {os  << "{" << val.x << ", " << val.y << "}";return os; };
std::ostream &operator<<(std::ostream &os, hpc::Scroll &val) {os  << "{" << val.pos().x << ", " << val.pos().y << "}";return os; };
template <typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) { os  << "["; for(auto x: v) os << x << ", "; os << "]"; return os; };
template <typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T, typename U> std::ostream &operator<<(std::ostream &os, const std::pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }


#define DUMPOUT std::cerr
void dump_func(){ DUMPOUT << std::endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...)  dump_func(__VA_ARGS__) 
#define dump(...) DUMPOUT << std::string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

//--------------------------------other functions----------------------------------------------




//------------------------------------------------------------------------------------------
namespace hpc {
// 変数
const int M = Parameter::MaxScrollCount;
const int H = Parameter::StageHeight;
const int W = Parameter::StageWidth;
float beki[M+5];
int scrollN; // ステージにある巻物の個数
Vector2 ini_pos;
std::vector<Scroll> anslist; // random_moveのときに使う、移動する順序
std::vector<std::vector<Vector2>> paths; // path[idx_encode(i, j)] := i -> jへの最短経路
std::vector<int> scrollseq; // 巻物の周り順（本質情報）
int scrollseq_idx;
int cell_idx;
float distScroll[M+5][M+5];

Vector2 cellnum2pos(int cellnum){
    return Vector2(float(cellnum/W)+0.5f, float(cellnum%W+0.5f));
}
//--------------------------------my libraries----------------------------------------------
// ダイクストラ法
template<class T> class Dijkstra {
public:
    int N;
    T inf;
    std::vector<T> cost;
    std::vector<std::vector<std::pair<T, int>>> edge;
    std::vector<int> prev;
    Dijkstra(const int N_, T inf_) : N(N_), inf(inf_),cost(N_), edge(N_), prev(N_){
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
        for(int i = 0; i < N; ++i) prev[i] = -1;
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;
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
    std::vector<Vector2> get_path(int t){
        std::vector<Vector2> res;
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
    std::vector<int> Parent;
    std::vector<int> sizes;
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
        if(sizes[x] < sizes[y]) std::swap(x, y);
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
//--------------------------------my libraries----------------------------------------------


void parametar_clear(){
    anslist.clear();
    paths.clear();
    rep(i,M)rep(j,M)distScroll[i][j] = -1;
    scrollseq.clear();
}
void parametar_ini(const Stage &aStage){
    scrollN = aStage.scrolls().count() + 1; // +1は最初の点
    ini_pos = aStage.rabbit().pos();
    scrollseq_idx = 0;
    cell_idx = 0;
    paths.resize(scrollN*scrollN);

}
// 処理
Vector2 random_move(const Stage& aStage){
    // // 前の目標に到達していなかったら
    std::vector<Scroll> notGottenList;
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
        rep(k,8){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(aStage.isOutOfBounds(Vector2(nx, ny)))continue;
            Vector2 to = {float(nx), float(ny)};
            // Terrain to_tr = aStage.terrain(to);
            int to_idx = idx_encode(to);
            float cost = terrain_cost(from_tr) /*+ terrain_cost(to_tr)*/;
            G.make_edge(from_idx, to_idx, cost);
        }
    }
}

void build_distance_matrix(const Stage& aStage){
    Dijkstra<float> G(H*W, 1e5);
    build_make_edges(aStage, G);

    std::vector<Vector2> positions;
    // 巻物
    rep(i,scrollN-1)positions.push_back(aStage.scrolls()[i].pos());
    // 最初のポジション
    positions.push_back(ini_pos);


    rep(i,scrollN){
        Vector2 scroll_from = positions[i];
        int start_idx = idx_encode(scroll_from);
        G.solve(start_idx);
        rep(j,scrollN){
            Vector2 scroll_to = positions[j];
            int to_idx = idx_encode(scroll_to);
            distScroll[i][j] = G.cost[to_idx];
            paths[i*scrollN+j] = G.get_path(to_idx);
        }
    }
}
void dfs(int cur, int pre, const std::vector<std::vector<int>> &G, std::vector<int>& res){
    res.push_back(cur);
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        dfs(nxt, cur, G, res);
    }
}
// 最小全域木のアルゴリズム、クラスカル法（直線になるように調整）（ここもっといい方法あると思う）
std::vector<int> kuraskal(){
    std::vector<std::vector<int>> tree(scrollN);
    std::vector<std::pair<float, std::pair<int, int>>> scrollEdges;
    rep(i,scrollN)rep(j,scrollN){
        scrollEdges.push_back({distScroll[i][j], {i, j}});
    }
    sort(scrollEdges.begin(), scrollEdges.end());
    UnionFind Uni(scrollN);
    for(auto e: scrollEdges){
        // auto cost = e.first;
        int i = e.second.first;
        int j = e.second.second;
        if(i == scrollN-1 && not tree[i].empty())continue; // startは必ず葉にする
        if(j == scrollN-1 && not tree[j].empty())continue; // startは必ず葉にする
        if(tree[i].size() == 2)continue;
        if(tree[j].size() == 2)continue;
        if(Uni.same(i, j))continue;
        Uni.unite(i, j);
        tree[i].push_back(j);
        tree[j].push_back(i);
    }
    std::vector<int> res;
    dfs(scrollN-1, -1, tree, res);
    return res;
}

float calc_cost(const std::vector<int>& v){
    float cost = 0;
    int sz = v.size();
    rep(i,sz-1){
        int l = v[i], r = v[i+1];
        cost += distScroll[l][r] / beki[i];
    }
    return cost;
}
std::vector<int> bluteforce(){
    float min_cost = 1e5;
    std::vector<int> tmp, res;
    rep(i,scrollN-1){
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end());
    do{
        std::vector<int> tmp2;
        tmp2.push_back(scrollN-1);
        rep(i,scrollN-1)tmp2.push_back(tmp[i]);
        if(chmin(min_cost, calc_cost(tmp2))){
            res = tmp2;
        }
    }while(next_permutation(tmp.begin(), tmp.end()));
    return res;
}
// [l, r)に関して、順列を変えてみてコストが最小のものに変換する
void bluteforce(int l, int r, std::vector<int>& scrollseq_){
    chmin(r, (int)scrollseq.size());
    float min_cost = 1e5;
    std::vector<int> tmp_changed, res;
    std::vector<int> tmp_prefix, tmp_suffix;
    for(int i = 0; i < l; i++)tmp_prefix.push_back(scrollseq_[i]);
    for(int i = l; i < r; i++)tmp_changed.push_back(scrollseq_[i]);
    for(int i = r; i < (int)scrollseq_.size(); i++)tmp_suffix.push_back(scrollseq_[i]);
    sort(tmp_changed.begin(), tmp_changed.end());
    do{
        std::vector<int> tmp2;
        for(auto x: tmp_prefix)tmp2.push_back(x);
        for(auto x: tmp_changed)tmp2.push_back(x);
        for(auto x: tmp_suffix)tmp2.push_back(x);
        if(chmin(min_cost, calc_cost(tmp2))){
            scrollseq_ = tmp2;
        }
    }while(next_permutation(tmp_changed.begin(), tmp_changed.end()));
}
void build_scrollseq(const Stage &aStage){
    if(scrollN < 12){
        scrollseq.resize(scrollN);
        scrollseq[0] = scrollN-1;
        rep(i,scrollN-1)scrollseq[i+1] = i;
        bluteforce(1, scrollN, scrollseq);
        // auto tmp = kuraskal();
        // float pre_cost = calc_cost(tmp);
        // float new_cost = calc_cost(scrollseq);
        // float diff = new_cost - pre_cost;
        // dbg(scrollN, pre_cost, new_cost, diff);
    }
    else{
        // g Combine.cpp && ./a.out -r 89 35 39 90 
        scrollseq = kuraskal();

        // bluteforce(1, 10, scrollseq); // 33140 58.710s
        // bluteforce(scrollN-9, scrollN, scrollseq); // 31623 90sec (+ d * 30)

        // // none 33625 26.539s


        // // d = 2 ~ 5: TotalTurn: 32745 Time: 151.862 sec
        // // d = 3 ~ 5: TotalTurn: 32814 Time: 56.862 sec
        // // d = 3 = 5: TotalTurn: 31901 Time: 52.686 sec(default)
        // int kai = 1;    //  1: 31973, 29 sec
        //                 //   10: 31952, 32 sec
        //                 //  100: 31952, 32 sec
        // while(kai--){
        //     for(int d = 4; d <= 5; d++){
        //         int tmpd = d;
        //         int cnt = scrollN - 1;
        //         std::vector<int> lens;
        //         while(cnt > 0){
        //             int nxt_add = (cnt + tmpd - 1) / tmpd;
        //             chmin(nxt_add, 7);
        //             lens.push_back(nxt_add);
        //             cnt -= lens.back();
        //             tmpd--;
        //         }
        //         int l = 1;
        //         // dump(lens);
        //         for(auto x: lens){
        //             bluteforce(l, l+x, scrollseq);
        //             l += x;
        //         }
        //     }

        //     for(int d = 3; d <= 5; d++){
        //         int tmpd = d;
        //         int cnt = scrollN - 1;
        //         std::vector<int> lens;
        //         while(cnt > 0){
        //             int nxt_add = (cnt + tmpd - 1) / tmpd;
        //             chmin(nxt_add, 7);
        //             lens.push_back(nxt_add);
        //             cnt -= lens.back();
        //             tmpd--;
        //         }
        //         int r = scrollN;
        //         // dump(lens);
        //         for(auto x: lens){
        //             bluteforce(r-x, r, scrollseq);
        //             r -= x;
        //         }
        //     }
        // }
        // // bluteforce(1, 1+len, scrollseq); //  33130 27.130s
        // // bluteforce(1+len, 1+len+len, scrollseq);
        // // bluteforce(1+len+len, 1+len+len+len, scrollseq);
    }
}
/// コンストラクタ
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます
Answer::Answer()
{
    beki[0] = 1.0f;
    rep(i,M)beki[i+1] = beki[i] * 1.1f;
    // rep(i,M+1){
    //     std::cerr << beki[i] << " ";
    // }
    // std::cerr << std::endl;
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
/// @param aStage 現在のステージ
void Answer::initialize(const Stage& aStage)
{
    parametar_clear();
    parametar_ini(aStage);
    build_distance_matrix(aStage);
    build_scrollseq(aStage);
}
float get_jumpdist(const Stage& aStage, const Rabbit& rabbit){
    return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
}

float dist(float x, float y){
    return std::sqrt(x*x+y*y);
}
float dist(const Vector2& a,const Vector2& b){
    return dist(abs(a.x-b.x), abs(a.y-b.y));
}
//------------------------------------------------------------------------------
/// 毎フレーム呼び出される処理
/// @detail 移動先を決定して返します
/// @param aStage 現在のステージ
/// @return 移動の目標座標
Vector2 Answer::getTargetPos(const Stage& aStage){

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
    int path_idx = scroll_l* scrollN + scroll_r;
    while(cell_idx+1 < (int)paths[path_idx].size() && length > dist(now_pos, paths[path_idx][cell_idx])){
        cell_idx++;
    }
    auto res = paths[path_idx][cell_idx];
    // std::cerr << std::endl;
    // dump(scrollseq.size(), paths[path_idx].size());
    // dump(scrollseq_idx, cell_idx);
    // dump(now_pos, res);
    // dump(length, dist(now_pos, res));
    return res;

    // return random_move(aStage); // 1


}

//------------------------------------------------------------------------------
/// 各ステージ終了時に呼び出される処理
/// @detail 各ステージに対する終了処理が必要ならここに書きます
/// @param aStage 現在のステージ
void Answer::finalize(const Stage& aStage)
{
    anslist.clear();
}
} // namespace

/// 
// EOF