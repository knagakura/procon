

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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//const string dir = "DRUL";

/*---------------------------------------------------------------*/

ll XorShift() {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
/*---------------------------------------------------------------*/
/**
 * Grab the pellets as fast as you can!
 **/map<string, int> dict{
        {"ROCK",     0},
        {"PAPER",    1},
        {"SCISSORS", 2}
};
vector<string> pac_types = {"ROCK", "PAPER", "SCISSORS"};
int H, W;
int turn = 0;
int stopped_cnt;

bool IsIn(int x, int y) {
    return 0 <= x && x < H && 0 <= y && y < W;
}

int myScore;
int opponentScore;
int visiblePacCount; // all your pacs and enemy pacs in sight
int MyPacCount;
int pacId; // pac number (unique within a team)
bool mine; // true if this pac is yours
int pax; // position in the grid
int pay; // position in the grid
string typeId; // unused in wood leagues
int speedTurnsLeft; // unused in wood leagues
int abilityCooldown; // unused in wood leagues
vector<string> Field;
vvec<pair<string, int>> tmpField;
vvec<bool> visited;
vec<int> nx, ny;
int visiblePelletCount; // all pellets in sight
vector<pair<int, i_i>> Pellets;
vector<i_i> SuperPellets;
vector<bool> SuperPelletsUsed;

pair<int, int> all_search() {
    vector<pair<int, int>> v;
    rep(i, H)
        rep(j, W) {
            if (not visited[i][j])v.emplace_back(i, j);
        }
    if (v.empty())return {-1, -1};
    int idx = XorShift() % v.size();
    return v[idx];
}

class Pac {
public:
    int id;
    int x;
    int y;
    int type_id;
    int speedTurnsLeft;
    int abilityCooldown;
    vector<string> action_commands;
    vector<Pac> OpPacs;
    vector<i_i> four_dir_pellets[4];

    //constructor
    Pac(int _id, int _x, int _y, int _typeid, int speed, int abi) {
        id = _id;
        x = _x;
        y = _y;
        type_id = _typeid;
        speedTurnsLeft = speed;
        abilityCooldown = abi;
    };

    Pac() {};

    friend std::ostream &operator<<(std::ostream &os, const Pac &a) {
        os << a.y << " " << a.x;
        return os;
    }

    int pac_dist(const Pac &b) const;

    void four_direction_search();

    bool battle(const Pac &b);

    vector<string> action();

    void switch_com(Pac &min_op);

    void speed_com();

    void move_com();

    void random_move();

    void all_change();

    bool stopped();
    void move_gyaku();
};

vector<Pac> MyPacs;
vector<Pac> PreMyPacs;
vector<Pac> ALLOpPacs;
vector<i_i> ThreeWalls;
map<i_i, int> ThreeWalls_map;
map<i_i, Pac> twoD2Pac;
vvec<Pac> history(500);

void Pac::switch_com(Pac &min_op) {
    action_commands.emplace_back("SWITCH");
    action_commands.emplace_back(to_string(id));
    int idx = (min_op.type_id + 1) % 3;
    //if (pac_dist(min_op) == 1)idx = (idx + 1) % 3;
    action_commands.emplace_back(pac_types[idx]);
}

bool Pac::stopped() {
    return history[turn][id].x == history[turn - 1][id].x &&
           history[turn][id].y == history[turn - 1][id].y;
}

void Pac::move_gyaku(){
    action_commands.emplace_back("MOVE");
    action_commands.emplace_back(to_string(id));
    cerr << "gyaku" << endl;
    int nh = XorShift()%H;
    int nw = XorShift()%W;
    rep(j,4){
        nh = y + dy[j];
        nw = x + dx[j];
        if(!IsIn(nh,nw))continue;
        if(tmpField[nh][nw].first == "#")continue;
        if(tmpField[nh][nw].first == "MyPac")continue;
        if(IsIn(nh+dy[j], nw+dx[j]) && tmpField[nh+dy[j]][nw+dx[j]].first == "MyPac"){
            continue;
        }
        action_commands.emplace_back(to_string(nw));
        action_commands.emplace_back(to_string(nh));
        return;
    }
    action_commands.emplace_back(to_string(nw));
    action_commands.emplace_back(to_string(nh));
}
void Pac::speed_com() {
    action_commands.emplace_back("SPEED");
    action_commands.emplace_back(to_string(id));
}

void Pac::move_com() {
    action_commands.emplace_back("MOVE");
    action_commands.emplace_back(to_string(id));
    int cx = XorShift() % W;
    int cy = XorShift() % H;
    //スーパーペレットが残っているなら、//ペレットから最短距離にあるパックに向かわせる
    if (not SuperPellets.empty()) {
        //最短距離に向かわせる
        //MyPacsとSuperPelletsの組み合わせ全通り試して、
        cx = SuperPellets.back().first;
        cy = SuperPellets.back().second;
        SuperPellets.pop_back();
    } else {
        int maxsize = 0;
        int dir = 0;
        rep(j, 4) {
            if (chmax(maxsize, (int) four_dir_pellets[j].size())) {
                dir = j;
            }
        }
        if (maxsize > 0) {
            int nxx = x + dx[dir];
            int nyy = y + dy[dir];
            cerr << nxx << " " << nyy << endl;
            //if(visited[nyy][nxx])dir = (dir + 2) % 4;
            cx = four_dir_pellets[dir].back().first;
            cy = four_dir_pellets[dir].back().second;
            cerr << "cx, cy: " << cx << " " << cy << endl;
        } else {
            if (ThreeWalls.size() > id) {
                cerr << "MOVE TO ThreeWALLS!!!" << endl;
                cx = ThreeWalls[id].second;
                cy = ThreeWalls[id].first;
            } else {
                auto p = all_search();
                if (p.first > 0) {
                    cx = p.second;
                    cy = p.first;
                }
            }

        }
    }
    action_commands.emplace_back((to_string(cx)));
    action_commands.emplace_back((to_string(cy)));
}

void Pac::random_move() {
    action_commands.emplace_back("MOVE");
    action_commands.emplace_back(to_string(id));
    int cx = XorShift() % W;
    int cy = XorShift() % H;
    auto p = all_search();
    if (p.first > 0) {
        cy = p.first;
        cx = p.second;
    }
    cerr << "random" << endl;
    action_commands.emplace_back((to_string(cx)));
    action_commands.emplace_back((to_string(cy)));
}

void Pac::all_change() {
    action_commands.emplace_back("SWITCH");
    action_commands.emplace_back(to_string(id));
    int idx = (ALLOpPacs[0].type_id + 1) % 3;
    //if (pac_dist(min_op) == 1)idx = (idx + 1) % 3;
    action_commands.emplace_back(pac_types[idx]);
}

vector<string> Pac::action() {
    //四方の相手のパックを探す
    four_direction_search();
    cerr << "four direction search done" << endl;
    //print(Pellets);
    action_commands.emplace_back("|");
    dump(abilityCooldown);
    if(stopped() && abilityCooldown != 9)stopped_cnt++;
    //相手の種類が一種類になったら
    set<int> st;
    for (auto &op: ALLOpPacs) {
        st.insert(op.type_id);
    }
    //SWITCH
    Pac min_dist_pac;
    auto check = [&]() {
        //最も近い相手パックが、距離2以内
        int min_dist = INF;
        for (auto &op: OpPacs) {
            if (chmin(min_dist, pac_dist(op))) {
                min_dist_pac = op;
            }
        }
        return not OpPacs.empty() && min_dist <= 2 && not battle(min_dist_pac) && abilityCooldown == 0;
    };
    if (stopped() && abilityCooldown != 9) {
        if(stopped_cnt >= 2){
            move_gyaku();
        }
        else if (abilityCooldown == 0)switch_com(history[turn][id]);
        else {
            move_com();
        }
    } /*else if (abilityCooldown == 0 && st.size() == 1 && (ALLOpPacs[0].type_id + 1) % 3 != type_id) {
        all_change();
    } */else if (check()) {
        switch_com(min_dist_pac);
    }
        //SPEED
    else if (abilityCooldown == 0) speed_com();
        //MOVE
    else move_com();
    action_commands.emplace_back("|");
    return action_commands;
}


int Pac::pac_dist(const Pac &b) const {
    return abs(x - b.x) + abs(y - b.y);
}

void Pac::four_direction_search() {
    //上下左右に対して
    //壁が来る前、外に出る前
    //not visitedであり、かつPelletでないなら、visitedに変更
    OpPacs.clear();
    rep(j, 4) {
        int nh = y;
        int nw = x;
        while (true) {
            //cerr <<  nh  << " "   <<  nw << endl;
            nh += dy[j];
            nw += dx[j];
            if (not IsIn(nh, nw))break;
            //nh %= H;
            //nw %= W;
            if (tmpField[nh][nw].first == "Pellet") {
                four_dir_pellets[j].emplace_back(nw, nh);
                if (ThreeWalls_map[{nh, nw}] > 0) {
                    rep(_, 10)four_dir_pellets[j].emplace_back(nw, nh);
                }
            }
            if (tmpField[nh][nw].first == "#")break;
            if (tmpField[nh][nw].first == "MyPac") {
                cerr << "こっちはダメ！！" << endl;
                four_dir_pellets[j].clear();
                int gyaku = (j + 2)%4;
                int nextx = x+dx[gyaku];
                int nexty = y+dy[gyaku];
                if(IsIn(nexty, nextx)){
                    if(tmpField[nexty][nextx].first == "#" || XorShift()%2){
                        gyaku++;
                        gyaku %= 4;
                        nextx = x + dx[gyaku];
                        nexty = y + dy[gyaku];
                    }
                    rep(_,10){
                        four_dir_pellets[gyaku].emplace_back(nextx,nexty);
                    }
                    cerr << nextx << " " << nexty << endl;
                }
                break;
            }
            if (!visited[nh][nw] && tmpField[nh][nw].first != "Pellet") {
                visited[nh][nw] = true;
            }
            if (tmpField[nh][nw].first == "Op") {
                OpPacs.push_back(twoD2Pac[{nh, nw}]);
            }
        }
        rep(j,4)print(four_dir_pellets[j]);
    }
}

bool Pac::battle(const Pac &b) {
    //cerr << pac_types[type_id] << " VS " << pac_types[b.type_id] << endl;
    return type_id == (b.type_id + 1) % 3;
}


int pex, pey, value; // amount of points this pellet is worth

void field_input() {
    cin >> W >> H;
    cin.ignore();
    Field.resize(H);
    rep(i, H) {
        string row;
        getline(cin, row);
        Field[i] = row; // one line of the grid: space " " is floor, pound "#" is wall
    }
    rep(i, H)
        rep(j, W) {
            if (Field[i][j] == ' ') {
                Field[i][j] = '.';
            }
        }
}

void pacs_input() {
    /* Pacs */
    twoD2Pac.clear();
    ALLOpPacs.clear();
    cin >> visiblePacCount;
    cin.ignore();
    MyPacCount = 0;
    MyPacs.clear();
    for (int i = 0; i < visiblePacCount; i++) {
        cin >> pacId >> mine >> pax >> pay >> typeId >> speedTurnsLeft >> abilityCooldown;
        int typeid_int = dict[typeId];
        cin.ignore();
        if (mine) {
            MyPacs.emplace_back(pacId, pax, pay, typeid_int, speedTurnsLeft, abilityCooldown);
        } else {
            ALLOpPacs.emplace_back(pacId, pax, pay, typeid_int, speedTurnsLeft, abilityCooldown);
            twoD2Pac[{pay, pax}] = ALLOpPacs.back();
        }
    }
    //print(ALLOpPacs);
    //print(twoD2Pac);
    MyPacCount = MyPacs.size();
}

void pellets_input() {
    /* Pellets */
    cin >> visiblePelletCount;
    cin.ignore();
    Pellets.clear();
    SuperPellets.clear();
    for (int i = 0; i < visiblePelletCount; i++) {
        cin >> pex >> pey >> value;
        cin.ignore();
        if (value > 1) {
            SuperPellets.emplace_back(pex, pey);
        }
        Pellets.push_back({value, {pex, pey}});
    }
    SuperPelletsUsed.assign(SuperPellets.size(),false);
    sort(all(Pellets));
    //reverse(all(Pellets));
}

void game_input() {
    cin >> myScore >> opponentScore;
    cin.ignore();
    pacs_input();
    pellets_input();
}


void random_move() {
    rep(i, MyPacCount) {
        cout << "|" << "MOVE " << MyPacs[i].id << " ";
        if (nx[i] >= 0 && ny[i] >= 0) {
            if (MyPacs[i].x == PreMyPacs[i].x && MyPacs[i].y == PreMyPacs[i].y) {
                nx[i] = XorShift() % W;
                ny[i] = XorShift() % H;
                cout << nx[i] << " " << ny[i];
            } else {
                cout << nx[i] << " " << ny[i];
            }
        } else {
            auto q = all_search();
            if (q.first == -1) {
                nx[i] = XorShift() % W;
                ny[i] = XorShift() % H;
                cout << nx[i] << " " << ny[i];
            } else {
                cout << q.first << " " << q.second;
            }
        }
        cout << "|";
    }
    cout << endl;
}

void tmp_field_setting() {
    tmpField.assign(H, vector<pair<string, int>>(W, {"", -1}));
    rep(i, H) {
        rep(j, W) {
            if (Field[i][j] == '#')tmpField[i][j].first.push_back('#');
            else tmpField[i][j].first.push_back('.');
        }
    }

    rep(i, MyPacCount) {
        tmpField[MyPacs[i].y][MyPacs[i].x].first = "MyPac";
        visited[MyPacs[i].y][MyPacs[i].x] = true;
    }
    for (auto &op: ALLOpPacs) {
        tmpField[op.y][op.x].first = "Op";
        visited[op.y][op.x] = true;
    }
    rep(i, visiblePelletCount) {
        value = Pellets[i].first;
        pex = Pellets[i].second.first;
        pey = Pellets[i].second.second;
        tmpField[pey][pex].first = "Pellet";
        tmpField[pey][pex].second = value;
    }
    rep(i, MyPacCount) {
        //上下左右に対して
        //壁が来る前、外に出る前
        //not visitedであり、かつPelletでないなら、visitedに変更
        rep(j, 4) {
            int nh = MyPacs[i].y;
            int nw = MyPacs[i].x;
            while (IsIn(nh + dy[j], nw + dx[j]) && tmpField[nh + dy[j]][nw + dx[j]].first != "#") {
                nh += dy[j];
                nw += dx[j];
                if (!visited[nh][nw] && tmpField[nh][nw].first != "Pellet") {
                    visited[nh][nw] = true;
                }
            }
        }
    }
    ThreeWalls.clear();
    rep(i, H)
        rep(j, W) {
            if (tmpField[i][j].first == ".") {
                int cnt = 0;
                rep(k, 4) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (!IsIn(ni, nj))continue;
                    if (tmpField[ni][nj].first == "#")cnt++;
                }
                if (cnt == 3) {
                    if (!visited[i][j]) {
                        ThreeWalls.emplace_back(i, j);
                        ThreeWalls_map[{i, j}] = 1;
                    }
                }
            }
        }
}


