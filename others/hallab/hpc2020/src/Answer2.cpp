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
float beki[M+5];
int scrollN; // ステージにある巻物の個数
Vector2 ini_pos;
vector<Scroll> anslist; // random_moveのときに使う、移動する順序
vector<vector<Vector2>> paths; // path[idx_encode(i, j)] := i -> jへの最短経路
vector<int> scrollseq; // 巻物の周り順（本質情報）
int scrollseq_idx;
int cell_idx;
float distScroll[M+5][M+5];
// chokudai search用のクラス。priority_queueに入れてコストを管理する
struct ScrollTour{
    vector<int> seq;
    vector<bool> used;
    float cost = 0.0f;
    ScrollTour(){
        cost = 0.0f;
        used.assign(scrollN, false);
    }
    ScrollTour(vector<int>& seq_): seq(seq_){
        used.assign(scrollN, false);
        for(auto x: seq)used[x] = true;
    }
    void add_scroll(int idx){
        if(seq.empty()){
            used[idx] = true;
            seq.emplace_back(idx);
            return;
        }
        used[idx] = true;
        cost += distScroll[seq.back()][idx] / beki[(int)seq.size()-1];
        seq.emplace_back(idx);
    }

    float added_cost_if(int idx){
        if(seq.empty())return 0;
        return cost + distScroll[seq.back()][idx] / beki[(int)seq.size()-1];
    }

    bool operator<(const ScrollTour& b) const{
        return (*this).cost > b.cost;
    }
};
vector<priority_queue<ScrollTour>> vpq;





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
    rep(i,M)rep(j,M)distScroll[i][j] = -1;
    scrollseq.clear();
    paths.clear();
    vpq.clear();
}
void parametar_ini(const Stage &aStage){
    scrollN = aStage.scrolls().count() + 1; // +1は最初の点
    ini_pos = aStage.rabbit().pos();
    scrollseq_idx = 0;
    cell_idx = 0;
    paths.resize(scrollN*scrollN);
    vpq.resize(scrollN);
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

void build_distance_matrix(const Stage& aStage){
    Dijkstra<float> G(H*W, 1e5);
    build_make_edges(aStage, G);

    vector<Vector2> positions;
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

float calc_cost(const vector<int>& v){
    float cost = 0;
    int sz = v.size();
    rep(i,sz-1){
        int l = v[i], r = v[i+1];
        cost += distScroll[l][r] / beki[i];
    }
    return cost;
}

int gochagocha(const vector<int> &tmpseq){
    vector<int> cntx(H,0), cnty(W,0);
    rep(i,tmpseq.size()-1){
        int scroll_l = tmpseq[i];
        int scroll_r = tmpseq[i+1];
        int path_idx = scroll_l* scrollN + scroll_r;
        for(auto v: paths[path_idx]){
            int a = v.x;
            int b = v.y;
            cntx[a]++;
            cnty[b]++;
        }
    }
    int res = 0;
    rep(i,H)res += max(0, cntx[i]-2);
    rep(i,W)res += max(0, cnty[i]-2);
    return res;
}
vector<int> chokudai_search(const Stage &aStage){
    // 定数
    MyTimer timer;
    //　初期はクラスカルでやる
    auto ini_seq = kuraskal();

    //　この時の形状の特徴量を測る
    // int gocha = gochagocha(ini_seq);
    // dump(gocha);
    // dump(ini_seq);
    ScrollTour ini_tour;
    // ターン毎にpqに突っ込んでいく
    rep(t,scrollN){
        ini_tour.add_scroll(ini_seq[t]);
        vpq[t].push(ini_tour);
    }


    timer.reset();
    int cnt = 0;
    double TIME_LIMIT = 0.40;
    int Chokudai_width = 1;
    while(true){
        cnt++;
        auto now_time = timer.get();
        if(now_time >= TIME_LIMIT) break;
        for(int t = 0; t < scrollN - 1; t++){
            rep(_,Chokudai_width){
                if(vpq[t].empty())break;
                ScrollTour past = vpq[t].top();
                vpq[t].pop();
                for(int l = 0; l < scrollN; l++){
                    if(not past.used[l]){
                        ScrollTour nxt = past;
                        nxt.add_scroll(l);
                        vpq[t+1].push(nxt);
                    }
                }
            }
        }
    }
    ScrollTour res = vpq[scrollN-1].top();
    // dbg(scrollN);
    // dbg(ini_tour.seq, ini_tour.cost);
    // dbg(res.seq, res.cost);
    return res.seq;
}

vector<int> bluteforce(){
    float min_cost = 1e5;
    vector<int> tmp, res;
    rep(i,scrollN-1){
        tmp.push_back(i);
    }
    sort(tmp.begin(), tmp.end());
    do{
        vector<int> tmp2;
        tmp2.push_back(scrollN-1);
        rep(i,scrollN-1)tmp2.push_back(tmp[i]);
        if(chmin(min_cost, calc_cost(tmp2))){
            res = tmp2;
        }
    }while(next_permutation(tmp.begin(), tmp.end()));
    return res;
}
// [l, r)に関して、順列を変えてみてコストが最小のものに変換する
void bluteforce(int l, int r, vector<int>& scrollseq_){
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
        // scrollseq = kuraskal();
    }
    else{
        // scrollseq = kuraskal();
        scrollseq = chokudai_search(aStage);
    }
}
/// コンストラクタ
/// @detail 最初のステージ開始前に実行したい処理があればここに書きます
Answer::Answer()
{
    beki[0] = 1.0f;
    rep(i,M)beki[i+1] = beki[i] * 1.1f;
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
    build_distance_matrix(aStage); // scroll x scrollの距離行列の構築
    build_scrollseq(aStage); // scroll Tourの構築
}
float get_jumpdist(const Stage& aStage, const Rabbit& rabbit){
    return rabbit.power() * terrain_magni(aStage.terrain(rabbit.pos()));
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
    return res;

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