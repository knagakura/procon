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
#include <set>
#include <climits>
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
constexpr int INF = 100000;
const float PI = acos(-1);
//--------------------------------my libraries----------------------------------------------
class MyAnswer{
public:
    vector<Vector2> PositionSeq;
    int StageNum = 0;
    int positionSeqIdx{};
    constexpr static const float RANDOM_LIMIT = 0.060;
    constexpr static const float GREEDY_TSP_LIMIT = 0.00;
    static const int n_Splits = 5; // 座標を何倍に拡大してみるか, 中心を定義したいので奇数
    static const int Hn = H * n_Splits;
    static const int Wn = W * n_Splits;
    Stage bStage;
    explicit MyAnswer(int t){
        clear();
    }
    void clear(){
        StageNum++;
        PositionSeq.clear();
        positionSeqIdx = 0;
    }
    void setStage(const Stage &aStage){
        bStage = aStage;
    }
};
#define n_Splits MyAnswer::n_Splits
#define Hn MyAnswer::Hn
#define Wn MyAnswer::Wn
#define bStage aMyAnswer.bStage

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
    pair<int, int> cellIdx2PosIdxs(int cellIdx){
        return make_pair(cellIdx / Wn, cellIdx % Wn);
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
MyAnswer aMyAnswer(1);
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
bool isSame(const Vector2 &a, const Vector2 &b){
    return (int)a.x == (int)b.x && (int)a.y == (int)b.y;
}
float dist(float x, float y){
    return sqrt(x*x+y*y);
}
float dist(const Vector2& a,const Vector2& b){
    return dist(abs(a.x-b.x), abs(a.y-b.y));
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
float terrain_magni(const Vector2& pos){
    return terrain_magni(bStage.terrain(pos));
}
float getJumpDist(const Rabbit& rabbit){
    return rabbit.power() * terrain_magni(bStage.terrain(rabbit.pos()));
}
float kaku(const Vector2 &a, const Vector2 &b, const Vector2 &c){
    float ax = a.x - b.x;
    float ay = a.y - b.y;
    float cx = c.x - b.x;
    float cy = c.y - b.y;
    float alpha = atan2(ax, ay);
    float beta = atan2(cx, cy);
    float res = abs(alpha - beta);
    res = abs(res - PI);
    res = abs(res);
    while(res > PI){
        res -= PI;
    }
    // res < PI
    if(PI - res < res)res = PI - res;
    return res;
}
double Prob(void){
    double ret = (double)XorShift() / UINT_MAX;
    return ret;
}
int dp[1<<21][21];
int prevdp[1<<21][21];
int memoCost[M+5][M+5][M+5];
bool existScroll[H][W]{};
struct hoge{
    int scrollN;
    vector<int> seq;
    vector<deque<Vector2>> pathsDeque;
    vector<int> costSeq;
    vector<Vector2> scrollPosSeq;
    vector<Vector2> tourPosSeq;
    float distAll;
    int costAll;
    hoge(){}
    hoge(vector<int> &seq_,
         vector<deque<Vector2>>&pathsDeque_,
         vector<int> &costseq_,
         vector<Vector2> posSeq_,
         float dist_,
         int costAll_): scrollN((int)seq_.size()), seq(seq_), pathsDeque(pathsDeque_), costSeq(costseq_), scrollPosSeq(posSeq_), distAll(dist_), costAll(costAll_){
    }
    hoge(vector<int>& seq_, vector<deque<Vector2>> &pathsDeque_): scrollN((int)seq_.size()), seq(seq_), pathsDeque(pathsDeque_){
        costSeq.assign(scrollN-1, 0);
        scrollPosSeq.resize(scrollN-1);
        distAll = 0;
        costAll = 0;
    }
    void setScrollPosAfterBuildScrollSeq(){
        for(int i = 0; i < scrollN - 2; i++){
            int l = seq[i];
            int mid = seq[i+1];
            int r = seq[i+2];
            int pathLIdx = l * scrollN + mid;
            int pathRIdx = mid * scrollN + r;
            // rの位置を設定する
            Vector2 midScrollPos = bStage.scrolls()[mid].pos();
            while(isSame(pathsDeque[pathLIdx].back(), midScrollPos)){
                pathsDeque[pathLIdx].pop_back();
            }
            while(isSame(pathsDeque[pathRIdx].front(), midScrollPos)){
                pathsDeque[pathRIdx].pop_front();
            }
            pair<int, int> midScrollCellCenterIdx = aCellStage.getCellCenterIdx(midScrollPos);
            int midCenterX = midScrollCellCenterIdx.first;
            int midCenterY = midScrollCellCenterIdx.second;
            int scrollX = midCenterX;
            int scrollY = midCenterY;
            Vector2 NewScrollPos = aCellStage.getCellPos(scrollX, scrollY);
            Vector2 LPos = pathsDeque[pathLIdx].back();
            Vector2 RPos = pathsDeque[pathRIdx].front();

            float sumDist = dist(LPos, midScrollPos) + dist(RPos, midScrollPos);
            for(int dxx = -n_Splits / 2; dxx <= n_Splits/2; dxx++) {
                for (int dyy = -n_Splits / 2; dyy <= n_Splits / 2; dyy++) {
                    int nx = midCenterX + dxx;
                    int ny = midCenterY + dyy;
                    if (aCellStage.isOutOfBounds(nx, ny))continue;
                    Vector2 tmpScrollPos = aCellStage.getCellPos(nx, ny);
                    float sumDistTmp = dist(LPos, tmpScrollPos) + dist(RPos, tmpScrollPos) * 1.1;
                    if (chmin(sumDist, sumDistTmp)) {
                        NewScrollPos = aCellStage.getCellPos(nx, ny);
                    }
                }
            }
            pathsDeque[pathLIdx].push_back(NewScrollPos);
            pathsDeque[pathRIdx].push_front(NewScrollPos);
        }
    }
    bool shouldGaman(const Stage &tmpStage, const int path_idx, const int cellIdx, const vector<deque<Vector2>> &pathsDequeNow){
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
    vector<Vector2> moveByScrollSeq(){
        Stage pseudoStage = bStage; // この後も初期状態を使う可能性があるので完全には破壊したくない
        int scrollSeqIdx = 0;
        int cellIdx = 0;
        int cost = 0;
        costAll = 0;
        tourPosSeq.clear();
        tourPosSeq.emplace_back(pseudoStage.rabbit().pos());
        while(not pseudoStage.isEnd()) {
            auto player = pseudoStage.rabbit();
            Vector2 now_pos = player.pos();
            float length = getJumpDist(player);
            while (scrollSeqIdx + 1 < (int) seq.size() &&
                   pseudoStage.scrolls()[seq[scrollSeqIdx + 1]].isGotten()) { // 2
                costSeq[scrollSeqIdx] = cost;
                scrollPosSeq[scrollSeqIdx] = now_pos;
                scrollSeqIdx++;
                cellIdx = 0;
                cost = 0;
            }
            int scroll_l = seq[scrollSeqIdx];
            int scroll_r = seq[scrollSeqIdx + 1];
            int path_idx = scroll_l * scrollN + scroll_r;
            //
            int iniCellIdx = cellIdx;
            bool isSecondMove = false;
            bool gamanned = false;
            while (cellIdx + 1 < (int) pathsDeque[path_idx].size() &&
                   length > dist(now_pos, pathsDeque[path_idx][cellIdx])) {
                if (isSecondMove && shouldGaman(pseudoStage, path_idx, cellIdx, pathsDeque)) {
                    gamanned = true;
                    break;
                }
                cellIdx++;
                isSecondMove = true;
            }
            if (gamanned && length > 2) {
                // 最大限伸ばしたときに何が起きるかを見てから手前で止まるか考えるべき
                int nowTer = int(pseudoStage.terrain(now_pos));
                int tmpCellIdx = iniCellIdx;
                int okCellIdx = -1; // 今より悪くならない場所の最も奥の座標を保存する
                while (tmpCellIdx + 1 < (int) pathsDeque[path_idx].size() &&
                       length > dist(now_pos, pathsDeque[path_idx][tmpCellIdx])) {
                    tmpCellIdx++;
                    auto tmpNxtTargetPos = pathsDeque[path_idx][tmpCellIdx];
                    auto tmpNxtPos = pseudoStage.getNextPos(player.pos(), player.power(), tmpNxtTargetPos);
                    int tmpNxtTer = (int) pseudoStage.terrain(tmpNxtPos);
                    if (nowTer >= tmpNxtTer) {
                        okCellIdx = tmpCellIdx;
                    }
                }
                if (okCellIdx != -1) {
                    cellIdx = okCellIdx;
                }
            }
            auto nextTargetPos = pathsDeque[path_idx][cellIdx];
            pseudoStage.update(nextTargetPos);
            tourPosSeq.emplace_back(pseudoStage.rabbit().pos());
            cost++;
            costAll++;
            distAll += dist(tourPosSeq.back(), now_pos);
        }
        return tourPosSeq;
    }

    bool randomYamanobori(){
        int rand = XorShift() % (scrollN - 1);
        int pathsIdx = seq[rand] * scrollN + seq[rand+1];
        int cellIdx = XorShift() % ((int)pathsDeque[pathsIdx].size() - 1) + 1;
        float theta = kaku(pathsDeque[pathsIdx][cellIdx-1], pathsDeque[pathsIdx][cellIdx], pathsDeque[pathsIdx][cellIdx+1]);
        if((theta/PI) * 180 < 10)return false;
        float randX = Prob()/5;
        float randY = Prob()/5;
        auto tmpPathsDeque = pathsDeque;
        tmpPathsDeque[pathsIdx][cellIdx].x += randX;
        tmpPathsDeque[pathsIdx][cellIdx].y += randY;
//        float nxtTheta = kaku(tmpPathsDeque[pathsIdx][cellIdx-1], tmpPathsDeque[pathsIdx][cellIdx], tmpPathsDeque[pathsIdx][cellIdx+1]);
        if(existScroll[(int)pathsDeque[pathsIdx][cellIdx].x][(int)pathsDeque[pathsIdx][cellIdx].y]) {
            if (not isSame(tmpPathsDeque[pathsIdx][cellIdx], pathsDeque[pathsIdx][cellIdx])) {
                return false;
            }
        }
        else{
            if(int(bStage.terrain(pathsDeque[pathsIdx][cellIdx])) < int(bStage.terrain(tmpPathsDeque[pathsIdx][cellIdx]))){
                return false;
            }
        }
        hoge tmpVals(seq, tmpPathsDeque);
        tmpVals.moveByScrollSeq();
        if(costAll > tmpVals.costAll || (costAll == tmpVals.costAll && distAll > tmpVals.distAll)){
            if(costAll > tmpVals.costAll){
//                    dump((nxtTheta/PI)*180);
//                    dbg('\t', itr, (theta/PI) * 180, tmpCost, tmpDist);
//                    float preDo = (theta / PI) * 180;
//                    float nxtDo = (nxtTheta / PI) * 180;
//                    dump(preDo, nxtDo);
            }
            swap(*this, tmpVals);
            return true;
        }
        return false;
    }
};
class SolverBase{
public:
    int scrollN;
    Vector2 iniPos;
    vector<int> PositionSeq;
    float distScroll[M + 5][M + 5]{};

    vector<deque<Vector2>> pathsDeque;
    Vector2 ini_pos;
    vector<Vector2> positions;

    SolverBase(){};
    SolverBase(const Stage &aStage){
        stageInitiation(aStage);
    }
    void stageInitiation(const Stage& aStage){
        bStage = aStage;
        scrollN = bStage.scrolls().count() + 1;
        iniPos = bStage.rabbit().pos();
        ini_pos = aStage.rabbit().pos();
        pathsDeque.resize(scrollN * scrollN);
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                existScroll[i][j] = false;
            }
        }
        // 巻物
        rep(i,scrollN-1){
            positions.push_back(bStage.scrolls()[i].pos());
            existScroll[(int)positions[i].x][(int)positions[i].y] = true;
        }
        // 最初のポジション
        positions.push_back(ini_pos);
    }
    int idxEncodeCell(int a, int b){
        return a * Wn + b;
    }
    bool shouldGaman(const Stage &tmpStage, const int path_idx, const int cellIdx, const vector<deque<Vector2>> &pathsDequeNow){
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
        const int Dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        const int Dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
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
        rep(i,scrollN){
            Vector2 scroll_from = positions[i];
            pair<int, int> startCellIdx = aCellStage.getCellCenterIdx(scroll_from);
            int start_idx = idxEncodeCell(startCellIdx.first, startCellIdx.second);
            G.solve(start_idx);
            rep(j,scrollN-1){
                if(i == j)continue;
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
    void solveBitDP(vector<vector<int>> &betterScrollSeqs){
        MyTimer t;
        t.reset();
        int n = scrollN-1;
        int start = scrollN-1;
        int bit = (1 << n) - 1;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = INF;
                prevdp[i][j] = -1;
            }
        }
        rep(i,scrollN-1){
            dp[(1<<i)][i] = memoCost[0][start][i];
            prevdp[(1<<i)][i] = start;
        }
        // iが状態、jがスタートするところ、kが次のマス
        for (int i = 1; i < (1 << n); ++i) {
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == INF) continue;
                for (int k = 0; k < n; ++k) {
                    if (!((i >> k) & 1)) {
                        int nxtCost = dp[i][j] + memoCost[cnt][j][k];
                        if (dp[i | (1 << k)][k] >  nxtCost) {
                            dp[i | (1 << k)][k] = dp[i][j] + memoCost[cnt][j][k];
                            prevdp[i | (1 << k)][k] = j;
                        }
                    }
                }
            }
        }
        for(int lastScroll = 0; lastScroll < scrollN - 1; lastScroll++) {
            int bitnow = bit;
            int now = lastScroll;
            if(dp[bitnow][now] == INF)continue;
            vector<int> seq;
            seq.emplace_back(now);
            while(now != start) {
                int pre = prevdp[bitnow][now];
                bitnow ^= (1 << now);
                now = pre;
                seq.push_back(now);
            }
            reverse(seq.begin(), seq.end());
//            int calcCost = 0;
//            rep(i,scrollN-1){
//                calcCost += memoCost[i][seq[i]][seq[i+1]];
//            }
            betterScrollSeqs.emplace_back(seq);
//            dump(seq, dp[bit][lastScroll], calcCost);;
//            if(chmin(minCost, dp[bit][lastScroll])){
//                swap(scrollSeq, seq);
//            }
        }
    }
    vector<Vector2> solve() /*override*/{
        dijkstra();
        buildMemoCost();
        hoge minVals;
        int minCost = INF;
        vector<vector<int>> betterScrollSeqs;
        solveBitDP(betterScrollSeqs);
        for(auto &v: betterScrollSeqs) {
            auto tmpDeque = pathsDeque;
            hoge tmpVals(v, tmpDeque);
            tmpVals.setScrollPosAfterBuildScrollSeq();
            tmpVals.moveByScrollSeq();
//            int dpCost = dp[(1 << (scrollN-1)) - 1][v.back()];
//            dump(v, cost, dpCost);
            if(chmin(minCost, tmpVals.costAll)){
                swap(minVals, tmpVals);
            }
        }
        MyTimer t;
        /**
         * GREEDY 2OP
         */
         t.reset();
         while(true){
             bool changed = false;
             for(int i = 1; i < scrollN; i++){
                 if(t.get() > MyAnswer::GREEDY_TSP_LIMIT)break;
                 for(int j = 1; j < scrollN; j++){
                     if(t.get() > MyAnswer::GREEDY_TSP_LIMIT)break;
                     if(tspSwap2Opt(minVals, i, j)){
                         changed = true;
                     }
                 }
             }
             if(not changed)break;
         }
        /*
         * 山登りをする
         */
        // RANDOM YAMANOBORI
        t.reset();
        int itr = 0;
        while(true) {
            if(itr % 10 == 0){
                if(t.get() > MyAnswer::RANDOM_LIMIT)break;
//                dump(itr);
            }
            if(minVals.randomYamanobori()){
                dump(itr);
            }
            itr++;
        }
        dump(itr);
        return minVals.tourPosSeq;
//        return moveByScrollSeq(BestScrollSeq, BestPathsDeque, d);
    }


    int calcCostForMemo(int cnt, int from, int to){
        if(to == scrollN-1)return -1;
        if(from == to)return -1;
        if(cnt == 0 && from != scrollN-1)return -1;
        const int pathsDequeIdx = from * scrollN + to;
        Vector2 nowIniPos = pathsDeque[pathsDequeIdx].front();
        Rabbit player;
        player.setPos(nowIniPos);
        player.setPower(aCellStage.beki[cnt]);
        Scroll toScroll = bStage.scrolls()[to];
        int cellIdx = 0; // cellIdxとは異なる

        int res = 0;
        while(not isSame(player.pos(), toScroll.pos())){
            auto now_pos = player.pos();
            float length = getLength(player.pos(), player.power());
            int iniCellIdx = cellIdx;
            bool isSecondMove = false;
            bool gamanned = false;
            while(cellIdx + 1 < (int)pathsDeque[pathsDequeIdx].size() && length > dist(player.pos(), pathsDeque[pathsDequeIdx][cellIdx])){
                if(isSecondMove && shouldGaman(player, pathsDequeIdx, cellIdx, pathsDeque)){
                    gamanned = true;
                    break;
                }
                cellIdx++;
                isSecondMove = true;
            }
            if(gamanned && length > 2) {
                // 最大限伸ばしたときに何が起きるかを見てから手前で止まるか考えるべき
                int nowTer = int(bStage.terrain(now_pos));
                int tmpCellIdx = iniCellIdx;
                int okCellIdx = -1; // 今より悪くならない場所の最も奥の座標を保存する
                while (tmpCellIdx + 1 < (int) pathsDeque[pathsDequeIdx].size() &&
                       length > dist(now_pos, pathsDeque[pathsDequeIdx][tmpCellIdx])) {
                    tmpCellIdx++;
                    auto tmpNxtTargetPos = pathsDeque[pathsDequeIdx][tmpCellIdx];
                    auto tmpNxtPos = bStage.getNextPos(player.pos(), player.power(), tmpNxtTargetPos);
                    int tmpNxtTer = (int) bStage.terrain(tmpNxtPos);
                    if (nowTer >= tmpNxtTer) {
                        okCellIdx = tmpCellIdx;
                    }
                }
                if (okCellIdx != -1) {
                    cellIdx = okCellIdx;
                }
            }
            auto nextTargetPos = pathsDeque[pathsDequeIdx][cellIdx];
            myRabbitUpdate(player, nextTargetPos); // playerの場所更新する
            res++;
        }
        return res;
    }
    void myRabbitUpdate(Rabbit &rab, const Vector2 &aTargetPos){
        auto nxtPos = bStage.getNextPos(rab.pos(), rab.power(), aTargetPos);
        rab.setPos(nxtPos);
    }
    bool shouldGaman(const Rabbit rab, const int path_idx, const int cellIdxx, const vector<deque<Vector2>> &pathsDequeNow){
        int nowRabiTer = (int)bStage.terrain(rab.pos());
        auto nowTargetCellPos = pathsDequeNow[path_idx][cellIdxx];
        auto nxtTargetCellPos = pathsDequeNow[path_idx][cellIdxx+1];
        auto nowCellPos = bStage.getNextPos(rab.pos(), rab.power(), nowTargetCellPos);
        auto nxtCellPos = bStage.getNextPos(rab.pos(), rab.power(), nxtTargetCellPos);
//        int nowCellTer = (int) tmpStage.terrain(pathsDequeNow[path_idx][cellIdx]);
//        int nxtCellTer = (int) tmpStage.terrain(pathsDequeNow[path_idx][cellIdx + 1]);
        int nowCellTer = (int) bStage.terrain(nowCellPos);
        int nxtCellTer = (int) bStage.terrain(nxtCellPos);
        return nowRabiTer == nowCellTer && nxtCellTer - nowCellTer > 1;
    }
    float getLength(const Vector2 &pos, float rabPower){
        return terrain_magni(pos) * rabPower;
    }
    void buildMemoCost(){
        rep(i,scrollN-1)rep(l,scrollN)rep(r,scrollN){
            memoCost[i][l][r] = calcCostForMemo(i, l, r);
        }
    }
    int nV = Hn * Wn;
    float inf = 1e5;
    vector<float> costs;
    vector<int> prev;
    void dijkstra(){
        // startを決める
        rep(i,scrollN) {
            dijkstraSolve(i); // iから解く
            rep(j,scrollN-1){
                if(i == j)continue;
                Vector2 scroll_to = positions[j];
                pair<int, int> toCellIdx = aCellStage.getCellCenterIdx(scroll_to);
                int to_idx = idxEncodeCell(toCellIdx.first, toCellIdx.second);
                distScroll[i][j] = costs[to_idx];
                pathsDeque[i * scrollN + j] = getPathsDeque(to_idx);
//                distScroll[i][j] = G.cost[to_idx];
//                paths[i*scrollN+j] = G.getCellPath(to_idx);
//                pathsDeque[i*scrollN+j] = G.getCellPathDeque(to_idx);
            }
        }
    }
    void dijkstraSolve(int startScrollIdx){
        const int Dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        const int Dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        priority_queue<pair<float, int>, vector<pair<float, int>> , greater<pair<float, int>>> pq;
        costs.assign(nV, inf);
        prev.assign(nV, -1);
        Vector2 scroll_from = positions[startScrollIdx];
        pair<int, int> startCellIdx = aCellStage.getCellCenterIdx(scroll_from);
        int start_idx = idxEncodeCell(startCellIdx.first, startCellIdx.second);
        costs[start_idx] = 0;
        pq.push({0, start_idx});
        while(not pq.empty()){
            float preCost = pq.top().first;
            int fromCellIdx = pq.top().second;
            pq.pop();
            pair<int, int> fromP = aCellStage.cellIdx2PosIdxs(fromCellIdx);
            int fromX = fromP.first;
            int fromY = fromP.second;
            Terrain from_tr = bStage.terrain(aCellStage.getCellPos(fromX, fromY));
            if(costs[fromCellIdx] < preCost)continue;
            // 別の頂点へ遷移
            rep(k,8){
                int nx = fromX + dx[k];
                int ny = fromY + dy[k];
                if(aCellStage.isOutOfBounds(nx, ny))continue;
//                        Vector2 to = aCellStage.getCellPos(i, j);
                // Terrain to_tr = aStage.terrain(to);
                int toCellIdx = idxEncodeCell(nx, ny);
                float cost = terrain_cost(from_tr) * dist(dx[k], dy[k])/*+ terrain_cost(to_tr)*/;
                if(preCost + cost < costs[toCellIdx]){
                    costs[toCellIdx] = preCost + cost;
                    prev[toCellIdx] = fromCellIdx;
                    pq.push({costs[toCellIdx], toCellIdx});
                }
//                G.make_edge(from_idx, to_idx, cost);
            }
            rep(k,8){
                int nx = fromX + Dx[k];
                int ny = fromY + Dy[k];
                if(aCellStage.isOutOfBounds(nx, ny))continue;
//                        Vector2 to = aCellStage.getCellPos(i, j);
                // Terrain to_tr = aStage.terrain(to);
                int toCellIdx = idxEncodeCell(nx, ny);
                float cost = terrain_cost(from_tr) * dist(Dx[k], Dy[k])/*+ terrain_cost(to_tr)*/;
                if(preCost + cost < costs[toCellIdx]){
                    costs[toCellIdx] = preCost + cost;
                    prev[toCellIdx] = fromCellIdx;
                    pq.push({costs[toCellIdx], toCellIdx});
                }
//                G.make_edge(from_idx, to_idx, cost);
            }
        }
    }
    deque<Vector2> getPathsDeque(int t){
        deque<Vector2> res;
        for(; t != -1; t = prev[t]){
            res.push_front(aCellStage.cellIdx2Pos(t));
        }
        return res;
    }
    // tsp関連
    bool tspSwap2Opt(hoge& vals){
        int p = XorShift() % (scrollN-1) +1;
        int q = XorShift() % (scrollN-1) +1;
        if(p > q)swap(p,q);
        return tspSwap2Opt(vals, p, q);
    }
    bool tspSwap2Opt(hoge &vals, int p, int q){
        auto tmpseq = vals.seq;
        auto tmppd = vals.pathsDeque;
        reverse(tmpseq.begin() + p, tmpseq.begin() + q);
        hoge tmpVals(tmpseq, vals.pathsDeque);
        tmpVals.setScrollPosAfterBuildScrollSeq();
        tmpVals.moveByScrollSeq();

        if(vals.costAll > tmpVals.costAll){
            swap(vals, tmpVals);
            return true;
        }
        return false;
    }
    int calcCostForRandom(){
        return 0;
    }

};
//-----------------------------------------------------------------------------

/// コンストラクタ
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます
Answer::Answer()
{
    aCellStage.Initiation();
}

//------------------------------------------------------------------------------
/// デストラクタ
/// @detail 最後のステージ終了後に実行したい処理があればここに書きます
Answer::~Answer()
{
}
void Solve(const Stage& aStage) {
    SolverBase Solver(aStage);
    aMyAnswer.PositionSeq = Solver.solve();
}
//------------------------------------------------------------------------------
/// 各ステージ開始時に呼び出される処理
/// @detail 各ステージに対する初期化処理が必要ならここに書きます
/// @param aStage 現在のステージ
void Answer::initialize(const Stage& aStage)
{
    dump(aMyAnswer.StageNum);
    aMyAnswer.clear();
    aMyAnswer.setStage(aStage);
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