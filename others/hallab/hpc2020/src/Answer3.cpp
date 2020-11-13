//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  (C)HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#include "Answer.hpp"
#include "Parameter.hpp"
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <random>
#include <deque>
//--------------------------------my macro--------------------------------------
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
//--------------------------------debug functions-------------------------------

ostream &operator<<(ostream &os, hpc::Vector2 &val) {os  << "{" << val.x << ", " << val.y << "}";return os; }
ostream &operator<<(ostream &os, hpc::Scroll &val) {os  << "{" << val.pos().x << ", " << val.pos().y << "}";return os; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto x: v) os << x << ", "; os << "]"; return os; }
template <typename T> ostream &operator<<(ostream &os, const deque<T> &v) { os  << "["; for(auto x: v) os << x << ", "; os << "]"; return os; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }


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
//--------------------------------debug functions-------------------------------

namespace hpc {
const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// 変数
const int M = Parameter::MaxScrollCount;
const int H = Parameter::StageHeight;
const int W = Parameter::StageWidth;
//const int n_Splits = 3; // 座標を何倍に拡大してみるか, 中心を定義したいので奇数
//const int Hn = H * n_Splits;
//const int Wn = W * n_Splits;

//--------------------------------my libraries----------------------------------------------
class MyAnswer{
public:
    vector<Vector2> PositionSeq;
    int StageNum = 0;
    int positionSeqIdx{};

    // Solverクラスを選択する変数
    int SolverSelection = 2;
    static const int Random = 0;
    static const int BluteKur = 1;
    static const int BluteKurCell = 2;
    static const int TSPSolver = 3;
    // cnhokudai_searchに関するパラメータ
    int CHOKUDAI_INITIATION = CHOKUDAI_INITIATION_NULL;
    static const int CHOKUDAI_INITIATION_NULL = 0;
    static const int CHOKUDAI_INITIATION_KUR = 1;
    static const int BluteMAX_N = 0; // ((BluteMAX_N-1) !の計算量を許す)
    constexpr static const float CHOKUDAI_SEARCH_TIME_LIMIT_ALL = 0.20;
    constexpr static const float CHOKUDAI_SEARCH_TIME_LIMIT_SMALL = CHOKUDAI_SEARCH_TIME_LIMIT_ALL;
    constexpr static const float CHOKUDAI_SEARCH_TIME_LIMIT_MEDIAM = CHOKUDAI_SEARCH_TIME_LIMIT_ALL;
    constexpr static const float CHOKUDAI_SEARCH_TIME_LIMIT_LARGE = CHOKUDAI_SEARCH_TIME_LIMIT_ALL;
    constexpr static const float SIMULATION_TIME_LIMT = 0.10;
    constexpr static const int SCROLLN_MAX_SMALL = 10;
    constexpr static const int SCROLLN_MAX_MEDIAM = 15;
    static const int CHOKUDAI_WIDTH = 1;
    static const bool VISITED_CHECK = false; // iterationの回数が少なくなるから禁止！


    constexpr static const float TSP_TIME_LIMIT = 0.1;

    static const int n_Splits = 5; // 座標を何倍に拡大してみるか, 中心を定義したいので奇数
    static const int Hn = H * n_Splits;
    static const int Wn = W * n_Splits;
    explicit MyAnswer(int type_): SolverSelection(type_){
        clear();
    }
    void clear(){
        StageNum++;
        PositionSeq.clear();
        positionSeqIdx = 0;
    }
};
#define n_Splits MyAnswer::n_Splits
#define Hn MyAnswer::Hn
#define Wn MyAnswer::Wn

class CellStage {
public:
    // 共通
    vector <vector<Vector2>> pos; // n_Splitしたcellのposition
    float beki[M + 5]{};
    long long fact[M+5]{};
    // 共通Initiation
    CellStage() = default;
    void Initiation(){
        buildCellPos();
        buildBeki();
        if(MyAnswer::VISITED_CHECK)buildFact();
    }
    void buildCellPos(){
        pos.resize(Hn);
        rep(i, Hn) {
            pos[i].resize(Wn);
            rep(j, Wn) {
                pos[i][j] = {float(2 * i + 1) / float(2 * n_Splits),
                             float(2 * j + 1) / float(2 * n_Splits)};
            }
        }
    }
    void buildBeki(){
        beki[0] = 1.0f;
        rep(i,M)beki[i+1] = beki[i] * Parameter::JumpPowerUpRate;
    }
    void buildFact(){
        fact[0] = 1;
        rep(i,M)fact[i+1] = fact[i] * (i+1);
    }
    // インターフェース
    Vector2 getCellPos(int i, int j){
        return pos[i][j];
    }
    static pair<int, int> getCellCenterIdx(const Vector2 &v){
        return getCellCenterIdx(v.x, v.y);
    }
    static pair<int, int> getCellCenterIdx(int i, int j){
//        assert(0 <= i && i < H && 0 <= j && j < W);
        return {n_Splits * i + n_Splits / 2,
                n_Splits * j + n_Splits / 2};
    }
    Vector2 getCellCenterPos(int i, int j){
//        assert(0 <= i && i < H && 0 <= j && j < W);
        pair<int, int> CenterIdx = getCellCenterIdx(i, j);
        return getCellPos(CenterIdx.first, CenterIdx.second);
    }
    Vector2 getCellCenterPos(const Vector2& v){
        return getCellCenterPos(int(v.x), int(v.y));
    }
    Vector2 cellIdx2Pos(int cellIdx){
        return getCellPos(cellIdx / Wn, cellIdx % Wn);
    }
    bool isOutOfBounds(int i, int j){
        return i < 0 || i >= Hn || j < 0 || j  >= Wn;
    }
    bool isOutOfBounds(const Vector2 aPos) const
    {
        if(aPos.x < 0.0f || Parameter::StageWidth <= aPos.x || aPos.y < 0.0f || Parameter::StageHeight <= aPos.y) {
            return true;
        } else {
            return false;
        }
    }
    // その座標と同じ升目にあるますを列挙する
    vector<Vector2> getAroundCells(int i, int j){
        pair<int,int> centerPIdx = getCellCenterIdx(i, j);
        int centerI = centerPIdx.first;
        int centerJ = centerPIdx.second;
        vector<Vector2> res;
        for(int di = - n_Splits / 2; di <= n_Splits/2; di++){
            for(int dj = - n_Splits / 2; dj <= n_Splits/2; dj++) {
                int ni = centerI + di;
                int nj = centerJ + dj;
                if(isOutOfBounds(ni, nj))continue;
                res.emplace_back(pos[ni][nj]);
            }
        }
        return res;
    }
    vector<Vector2> getAroundCells(const Vector2& v){
        return getAroundCells((int)v.x, (int)v.y);
    }
};


// ------------------------------------------------------------
CellStage aCellStage; // 一番最初に行われる処理。
MyAnswer aMyAnswer(2);
// ------------------------------------------------------------

constexpr long long CYCLES_PER_SEC = 2800000000;
struct MyTimer {
        long long start{};

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
    Dijkstra(const int N_, T inf_) : N(N_), inf(inf_),cost(N_), edge(N_), prev(N_){}
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
    }
    vector<Vector2> getFieldPath(int t){
        vector<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_back(fieldIdx2pos(t));
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<Vector2> getCellPath(int t){
        vector<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_back(cellIdx2Pos(t));
        }
        reverse(res.begin(), res.end());
        return res;
    }

