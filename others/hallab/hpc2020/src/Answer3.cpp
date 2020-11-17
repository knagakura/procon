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
#define rep1(i,N) for(int i=1;i<int(N);++i)
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
constexpr float EPS = 1e-11;
//--------------------------------my libraries----------------------------------------------
class MyAnswer{
public:
    vector<Vector2> PositionSeq;
    int StageNum = 0;
    int positionSeqIdx{};
    static const int n_Splits = 5; // 座標を何倍に拡大してみるか, 中心を定義したいので奇数
    static const int Hn = H * n_Splits;
    static const int Wn = W * n_Splits;
    MyAnswer(){
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
    // 1.1の冪
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
        return {n_Splits * i + n_Splits / 2,
                n_Splits * j + n_Splits / 2};
    }
    Vector2 getCellCenterPos(int i, int j){
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
};


// ------------------------------------------------------------
CellStage aCellStage; // 一番最初に行われる処理。
MyAnswer aMyAnswer;
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
int dp[1<<21][21];
int prevdp[1<<21][21];
int memoCost[M+5][M+5][M+5];

class Solver{
public:
    Stage bStage;
    int scrollN;
    Vector2 iniPos;
    vector<int> PositionSeq;
    float distScroll[M + 5][M + 5]{};
    bool existScroll[H][W]{};
    vector<deque<Vector2>> pathsDeque;
    Vector2 ini_pos;
    vector<Vector2> positions;
    int nV = Hn * Wn;
    float inf = 1e5;
    vector<float> costs;
    vector<int> prev;
    Solver(){};
    Solver(const Stage &aStage){
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
    bool isSame(const Vector2 &a, const Vector2 &b){
        return (int)a.x == (int)b.x && (int)a.y == (int)b.y;
    }
    float dist(float x, float y){
        return sqrt(x*x+y*y);
    }
    float dist(const Vector2& a,const Vector2& b){
        return dist(abs(a.x-b.x), abs(a.y-b.y));
    }
    float terrain_magni(const Vector2& pos){
        return terrain_magni(bStage.terrain(pos));
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
    float getJumpDist(const Stage& aStage, const Rabbit& rabbit){
        return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
    }
    int idxEncodeCell(int a, int b){
        return a * Wn + b;
    }
    bool isExistScroll(const Vector2 & v){
        return existScroll[(int)v.x][(int)v.y];
    }
    float kaku(Vector2 &a, Vector2 &b, Vector2 &c)const{
        float bx = b.x - a.x;
        float by = b.y - a.y;
        float cx = c.x - a.x;
        float cy = c.y - a.y;
        float alpha = atan2(bx, by);
        float beta = atan2(cx, cy);
        float res = beta - alpha;
        float resDo = res / PI * 180;
        return resDo;
    }

    int calcCostFromScrollSeq(const vector<int> &tmpSeq, vector<deque<Vector2>> &tmpPathsDeque, float &dist){
//        setScrollPosAfterBuildScrollSeq(tmpSeq, tmpPathsDeque);
        auto x = moveByScrollSeq(tmpSeq, tmpPathsDeque, dist);
        return x.size();
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
                    float sumDistTmp = dist(LPos, tmpScrollPos) + dist(RPos, tmpScrollPos) * 1.1;
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

    bool shouldGaman(const Stage &tmpStage, const int path_idx, const int cellIdx, const vector<deque<Vector2>> &pathsDequeNow){
        int nowRabiTer = (int) tmpStage.terrain(tmpStage.rabbit().pos());
        auto nowTargetCellPos = pathsDequeNow[path_idx][cellIdx];
        auto nxtTargetCellPos = pathsDequeNow[path_idx][cellIdx+1];
        auto nowCellPos = tmpStage.getNextPos(tmpStage.rabbit().pos(), tmpStage.rabbit().power(), nowTargetCellPos);
        auto nxtCellPos = tmpStage.getNextPos(tmpStage.rabbit().pos(), tmpStage.rabbit().power(), nxtTargetCellPos);
        int nowCellTer = (int) tmpStage.terrain(nowCellPos);
        int nxtCellTer = (int) tmpStage.terrain(nxtCellPos);
        if(isExistScroll(nxtCellPos))return false;
        return nowRabiTer == nowCellTer && nxtCellTer - nowCellTer > 1;
    }
    vector<Vector2> moveByScrollSeq(const vector<int> &scrollSeq, const vector<deque<Vector2>> &pathsDequeNow, float& tourDist){
        tourDist = 0;
        Stage pseudoStage = bStage; // この後も初期状態を使う可能性があるので完全には破壊したくない
        vector<Vector2> res;
        int scrollSeqIdx = 0;
        int cellIdx = 0;
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
            int iniCellIdx = cellIdx;
            bool isSecondMove = false;
            bool gamanned = false;
            while (cellIdx + 1 < (int) pathsDequeNow[path_idx].size() &&
                   length > dist(now_pos, pathsDequeNow[path_idx][cellIdx])) {
                if (isSecondMove && shouldGaman(pseudoStage, path_idx, cellIdx, pathsDequeNow)){
                    gamanned = true;
                    break;
                }
                cellIdx++;
                isSecondMove = true;
            }
            if(gamanned && length > 2) {
                // 最大限伸ばしたときに何が起きるかを見てから手前で止まるか考えるべき
                int nowTer = int(pseudoStage.terrain(now_pos));
                int tmpCellIdx = iniCellIdx;
                int okCellIdx = -1; // 今より悪くならない場所の最も奥の座標を保存する
                while (tmpCellIdx + 1 < (int) pathsDequeNow[path_idx].size() &&
                       length > dist(now_pos, pathsDequeNow[path_idx][tmpCellIdx])) {
                    tmpCellIdx++;
                    auto tmpNxtTargetPos = pathsDequeNow[path_idx][tmpCellIdx];
                    auto tmpNxtPos = pseudoStage.getNextPos(player.pos(), player.power(), tmpNxtTargetPos);
                    int tmpNxtTer = (int) pseudoStage.terrain(tmpNxtPos);
                    if (nowTer >= tmpNxtTer) {
                        okCellIdx = tmpCellIdx;
                    }
                    else if(scrollSeqIdx == scrollN - 2 && isSame(tmpNxtPos, pathsDequeNow[path_idx].back())){
                        okCellIdx = tmpCellIdx;
                    }
                    else{
                        // 仮にそこで我慢したときに移動できる距離と
                        float gamanDist = dist(now_pos, pathsDequeNow[path_idx][cellIdx]) + getLength(pathsDequeNow[path_idx][cellIdx], player.power());
                        // 今少し足を伸ばした先でまた移動する距離を比較する
                        float canDist = dist(now_pos, tmpNxtPos) + getLength(tmpNxtPos, player.power());
                        if(gamanDist < canDist){
                            okCellIdx = tmpCellIdx;
                        }
                    }
                }
                if (okCellIdx != -1) {
                    cellIdx = okCellIdx;
                }
            }
            auto nextTargetPos = pathsDequeNow[path_idx][cellIdx];
            pseudoStage.update(nextTargetPos);
            res.emplace_back(pseudoStage.rabbit().pos());
            tourDist += dist(res.back(), now_pos);
        }
        return res;
    }
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
            betterScrollSeqs.emplace_back(seq);
        }
    }
    vector<Vector2> solve(){
        dijkstra();
        buildMemoCost();
        vector<int> BestScrollSeq;
        vector<deque<Vector2>> BestPathsDeque;
        int minCost = INF;
        float minDist = INF;
        vector<vector<int>> betterScrollSeqs;
        solveBitDP(betterScrollSeqs);
        // betterな状態に対して、まっすぐ行って良いところはまっすぐいくように設定した上で、コストを計算する
        // 最もいいものを採用。
        for(auto &v: betterScrollSeqs) {
            auto tmpDeque = pathsDeque;
            setScrollPosAfterBuildScrollSeq(v, tmpDeque);
            float tmpDist = 0;
            int tmpCost = calcCostFromScrollSeq(v, tmpDeque, tmpDist);
            rep(i,scrollN-1){
                int l = v[i];
                int r = v[i+1];
                int pathIdx = l * scrollN + r;
                if(tmpDeque[pathIdx].size() == 2)continue;
                auto tmptmpDeque = tmpDeque;
                deque<Vector2> tmp;
                tmp.push_front(tmpDeque[pathIdx].front());
                tmp.push_back(tmpDeque[pathIdx].back());
                swap(tmptmpDeque[pathIdx], tmp);
                float tmptmpDist = 0;
                int tmptmpCost = calcCostFromScrollSeq(v, tmptmpDeque, tmptmpDist);
                if(tmpCost > tmptmpCost || (tmpCost == tmptmpCost && tmpDist > tmptmpDist)){
                    chmin(tmpCost, tmptmpCost);
                    swap(tmptmpDeque, tmpDeque);
                    swap(tmpDist, tmptmpDist);
                }
            }
            if(minCost > tmpCost || (minCost == tmpCost && minDist > tmpDist)){
                minCost = tmpCost;
                swap(BestScrollSeq, v);
                swap(BestPathsDeque, tmpDeque);
                swap(minDist, tmpDist);
            }
        }
        /*
         山登りをする
        */

        MyTimer t;
        t.reset();
        int itr = 0;
        float tl = 0.010;
        if(scrollN == 2){
            tl = 0.005;
        }
        if(scrollN >= 11){
            tl = 0.030;
        }
        if(scrollN == 21){
            tl += 0.005;
        }
        // ある区間を直線にしてよくなるかどうか
        while(true){
            int rand = XorShift() % (scrollN-1);
            if(t.get() > tl)break;
            int pathsIdx = BestScrollSeq[rand] * scrollN + BestScrollSeq[rand+1];
            if((int)BestPathsDeque[pathsIdx].size() == 2)continue;
            int LeftCellIdx = XorShift() % ((int)BestPathsDeque[pathsIdx].size() - 1) + 1;
            int RightCellIdx = XorShift() % ((int)BestPathsDeque[pathsIdx].size() - 1) + 1;
            if(abs(LeftCellIdx - RightCellIdx) <= 2)continue;
            if(LeftCellIdx > RightCellIdx){
                swap(LeftCellIdx, RightCellIdx);
            }
            auto tmpDeque = BestPathsDeque;
            deque<Vector2> tmp;
            rep(i, LeftCellIdx){
                tmp.push_back(tmpDeque[pathsIdx][i]);
            }
            for(int i = RightCellIdx; i < (int)tmpDeque[pathsIdx].size(); i++){
                tmp.push_back(tmpDeque[pathsIdx][i]);
            }
            swap(tmp, tmpDeque[pathsIdx]);
            float tmpDist = 0;
            int tmpCost = calcCostFromScrollSeq(BestScrollSeq, tmpDeque, tmpDist);
            if(minCost > tmpCost || (minCost == tmpCost && minDist > tmpDist)){
                dbg('\t', minCost, tmpCost, tmpDist, LeftCellIdx, RightCellIdx);
                minCost = tmpCost;
                minDist = tmpDist;
                swap(tmpDeque, BestPathsDeque);
            }
        }
        t.reset();
        // ある点をランダムに変更してよくなるか
        while(true) {
            if(t.get() > tl)break;
            int rand = XorShift() % (scrollN - 1);
            int pathsIdx = BestScrollSeq[rand] * scrollN + BestScrollSeq[rand+1];
            int cellIdx = XorShift() % ((int)BestPathsDeque[pathsIdx].size() - 1) + 1;
            if(XorShift() % 2 == 0){
                cellIdx = BestPathsDeque[pathsIdx].size() - 1;
            }
            float theta = kaku(BestPathsDeque[pathsIdx][cellIdx-1], BestPathsDeque[pathsIdx][cellIdx], BestPathsDeque[pathsIdx][cellIdx+1]);
            if(theta < 10)continue;
            float randX = Prob()/5;
            float randY = Prob()/5;
            auto tmpPathsDeque = BestPathsDeque;
            tmpPathsDeque[pathsIdx][cellIdx].x += randX;
            tmpPathsDeque[pathsIdx][cellIdx].y += randY;
            if (existScroll[(int) BestPathsDeque[pathsIdx][cellIdx].x][(int) BestPathsDeque[pathsIdx][cellIdx].y]) {
                if (not isSame(tmpPathsDeque[pathsIdx][cellIdx], BestPathsDeque[pathsIdx][cellIdx])) {
                    continue;
                }
            } else {
                if (int(bStage.terrain(BestPathsDeque[pathsIdx][cellIdx])) <
                    int(bStage.terrain(tmpPathsDeque[pathsIdx][cellIdx]))) {
                    continue;
                }
            }
            float tmpDist = 0;
            int tmpCost = calcCostFromScrollSeq(BestScrollSeq, tmpPathsDeque, tmpDist);
            itr++;
            if(minCost > tmpCost || (minCost == tmpCost && minDist > tmpDist)){
                dbg('\t', itr, tmpCost, tmpDist, theta);
                if(minCost > tmpCost){
//                    dump((nxtTheta/PI)*180);
                }
                minCost = tmpCost;
                minDist = tmpDist;
                swap(tmpPathsDeque, BestPathsDeque);
            }
        }
        float d = 0;
        auto v = moveByScrollSeq(BestScrollSeq, BestPathsDeque, d);
        return v;
    }
    double Prob(void){
        double ret = (double)XorShift() / UINT_MAX;
        return ret;
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
            bool isSecondMove = false;
            bool gamanned = false;
            int iniCellIdx = cellIdx;
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
                    else if(cnt == scrollN - 2 && isSame(tmpNxtPos, pathsDeque[pathsDequeIdx].back())){
                        okCellIdx = tmpCellIdx;
                    }
                    else{
                        // 仮にそこで我慢したときに移動できる距離と
                        float gamanDist = dist(now_pos, pathsDeque[pathsDequeIdx][cellIdx]) + getLength(pathsDeque[pathsDequeIdx][cellIdx], player.power());
                        // 今少し足を伸ばした先でまた移動する距離を比較する
                        float canDist = dist(now_pos, tmpNxtPos) + getLength(tmpNxtPos, player.power());
                        if(gamanDist < canDist){
                            okCellIdx = tmpCellIdx;
                        }
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

        if(isExistScroll(nxtCellPos))return false;
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
                int toCellIdx = idxEncodeCell(nx, ny);
                float cost = terrain_cost(from_tr) * dist(dx[k], dy[k])/*+ terrain_cost(to_tr)*/;
                if(preCost + cost < costs[toCellIdx]){
                    costs[toCellIdx] = preCost + cost;
                    prev[toCellIdx] = fromCellIdx;
                    pq.push({costs[toCellIdx], toCellIdx});
                }
            }
            rep(k,8){
                int nx = fromX + Dx[k];
                int ny = fromY + Dy[k];
                if(aCellStage.isOutOfBounds(nx, ny))continue;
                int toCellIdx = idxEncodeCell(nx, ny);
                float cost = terrain_cost(from_tr) * dist(Dx[k], Dy[k])/*+ terrain_cost(to_tr)*/;
                if(preCost + cost < costs[toCellIdx]){
                    costs[toCellIdx] = preCost + cost;
                    prev[toCellIdx] = fromCellIdx;
                    pq.push({costs[toCellIdx], toCellIdx});
                }
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
    Solver aSolver(aStage);
    aMyAnswer.PositionSeq = aSolver.solve();
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