void Cout() {
    stopped_cnt = 0;
    for (auto &pac: MyPacs) {
        vector<string> v = pac.action();
        for (auto &s: v) {
            cout << s << " ";
        }
    }
    cout << endl;
}

void show_visited() {
    rep(i, H) {
        rep(j, W) {
            if (tmpField[i][j].first == "#") {
                cerr << "#";
            } else if (tmpField[i][j].first == "Pellet") {
                cerr << "o";
            } else if (tmpField[i][j].first == "MyPac") {
                cerr << "M";
            } else if (tmpField[i][j].first == "Op") {
                cerr << "P";
            } else if (visited[i][j]) {
                cerr << "x";
            } else {
                cerr << ".";
            }
        }
        cerr << endl;
    }
}

void set_history() {
    history[0].resize(10);
    history[turn].resize(10);
    for (auto &pac: MyPacs) {
        history[turn][pac.id] = pac;
    }
}

// game loop
void game_loop() {
    nx.assign(10, -1);
    ny.assign(10, -1);
    visited.assign(H, vec<bool>(W, false));
    int Q = 500;
    while (Q--) {
        turn++;
        game_input();
        cerr << "game input done" << endl;
        tmp_field_setting();
        cerr << "temp_field_setting done" << endl;
        print(ThreeWalls);
        set_history();
        cerr << "history_setting done" << endl;
        Cout();
        show_visited();
        swap(PreMyPacs, MyPacs);
    }
}

int main() {
    field_input();
    game_loop();
}