    deque<Vector2> getFieldPathDeque(int t){
        deque<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_front(fieldIdx2pos(t));
        }
        // reverse(res.begin(), res.end());
        return res;
    }
    deque<Vector2> getCellPathDeque(int t){
        deque<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_front(cellIdx2Pos(t));
        }
        // reverse(res.begin(), res.end());
        return res;
    }
    Vector2 fieldIdx2pos(int fieldIdx){
        return {float(fieldIdx/W)+0.5f, float(fieldIdx%W+0.5f)};
    }
    Vector2 cellIdx2Pos(int cellIdx){
        return aCellStage.cellIdx2Pos(cellIdx);
    }
};
// 素集合データ構造
struct UnionFind{
        int n;
        vector<int> Parent;
        vector<int> sizes;
        explicit UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
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
uint32_t XorShift() {
        static uint32_t x = 123456789;
        static uint32_t y = 362436069;
        static uint32_t z = 521288629;
        static uint32_t w = 88675123;
        uint32_t t;

        t = x ^ (x << 11);
        x = y; y = z; z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }
//--------------------------------my libraries----------------------------------------------

class SolverBase{
public:
    // 特有
    Stage bStage;
    int scrollN;
    Vector2 iniPos;
    vector<int> PositionSeq;
    SolverBase(){};
    SolverBase(const Stage &aStage){
        stageInitiation(aStage);
    }
    // 特有Initiation
    void stageInitiation(const Stage& aStage){
        bStage = aStage;
        scrollN = bStage.scrolls().count() + 1;
        iniPos = bStage.rabbit().pos();
    }
    // 変数の初期化
    virtual vector<Vector2> solve() = 0;
    bool isSame(const hpc::Scroll &a, const hpc::Scroll &b){
        return isSame(a.pos(), b.pos());
    }
    bool isSame(const Vector2 &a, const Vector2 &b){
        return (int)a.x == (int)b.x && (int)a.y == (int)b.y;
    }
    float dist(float x, float y){
        return sqrt(x*x+y*y);
    }
    float dist(const Vector2& a,const Vector2& b){
        return dist(abs(a.x-b.x), abs(a.y-b.y));
    }
    int idxEncodeCell(int a, int b){
        return a * Wn + b;
    }
    int idx_encode(int a, int b){
        return a * W + b;
    }
    int idx_encode(const Vector2 &v){
        return idx_encode(v.x, v.y);
    }
    // rabbitとか打つの大変なときに
    Vector2 getNextPosEasy(const Vector2& aTargetPos){
        return bStage.getNextPos(bStage.rabbit().pos(),
                                 bStage.rabbit().power(),
                                 aTargetPos);
    }
};

class RandomSolver : public SolverBase{
public:
    vector<Scroll> scrollList; // random_moveのときに使う、移動する順序
    RandomSolver(): SolverBase(){}
    explicit RandomSolver(const Stage& aStage): SolverBase(aStage){}
    vector<Vector2> solve() override{
        return random_move();
    }
    vector<Vector2> random_move(){
        dump("random_move");
        // 前の目標に到達していなかったら
        int idx = 0;
        int sz = bStage.scrolls().count();
        idx = XorShift() % sz;
        dump(idx);
        vector<Vector2> res;
        while(not bStage.isEnd()) {
            while(bStage.scrolls()[idx].isGotten()){
                idx = XorShift() % sz;
            }
            while(not bStage.scrolls()[idx].isGotten()){
                auto NextPos = getNextPosEasy(bStage.scrolls()[idx].pos());
                bStage.update(NextPos);
                res.emplace_back(NextPos);
            }
        }
        return res;
    }
};


class BluteKurSolver : public SolverBase{
public:
    struct ScrollTour{
        vector<int> seq;
        vector<bool> used;
        float cost = 0.0f;
        ScrollTour(){
            cost = 0.0f;
            used.assign(M+5, false);
        }
        explicit ScrollTour(vector<int>& seq_): seq(seq_){
            cost  = 0.0f;
            used.assign(M+5, false);
            for(auto x: seq)used[x] = true;
        }
        void add_scroll(const BluteKurSolver &Solver, int idx){
            if(seq.empty()){
                used[idx] = true;
                seq.emplace_back(idx);
                return;
            }
            used[idx] = true;
            cost += Solver.distScroll[seq.back()][idx] / aCellStage.beki[(int)seq.size()-1];
            seq.emplace_back(idx);
        }

        float added_cost_if(const BluteKurSolver &Solver, int idx) const{
            if(seq.empty())return 0;
            return cost + Solver.distScroll[seq.back()][idx] / aCellStage.beki[(int)seq.size()-1];
        }
        bool operator<(const ScrollTour& b) const{
            return (*this).cost > b.cost;
        }
    };

    float distScroll[M + 5][M + 5]{};
    vector<vector<Vector2>> paths; // path[idx_encode(i, j)] := i -> jへの最短経路
    vector<priority_queue<ScrollTour>> vpq;
    vector<int> scrollSeq;
    int scrollSeqIdx{};
    int cellIdx{};
    BluteKurSolver(): SolverBase(){}
    Vector2 ini_pos;
    explicit BluteKurSolver(const Stage& aStage): SolverBase(aStage){
        ini_pos = aStage.rabbit().pos();
        vpq.resize(scrollN+5);
        paths.resize(scrollN * scrollN);
    }
    vector<Vector2> solve() override{
        buildDistanceMatrix();
        buildScrollSeq();
        return moveByScrollSeq();
    }
    float getJumpDist(const Stage& aStage, const Rabbit& rabbit){
        return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
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
    vector<Vector2> moveByScrollSeq(){
        Stage pseudoStage = bStage; // この後も初期状態を使う可能性があるので完全には破壊したくない
        vector<Vector2> res;
        scrollSeqIdx = 0;
        cellIdx = 0;
        while(not pseudoStage.isEnd()) {
            auto player = pseudoStage.rabbit();
            Vector2 now_pos = player.pos();
            float length = getJumpDist(pseudoStage, player);
            while (scrollSeqIdx + 1 < (int) scrollSeq.size() &&
                   pseudoStage.scrolls()[scrollSeq[scrollSeqIdx + 1]].isGotten()) { // 2
                scrollSeqIdx++;
                cellIdx = 0;
            }
            int scroll_l = scrollSeq[scrollSeqIdx];
            int scroll_r = scrollSeq[scrollSeqIdx + 1];
            int path_idx = scroll_l * scrollN + scroll_r;
            while (cellIdx + 1 < (int) paths[path_idx].size() && length > dist(now_pos, paths[path_idx][cellIdx])) {
                cellIdx++;
            }
            auto nextPos = paths[path_idx][cellIdx];
            pseudoStage.update(nextPos);
            res.emplace_back(pseudoStage.rabbit().pos());
        }
        return res;
    }
    void buildScrollSeq(){
        if(scrollN <= MyAnswer::BluteMAX_N){
            bluteForce(1, scrollN);
        }
        else{
            scrollSeq = chokudaiSearch();
        }
    }
    float calcCost(const vector<int>& v){
        float cost = 0;
        int sz = v.size();
        rep(i,sz-1){
            int l = v[i], r = v[i+1];
            cost += distScroll[l][r] / aCellStage.beki[i];
        }
        return cost;
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
    void buildMakeEdges(Dijkstra<T>& G){
        rep(i,H)rep(j,W){
                Vector2 from = {float(i), float(j)};
                Terrain from_tr = bStage.terrain(from);
                int from_idx = idx_encode(from);
                rep(k,8){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(bStage.isOutOfBounds(Vector2(nx, ny)))continue;
                    Vector2 to = {float(nx), float(ny)};
                    // Terrain to_tr = aStage.terrain(to);
                    int to_idx = idx_encode(to);
                    float cost = terrain_cost(from_tr) * dist(dx[k], dy[k])/*+ terrain_cost(to_tr)*/;
                    G.make_edge(from_idx, to_idx, cost);
                }
            }
    }
    void buildDistanceMatrix(){
        Dijkstra<float> G(H*W, 1e5);
        buildMakeEdges(G);
        buildPaths(G);
    }
    template <typename T>
    void buildPaths(Dijkstra<T> &G){
        vector<Vector2> positions;
        // 巻物
        rep(i,scrollN-1)positions.push_back(bStage.scrolls()[i].pos());
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
                paths[i*scrollN+j] = G.getFieldPath(to_idx);
            }
        }
    }
    // [l, r)に関して、順列を変えてみてコストが最小のものに変換する
    void bluteForce(int l, int r){
        scrollSeq.resize(scrollN);
        scrollSeq[0] = scrollN-1;
        rep(i,scrollN-1)scrollSeq[i+1] = i;
        chmin(r, (int)scrollSeq.size());
        float min_cost = 1e5;
        vector<int> tmp_changed, res;
        vector<int> tmp_prefix, tmp_suffix;
        for(int i = 0; i < l; i++)tmp_prefix.push_back(scrollSeq[i]);
        for(int i = l; i < r; i++)tmp_changed.push_back(scrollSeq[i]);
        for(int i = r; i < (int)scrollSeq.size(); i++)tmp_suffix.push_back(scrollSeq[i]);
        sort(tmp_changed.begin(), tmp_changed.end());
        do{
            vector<int> tmp2;
            for(auto x: tmp_prefix)tmp2.push_back(x);
            for(auto x: tmp_changed)tmp2.push_back(x);
            for(auto x: tmp_suffix)tmp2.push_back(x);
            if(chmin(min_cost, calcCost(tmp2))){
                scrollSeq = tmp2;
            }
        }while(next_permutation(tmp_changed.begin(), tmp_changed.end()));
    }
    void dfs(int cur, int pre, const vector<vector<int>> &G, vector<int>& res){
        res.push_back(cur);
        for(auto nxt: G[cur]){
            if(nxt == pre)continue;
            dfs(nxt, cur, G, res);
        }
    }
    // 最小全域木のアルゴリズム、クラスカル法（直線になるように調整）（ここもっといい方法あると思う）
    vector<int> kuraskal(){
        vector<vector<int>> tree(scrollN);
        vector<pair<float, pair<int, int>>> scrollEdges;
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
        vector<int> res;
        dfs(scrollN-1, -1, tree, res);
        return res;
    }
    vector<int> chokudaiSearch(){
        // 定数
        MyTimer timer;
        timer.reset();
        //　初期はクラスカルでやる
        auto ini_seq = kuraskal();
        ScrollTour ini_tour;
        // ターン毎にpqに突っ込んでいく
        rep(t,scrollN){
            ini_tour.add_scroll(*this, ini_seq[t]);
            vpq[t].push(ini_tour);
        }
        while(true){
            if(timerCheck(timer.get())) break;
            for(int t = 0; t < scrollN - 1; t++){
                if(timerCheck(timer.get())) break;
                rep(_,MyAnswer::CHOKUDAI_WIDTH){
                    if(timerCheck(timer.get())) break;
                    if(vpq[t].empty())break;
                    ScrollTour past = vpq[t].top();
                    vpq[t].pop();
                    for(int l = 0; l < scrollN; l++){
                        if(not past.used[l]){
                            ScrollTour nxt = past;
                            nxt.add_scroll(*this, l);
                            vpq[t+1].push(nxt);
                        }
                    }
                }
            }
        }
        ScrollTour res = vpq[scrollN-1].top();
        return res.seq;
    }
    bool timerCheck(float nowTime){
        return nowTime >= MyAnswer::CHOKUDAI_SEARCH_TIME_LIMIT_LARGE;
    }
};

class BluteKurCellSolver : public SolverBase{
public:
    struct ScrollTour{
        vector<int> seq;
        vector<bool> used;
        float cost = 0.0f;
        ScrollTour(){
            cost = 0.0f;
            used.assign(M+5, false);
        }
        explicit ScrollTour(vector<int>& seq_): seq(seq_){
            cost  = 0.0f;
            used.assign(M+5, false);
            for(auto x: seq)used[x] = true;
        }
        void add_scroll(BluteKurCellSolver &Solver, int idx){
            if(seq.empty()){
                used[idx] = true;
                seq.emplace_back(idx);
                if(MyAnswer::VISITED_CHECK)Solver.isVisited[seq]++;
                return;
            }
            used[idx] = true;
            cost += Solver.distScroll[seq.back()][idx] / aCellStage.beki[(int)seq.size()-1];
            seq.emplace_back(idx);
            if(MyAnswer::VISITED_CHECK)Solver.isVisited[seq]++;
        }
        bool isEmpty(){
            return seq.empty();
        }
        float added_cost_if(const BluteKurCellSolver &Solver, int idx) const{
            if(seq.empty())return 0;
            return cost + Solver.distScroll[seq.back()][idx] / aCellStage.beki[(int)seq.size()-1];
        }
        bool operator<(const ScrollTour& b) const{
            return (*this).cost > b.cost;
        }
    };
    float distScroll[M + 5][M + 5]{};
    vector<deque<Vector2>> pathsDeque;
    vector<priority_queue<ScrollTour>> vpq;
    vector<int> vpqSizes;
    float vpqLastMinCost;
    vector<ScrollTour> betterScrollTours;
    int scrollSeqIdx{};
    int cellIdx{};
    map<vector<int>, long long> isVisited;
    BluteKurCellSolver(): SolverBase(){}
    Vector2 ini_pos;
    explicit BluteKurCellSolver(const Stage& aStage): SolverBase(aStage){
        ini_pos = aStage.rabbit().pos();
        vpq.resize(scrollN);
        vpqSizes.assign(scrollN,0);
        pathsDeque.resize(scrollN * scrollN);
        if(MyAnswer::VISITED_CHECK)isVisited.clear();
        vpqLastMinCost = 1e9;
    }
    vector<Vector2> solve() override{
        buildDistanceMatrix();
        // これらの変数は、scrollSeqに依存して変化
        vector<int> BestScrollSeq;
        vector<deque<Vector2>> BestPathsDeque = pathsDeque;
        //
        buildScrollSeq(BestScrollSeq);
        int realMinCost = (int)1e8;
        // chokudai searchでよくなる途中が見れる
        dbg(betterScrollTours[0].seq, betterScrollTours[0].cost);
        sort(betterScrollTours.begin(), betterScrollTours.end(), [](const ScrollTour&a, const ScrollTour &b){
            return a.cost < b.cost;
        });
        MyTimer t;
        t.reset();
        for(int i = 0; i < (int)betterScrollTours.size(); i++){
            if(t.get() > MyAnswer::SIMULATION_TIME_LIMT){
                dump(i);
                break;
            }
            auto tmpTour = betterScrollTours[i];
            auto tmpScrollseq = tmpTour.seq;
            auto tmpPathsDeque = pathsDeque;
            int tmpCost = calcCostFromScrollSeq(tmpScrollseq, tmpPathsDeque);
            if(chmin(realMinCost, tmpCost)){
                swap(BestScrollSeq,tmpScrollseq);
                swap(BestPathsDeque,tmpPathsDeque);
                dbg(tmpTour.seq, tmpTour.cost, tmpCost);
            }
        }
        dump(betterScrollTours.size());
        setScrollPosAfterBuildScrollSeq(BestScrollSeq, BestPathsDeque);
        return moveByScrollSeq(BestScrollSeq, BestPathsDeque);
    }
    int calcCostFromScrollSeq(const vector<int> &tmpSeq, vector<deque<Vector2>> &tmpPathsDeque){
        setScrollPosAfterBuildScrollSeq(tmpSeq, tmpPathsDeque);
        auto x = moveByScrollSeq(tmpSeq, tmpPathsDeque);
        return x.size();
    }
    float getJumpDist(const Stage& aStage, const Rabbit& rabbit){
        return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
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
    void setScrollPosAfterBuildScrollSeq(const vector<int>&scrollSeq, vector<deque<Vector2>> &pathsDequeNow){
        for(int i = 0; i < scrollN - 2; i++){
            int l = scrollSeq[i];
            int mid = scrollSeq[i+1];
            int r = scrollSeq[i+2];
            int pathLIdx = l * scrollN + mid;
            int pathRIdx = mid * scrollN + r;
            // rの位置を設定する
            Vector2 midScrollPos = bStage.scrolls()[mid].pos();
            while(isSame(pathsDequeNow[pathLIdx].back(), midScrollPos)){
                pathsDequeNow[pathLIdx].pop_back();
            }
            while(isSame(pathsDequeNow[pathRIdx].front(), midScrollPos)){
                pathsDequeNow[pathRIdx].pop_front();
            }
            pair<int, int> midScrollCellCenterIdx = aCellStage.getCellCenterIdx(midScrollPos);
            int midCenterX = midScrollCellCenterIdx.first;
            int midCenterY = midScrollCellCenterIdx.second;
            int scrollX = midCenterX;
            int scrollY = midCenterY;
            Vector2 NewScrollPos = aCellStage.getCellPos(scrollX, scrollY);
            Vector2 LPos = pathsDequeNow[pathLIdx].back();
            Vector2 RPos = pathsDequeNow[pathRIdx].front();

            float sumDist = dist(LPos, midScrollPos) + dist(RPos, midScrollPos);
            for(int dxx = -n_Splits / 2; dxx <= n_Splits/2; dxx++) {
                for (int dyy = -n_Splits / 2; dyy <= n_Splits / 2; dyy++) {
                    int nx = midCenterX + dxx;
                    int ny = midCenterY + dyy;
                    if (aCellStage.isOutOfBounds(nx, ny))continue;
                    Vector2 tmpScrollPos = aCellStage.getCellPos(nx, ny);
                    float sumDistTmp = dist(LPos, tmpScrollPos) + dist(RPos, tmpScrollPos);
                    if (chmin(sumDist, sumDistTmp)) {
                        NewScrollPos = aCellStage.getCellPos(nx, ny);
                    }
                }
            }
//            float ScrollIntX = int(NewScrollPos.x);
//            float ScrollIntY = int(NewScrollPos.y);
//            for(float dd = 0.0; dd < 1.0; dd += 0.099){
//                Vector2 tmpScrollPos = {ScrollIntX + dd, ScrollIntY};
//                float sumDistTmp = dist(LPos, tmpScrollPos) + dist(RPos, tmpScrollPos);
//                if(chmin(sumDist, sumDistTmp)){
//                    NewScrollPos = tmpScrollPos;
//                }
//                tmpScrollPos = {ScrollIntX, ScrollIntY + dd};
//                sumDistTmp = dist(LPos, tmpScrollPos) + dist(RPos, tmpScrollPos);
//                if(chmin(sumDist, sumDistTmp)){
//                    NewScrollPos = tmpScrollPos;
//                }
//            }
            pathsDequeNow[pathLIdx].push_back(NewScrollPos);
            pathsDequeNow[pathRIdx].push_front(NewScrollPos);
        }
    }
    bool shouldGaman(const Stage &tmpStage, const int path_idx, const vector<deque<Vector2>> &pathsDequeNow){
        int nowRabiTer = (int) tmpStage.terrain(tmpStage.rabbit().pos());
        auto nowTargetCellPos = pathsDequeNow[path_idx][cellIdx];
        auto nxtTargetCellPos = pathsDequeNow[path_idx][cellIdx+1];
        auto nowCellPos = tmpStage.getNextPos(tmpStage.rabbit().pos(), tmpStage.rabbit().power(), nowTargetCellPos);
        auto nxtCellPos = tmpStage.getNextPos(tmpStage.rabbit().pos(), tmpStage.rabbit().power(), nxtTargetCellPos);
//        int nowCellTer = (int) tmpStage.terrain(pathsDequeNow[path_idx][cellIdx]);
//        int nxtCellTer = (int) tmpStage.terrain(pathsDequeNow[path_idx][cellIdx + 1]);
        int nowCellTer = (int) tmpStage.terrain(nowCellPos);
        int nxtCellTer = (int) tmpStage.terrain(nxtCellPos);
        return nowRabiTer == nowCellTer && nxtCellTer - nowCellTer > 1;
    }
    bool shouldMate(const Stage &tmpStage, const int path_idx, const int targetScrollIdx, const vector<deque<Vector2>> &pathsDequeNow){
//            Vector2 nowRabitPos = tmpStage.rabbit().pos();
        Vector2 nowCellPos = pathsDequeNow[path_idx][cellIdx];
        Vector2 nowTargetScrollPos = tmpStage.scrolls()[targetScrollIdx].pos();
        Vector2 nxtCellPos = pathsDequeNow[path_idx][cellIdx];
        if(not isSame(nowCellPos, nowTargetScrollPos))return false; // 今のマスが目指してる巻物圏内である必要がある
        if(not path_idx + 1 < scrollN)return false; //　今のpathが最後ではないことが必要
        int notScrollCellIdx = 0;
        while(isSame(pathsDequeNow[path_idx + 1][notScrollCellIdx], nowTargetScrollPos)){
            notScrollCellIdx++;
        }
        Vector2 nxtPathStartPos = pathsDequeNow[path_idx + 1][notScrollCellIdx];
        return dist(nowCellPos, nxtPathStartPos) < dist(nxtCellPos, nxtPathStartPos);
    }
    vector<Vector2> moveByScrollSeq(const vector<int> &scrollSeq, const vector<deque<Vector2>> &pathsDequeNow, bool isTimeShow = false, bool isReConstruct = false){
        MyTimer t;
        if(isTimeShow)t.reset();
        Stage pseudoStage = bStage; // この後も初期状態を使う可能性があるので完全には破壊したくない
        vector<Vector2> res;
        scrollSeqIdx = 0;
        cellIdx = 0;
        while(not pseudoStage.isEnd()) {
            auto player = pseudoStage.rabbit();
            Vector2 now_pos = player.pos();
            float length = getJumpDist(pseudoStage, player);
            while (scrollSeqIdx + 1 < (int) scrollSeq.size() &&
                    pseudoStage.scrolls()[scrollSeq[scrollSeqIdx + 1]].isGotten()) { // 2
                scrollSeqIdx++;
                cellIdx = 0;
            }
            int scroll_l = scrollSeq[scrollSeqIdx];
            int scroll_r = scrollSeq[scrollSeqIdx + 1];
            int path_idx = scroll_l * scrollN + scroll_r;
            bool isSecondMove = false;
            while (cellIdx + 1 < (int) pathsDequeNow[path_idx].size() && length > dist(now_pos, pathsDequeNow[path_idx][cellIdx])) {
                if(isSecondMove && shouldGaman(pseudoStage, path_idx, pathsDequeNow))break;
                if(isSecondMove && shouldMate(pseudoStage, path_idx, scroll_r, pathsDequeNow))break;
                cellIdx++;
                isSecondMove = true;
            }
            auto nextTargetPos = pathsDequeNow[path_idx][cellIdx];
//            if(isReConstruct) {
//                auto nxtPos = pseudoStage.getNextPos(now_pos, player.power(), nextTargetPos);
//                if (cellIdx + 1 < pathsDequeNow[path_idx].size()-5 && not isSame(now_pos, nxtPos)) {
//                    auto nnPos = pathsDequeNow[path_idx].back();
//                    float minDist = dist(now_pos, nxtPos) + dist(nxtPos, nnPos);
//                    for(const Vector2 &tmpTargetPos: aCellStage.getAroundCells(nxtPos)){
//                        auto tmpNxtPos = pseudoStage.getNextPos(now_pos, player.power(), tmpTargetPos);
//                        float tmpDist = dist(now_pos, tmpNxtPos) + dist(tmpNxtPos, nnPos);
//                        if(length < dist(now_pos, tmpTargetPos) && length < dist(nxtPos, nnPos) && chmin(minDist, tmpDist)){
//                            nextTargetPos = tmpTargetPos;
//                        }
//                    }
//                }
//            }
            pseudoStage.update(nextTargetPos);
            res.emplace_back(pseudoStage.rabbit().pos());
        }
        if(isTimeShow) {
            dbg(t.get());
        }
        return res;
    } //
    virtual void buildScrollSeq(vector<int> &scrollSeq){
        if(scrollN <= MyAnswer::BluteMAX_N){
            bluteForce(1, scrollN, scrollSeq);
        }
        else {
            float TIME_LIMIT;
            if (scrollN - 1 <= MyAnswer::SCROLLN_MAX_SMALL)TIME_LIMIT = MyAnswer::CHOKUDAI_SEARCH_TIME_LIMIT_SMALL;
            else if (scrollN - 1 <= MyAnswer::SCROLLN_MAX_MEDIAM)TIME_LIMIT = MyAnswer::CHOKUDAI_SEARCH_TIME_LIMIT_MEDIAM;
            else TIME_LIMIT = MyAnswer::CHOKUDAI_SEARCH_TIME_LIMIT_LARGE;
            chokudaiSearch(scrollSeq, TIME_LIMIT);
        }
    }
    float calcCost(const vector<int>& v){
        float cost = 0;
        int sz = v.size();
        rep(i,sz-1){
            int l = v[i], r = v[i+1];
            cost += distScroll[l][r] / aCellStage.beki[i];
        }
        return cost;
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
    void buildMakeEdges(Dijkstra<T>& G){ //
        int Dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int Dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        rep(i,Hn)rep(j,Wn){
//                    Vector2 from = {float(i), float(j)};
                Vector2 from = aCellStage.getCellPos(i, j);
                Terrain from_tr = bStage.terrain(from);
                int from_idx = idxEncodeCell(i, j);
                rep(k,8){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(aCellStage.isOutOfBounds(nx, ny))continue;
//                        Vector2 to = aCellStage.getCellPos(i, j);
                    // Terrain to_tr = aStage.terrain(to);
                    int to_idx = idxEncodeCell(nx, ny);
                    float cost = terrain_cost(from_tr) * dist(dx[k], dy[k])/*+ terrain_cost(to_tr)*/;
                    G.make_edge(from_idx, to_idx, cost);
                }
                rep(k,8){
                    int nx = i + Dx[k];
                    int ny = j + Dy[k];
                    if(aCellStage.isOutOfBounds(nx, ny))continue;
//                        Vector2 to = aCellStage.getCellPos(i, j);
                    // Terrain to_tr = aStage.terrain(to);
                    int to_idx = idxEncodeCell(nx, ny);
                    float cost = terrain_cost(from_tr) * dist(Dx[k], Dy[k])/*+ terrain_cost(to_tr)*/;
                    G.make_edge(from_idx, to_idx, cost);
                }
            }
    } // Cell仕様
    void buildDistanceMatrix(){
        Dijkstra<float> G(Hn*Wn, 1e5);
        buildMakeEdges(G);
        buildPaths(G);
    } // Cell仕様
    template <typename T>
    void buildPaths(Dijkstra<T> &G){ //
        MyTimer t;
        t.reset();
        vector<Vector2> positions;
        // 巻物
        rep(i,scrollN-1)positions.push_back(bStage.scrolls()[i].pos());
        // 最初のポジション
        positions.push_back(ini_pos);
        rep(i,scrollN){
            Vector2 scroll_from = positions[i];
            pair<int, int> startCellIdx = aCellStage.getCellCenterIdx(scroll_from);
            int start_idx = idxEncodeCell(startCellIdx.first, startCellIdx.second);
            G.solve(start_idx);
            rep(j,scrollN){
                Vector2 scroll_to = positions[j];
                pair<int, int> toCellIdx = aCellStage.getCellCenterIdx(scroll_to);
                int to_idx = idxEncodeCell(toCellIdx.first, toCellIdx.second);
                distScroll[i][j] = G.cost[to_idx];
//                    paths[i*scrollN+j] = G.getCellPath(to_idx);
                pathsDeque[i*scrollN+j] = G.getCellPathDeque(to_idx);
            }
        }
//            dump("buildPath", t.get());
    } // Cell仕様
    virtual // [l, r)に関して、順列を変えてみてコストが最小のものに変換する
    void bluteForce(int l, int r, vector<int> &scrollSeq){
        scrollSeq.resize(scrollN);
        scrollSeq[0] = scrollN-1;
        rep(i,scrollN-1)scrollSeq[i+1] = i;
        chmin(r, (int)scrollSeq.size());
        float min_cost = 1e5;
        vector<int> tmp_changed, res;
        vector<int> tmp_prefix, tmp_suffix;
        for(int i = 0; i < l; i++)tmp_prefix.push_back(scrollSeq[i]);
        for(int i = l; i < r; i++)tmp_changed.push_back(scrollSeq[i]);
        for(int i = r; i < (int)scrollSeq.size(); i++)tmp_suffix.push_back(scrollSeq[i]);
        sort(tmp_changed.begin(), tmp_changed.end());
        do{
            vector<int> tmp2;
            for(auto x: tmp_prefix)tmp2.push_back(x);
            for(auto x: tmp_changed)tmp2.push_back(x);
            for(auto x: tmp_suffix)tmp2.push_back(x);
            if(chmin(min_cost, calcCost(tmp2))){
                scrollSeq = tmp2;
            }
        }while(next_permutation(tmp_changed.begin(), tmp_changed.end()));
    }
    void dfs(int cur, int pre, const vector<vector<int>> &G, vector<int>& res){
        res.push_back(cur);
        for(auto nxt: G[cur]){
            if(nxt == pre)continue;
            dfs(nxt, cur, G, res);
        }
    }
    // 最小全域木のアルゴリズム、クラスカル法（直線になるように調整）（ここもっといい方法あると思う）
    vector<int> kuraskal(){
        vector<vector<int>> tree(scrollN);
        vector<pair<float, pair<int, int>>> scrollEdges;
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
        vector<int> res;
        dfs(scrollN-1, -1, tree, res);
        return res;
    }
    void chokudaiSearch(vector<int> &scrollSeq, const float TIME_LIMIT){
        // 定数
        MyTimer timer;
        timer.reset();
        //　初期はクラスカルでやる
        if(aMyAnswer.CHOKUDAI_INITIATION == MyAnswer::CHOKUDAI_INITIATION_KUR){
            auto ini_seq = kuraskal();
            ScrollTour ini_tour;
            // ターン毎にpqに突っ込んでいく
            rep(t,scrollN) {
                ini_tour.add_scroll(*this, ini_seq[t]);
                addVps(t, ini_tour);
            }
        }
        else if(aMyAnswer.CHOKUDAI_INITIATION == MyAnswer::CHOKUDAI_INITIATION_NULL){
            vector<int> ini_seq;
            ini_seq.push_back(scrollN-1);
            ScrollTour ini_tour(ini_seq);
            addVps(0, ini_tour);
        }
        else{
            DUMPOUT << "DAMEDESU" << endl;
        }
//            int itr = 0;
        while(true){
//                if(itr++%100 == 0) {
//                        dump(itr);
//                        dbg(vpqSizes);
//                        dmpMinimumState();
//                        dump(isVisited.size());
//                        dump(isVisited);
//                }
            if(timerCheck(timer.get(), TIME_LIMIT)) break;
            bool ugoki = false;
            for(int t = 0; t < scrollN - 1; t++) {
                if (timerCheck(timer.get(), TIME_LIMIT)) break;
                rep(_, MyAnswer::CHOKUDAI_WIDTH) {
                    if(timerCheck(timer.get(), TIME_LIMIT))break;
                    if (vpq[t].empty())break;
                    ScrollTour past = popVps(t);
                    for (int l = 0; l < scrollN; l++) {
                        if (not past.used[l]) {
                            ScrollTour nxt = past;
                            if(visitedCheck(nxt, l))continue;
                            nxt.add_scroll(*this, l);
                            if(addVps(t + 1, nxt)) {
                                ugoki = true;
                            }
                        }
                    }
                }
            }
            if(not ugoki)break;
        }
        ScrollTour res = vpq[scrollN-1].top();
//            dump(ini_seq, ini_tour.cost);
//            dump(res.seq, res.cost);
//            dump("chokudai", timer.get());
//            dbg(ini_tour.cost, res.cost - ini_tour.cost);
        scrollSeq = res.seq;
    }
    bool visitedCheck(const ScrollTour& pastTour, int nxtl){
        if(not MyAnswer::VISITED_CHECK)return false;
        int pastSize = pastTour.seq.size();
        auto nxtSeq = pastTour.seq;
        nxtSeq.emplace_back(nxtl);
        if(isVisited.count(nxtSeq) && isVisited[nxtSeq] > aCellStage.fact[scrollN - pastSize])return true;
        return false;
    }
    bool timerCheck(float nowTime, const float TIME_LIMIT){
        if(vpq.back().empty())return false;
        return nowTime >= TIME_LIMIT;
    }
    bool addVps(int idx, const ScrollTour& tour){
        if(tour.cost > vpqLastMinCost + 50)return false;
        vpq[idx].push(tour);
        vpqSizes[idx]++;
        if(idx == scrollN - 1) {
            chmin(vpqLastMinCost, tour.cost);
            if(tour.cost < vpqLastMinCost + 50){
                betterScrollTours.push_back(tour);
            }
        }
        return true;
    }
    ScrollTour popVps(int idx){
        // vpq[idx]には一つ以上要素がある
        auto res = vpq[idx].top();
        vpq[idx].pop();
        vpqSizes[idx]--;
        return res;
    }
    void dmpMinimumState(){
        rep(i,scrollN){
            DUMPOUT << vpq[i].top().cost << " ";
        }
        DUMPOUT << endl;
    }
};


class TSPSolver : public BluteKurCellSolver {
public:
    struct ScrollTSP{
        int cost;
        vector<int> seq;
        vector<vector<int>> edges; // edges[i][k] = j := iの(k ? 次: 前)がj
        int scrollN;
        // seqが先
        ScrollTSP(vector<int> &seq_, TSPSolver &Solver): seq(seq_){
            scrollN = seq.size();
            auto tmpPathsDeque = Solver.pathsDeque;
            cost = Solver.calcCostFromScrollSeq(seq, tmpPathsDeque);
            edges = seq2Edges(seq);
        }
        // edgesが先
        ScrollTSP(vector<vector<int>> &edges_, TSPSolver &Solver): edges(edges_){
            auto tmpPathsDeque = Solver.pathsDeque;
            seq = Edges2Seq(edges_);
            cost = Solver.calcCostFromScrollSeq(seq, tmpPathsDeque);
        }
        void clearEdges(vector<vector<int>> &tmpEdges){
            tmpEdges.assign(scrollN, vector<int>(2, -1));
        }
        vector<vector<int>> seq2Edges(const vector<int> &tmpSeq){
            vector<vector<int>> tmpEdges;
            clearEdges(tmpEdges);
            int sz = tmpSeq.size();
            rep(i,sz-1){
                tmpEdges[tmpSeq[i]][1] = tmpSeq[i+1];
                tmpEdges[tmpSeq[i+1]][0] = tmpSeq[i];
            }
            return tmpEdges;
        }
        vector<int> Edges2Seq(const vector<vector<int>> &tmpEdges){
            vector<int> tmpSeq;
            int now = scrollN-1;
            tmpSeq.emplace_back(now);
            while(now != -1){
                now = tmpEdges[now][1];
                tmpSeq.emplace_back(now);
            }
            return tmpSeq;
        }
        ScrollTSP swapEdges_2opt(TSPSolver &Solver){
            int p = XorShift() % (scrollN-1) + 1;
            int q = XorShift() % (scrollN-1) + 1;
            vector<int> tmpSeq = seq;
            if(p > q)swap(p, q);
            reverse(tmpSeq.begin() + p, tmpSeq.begin() + q);
            auto res = ScrollTSP(tmpSeq, Solver);
            return res;
        }
        bool operator<(const ScrollTSP& b) const{
            return (*this).cost > b.cost;
        }
    };
    TSPSolver(): BluteKurCellSolver(){}
    explicit TSPSolver(const Stage& aStage): BluteKurCellSolver(aStage){}
    void bluteForce(int l, int r, vector<int>& scrollseq)override{
        scrollseq.resize(scrollN);
        scrollseq[0] = scrollN - 1;
        rep(i,scrollN-1)scrollseq[i+1] = i;
        chmin(r, (int)scrollseq.size());
        int min_cost = 1e5;
        vector<int> tmp_changed, res;
        vector<int> tmp_prefix, tmp_suffix;
        for(int i = 0; i < l; i++)tmp_prefix.push_back(scrollseq[i]);
        for(int i = l; i < r; i++)tmp_changed.push_back(scrollseq[i]);
        for(int i = r; i < (int)scrollseq.size(); i++)tmp_suffix.push_back(scrollseq[i]);
        sort(tmp_changed.begin(), tmp_changed.end());
        do{
            vector<int> tmp2;
            for(auto x: tmp_prefix)tmp2.push_back(x);
            for(auto x: tmp_changed)tmp2.push_back(x);
            for(auto x: tmp_suffix)tmp2.push_back(x);
            if(chmin(min_cost, ScrollTSP(tmp2, *this).cost)){
                scrollseq = tmp2;
            }
        }while(next_permutation(tmp_changed.begin(), tmp_changed.end()));
    }
    void buildScrollSeqEazy(vector<int> & ScrollSeq){
        chokudaiSearchEasy(ScrollSeq);
    }
    void chokudaiSearchEasy(vector<int>& ScrollSeq){
        chokudaiSearch(ScrollSeq, 0);
    }
    vector<Vector2> solve() override{
        buildDistanceMatrix(); // そのままでOK
        // これらの変数は、scrollSeqに依存して変化
        vector<int> BestScrollSeq;
        vector<deque<Vector2>> BestPathsDeque = pathsDeque;
        if(scrollN < 9){
            bluteForce(1, scrollN, BestScrollSeq);
        }
        else{
            buildScrollSeqEazy(BestScrollSeq); // 0秒のchokudai search
            // ここでTSPにする
            solveTSP(BestScrollSeq);
            //
        }
        setScrollPosAfterBuildScrollSeq(BestScrollSeq, BestPathsDeque);
        return moveByScrollSeq(BestScrollSeq, BestPathsDeque);
    }
    void solveTSP(vector<int> &iniScrollSeq){
        ScrollTSP iniTSP(iniScrollSeq, *this);
        dump(iniTSP.cost);
        dump(iniTSP.seq);
        dump(iniTSP.edges);
        priority_queue<ScrollTSP> pq;
        pq.push(iniTSP);
        MyTimer time;
        time.reset();
        int itr = 0;
        while(true) {
            itr++;
            if(itr%100 == 0){
                dump(itr);
            }
            if (timerCheck(time.get()))break;
            auto tmp = iniTSP.swapEdges_2opt(*this);
            if(iniTSP.cost > tmp.cost) {
                swap(iniTSP, tmp);
                pq.push(iniTSP);
                dump(iniTSP.cost);
            }
        }
        vector<int> BestScrollSeq = pq.top().seq;
        swap(iniScrollSeq, BestScrollSeq);
    }
    bool timerCheck(float time){
        return BluteKurCellSolver::timerCheck(time, MyAnswer::TSP_TIME_LIMIT);
    }
};

//-----------------------------------------------------------------------------

/// コンストラクタ
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます
Answer::Answer()
{
    aCellStage.Initiation();
//    assert(n_Splits % 2 == 1);
}

//------------------------------------------------------------------------------
/// デストラクタ
/// @detail 最後のステージ終了後に実行したい処理があればここに書きます
Answer::~Answer()
{
}

//  ~Solveでは必ずMyAnswer::PositionSeqか、 MyAnswer::scrollSeqを定義しなければならない
// 細かく指定したいときはPositionSeq, randomの場合はscrollSeq
void RandomSolve(const Stage & aStage){
    RandomSolver Solver(aStage);
    aMyAnswer.PositionSeq = Solver.solve();
}
void BluteKurSolve(const Stage &aStage){
    BluteKurSolver Solver(aStage);
    aMyAnswer.PositionSeq = Solver.solve();
}
void BluteKurCellSolve(const Stage& aStage){
    BluteKurCellSolver Solver(aStage);
    aMyAnswer.PositionSeq = Solver.solve();
}
void TSPSolve(const Stage& aStage){
    TSPSolver Solver(aStage);
    aMyAnswer.PositionSeq = Solver.solve();
}
void Solve(const Stage& aStage) {
    if (aMyAnswer.SolverSelection == MyAnswer::Random) {
        RandomSolve(aStage);
    } else if (aMyAnswer.SolverSelection == MyAnswer::BluteKur) {
        BluteKurSolve(aStage);
    } else if(aMyAnswer.SolverSelection == MyAnswer::BluteKurCell){
        BluteKurCellSolve(aStage);
    } else if(aMyAnswer.SolverSelection == MyAnswer::TSPSolver){
        TSPSolve(aStage);
    }
//    else{
//        HPC_ASSERT("適切なSolverを選択して下さい");
//    }
}
//------------------------------------------------------------------------------
/// 各ステージ開始時に呼び出される処理
/// @detail 各ステージに対する初期化処理が必要ならここに書きます
/// @param aStage 現在のステージ
void Answer::initialize(const Stage& aStage)
{
    dump(aMyAnswer.StageNum);
    aMyAnswer.clear();
    MyTimer t;
    t.reset();
    Solve(aStage);
    dbg(t.get());
}

//------------------------------------------------------------------------------

/// 毎フレーム呼び出される処理
/// @detail 移動先を決定して返します
/// @param aStage 現在のステージ
/// @return 移動の目標座標
Vector2 Answer::getTargetPos(const Stage& aStage){
    return aMyAnswer.PositionSeq[aMyAnswer.positionSeqIdx++];
}
//------------------------------------------------------------------------------
/// 各ステージ終了時に呼び出される処理
/// @detail 各ステージに対する終了処理が必要ならここに書きます
/// @param aStage 現在のステージ
void Answer::finalize(const Stage& aStage){
    dump(aStage.turn());
}
} // namespace

///
// EOF