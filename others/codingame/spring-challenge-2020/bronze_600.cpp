#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
/*---------------------------------------------------------------*/

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
/*---------------------------------------------------------------*/
/**
 * Grab the pellets as fast as you can!
 **/
int H, W;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
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

int visiblePelletCount; // all pellets in sight
int pex, pey,value; // amount of points this pellet is worth

vector<string> Field;

struct Pac{
    int id;
    int x;
    int y;
    int speedTurnsLeft;
    int abilityCooldown;
    Pac(int _id, int _x, int _y, int speed,int abi){
        id = _id;
        x = _x;
        y = _y;
        speedTurnsLeft = speed;
        abilityCooldown = abi;
    };
    //string typeid;
};


void field_input(){
    cin >> W >> H; cin.ignore();
    Field.resize(H);
    rep(i,H) {
        string row;
        getline(cin, row);
        Field[i] = row; // one line of the grid: space " " is floor, pound "#" is wall
    }
    rep(i,H)rep(j,W){
        if(Field[i][j] == ' '){
            Field[i][j] = '.';
        }
    }
    /*
    rep(i,H){
        rep(j,W){
            cerr << Field[i][j];
        }
        cerr << endl;
    }*/
}


// game loop
void game_loop(){
    vec<int> nx(10,-1);
    vec<int> ny(10,-1);
    int cnt = 0;
    vector<Pac> PreMyPacs;
    int turnnum = 0;
    while (1) {
        cin >> myScore >> opponentScore; cin.ignore();

        /* Pacs */
        cin >> visiblePacCount; cin.ignore();
        MyPacCount = 0;
        vector<Pac> MyPacs;
        for (int i = 0; i < visiblePacCount; i++) {
            cin >> pacId >> mine >> pax >> pay >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();
            if(mine){
                MyPacs.emplace_back(pacId, pax, pay,/* typeId,*/speedTurnsLeft, abilityCooldown);
            }
        }
        
        MyPacCount = MyPacs.size();
        /* Pellets */
        cin >> visiblePelletCount; cin.ignore();
        vector<pair<int,i_i>> Pellets;
        for (int i = 0; i < visiblePelletCount; i++) {
            cin >> pex >> pey >> value; cin.ignore();
            Pellets.push_back({value, {pex,pey}});
        }
        sort(all(Pellets));
        reverse(all(Pellets));
        if(visiblePelletCount == 0){
            rep(i,MyPacCount){
                cout << "|" << "MOVE " << MyPacs[i].id << " ";
                
                if(nx[i] >= 0 && ny[i] >= 0){
                    if(MyPacs[i].x == PreMyPacs[i].x && MyPacs[i].y == PreMyPacs[i].y){
                        nx[i] = XorShift()%W;
                        ny[i] = XorShift()%H;
                        cout << nx[i] << " " << ny[i];
                    }
                    else{
                        cout << nx[i] << " " << ny[i];
                    }
                }
                else {
                    nx[i] = XorShift()%W;
                    ny[i] = XorShift()%H;
                    cout << nx[i] << " " << ny[i];
                }
                cout << "|";
            }
            cout << endl;
            swap(PreMyPacs, MyPacs);
            continue;
        }
        
        vvec<pair<string, int>> tmpField(H,vector<pair<string, int>>(W, {".",-1}));
        
        rep(i,H)rep(j,W){
            if(Field[i][j] == '#')tmpField[i][j].first.push_back('#');
        }
        rep(i, MyPacCount){
            tmpField[MyPacs[i].y][MyPacs[i].x].first = "Pac";
        }
        rep(i,visiblePelletCount){
            value = Pellets[i].first;
            pex = Pellets[i].second.first;
            pey = Pellets[i].second.second;
            tmpField[pey][pex].first = "Perret";
            tmpField[pey][pex].second = value;
        }
        auto search = [&](int sw, int sh) -> pair<int, int>{
            for(int i = -2; i <= 2; i++){
                for(int j = -2; j <= 2; j++){
                    int nw = sw + j;
                    int nh = sh + i;
                    if(!IsIn(nh, nw))continue;
                    if(tmpField[nh][nw].second > 0){
                        return {nw, nh};
                    }
                }
            }
            return {-1,-1};
        };
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        
        rep(i,MyPacCount){
            cout << "|";
            if(MyPacs[i].abilityCooldown == 0){
                cout << "SPEED " << MyPacs[i].id << "|";
            }
            else{
                cout << "MOVE ";
                cout << MyPacs[i].id <<  " ";
                //前回と同じだったら
                if(PreMyPacs.size() > 0 && MyPacs[i].x == PreMyPacs[i].x && MyPacs[i].y == PreMyPacs[i].y){
                    int idx = XorShift()%visiblePelletCount;
                    nx[i] = Pellets[idx].second.first;
                    ny[i] = Pellets[idx].second.second;
                    cout << nx[i] << " " << ny[i];
                }
                //まだsuperペレットが残っているなら
                else if(Pellets[i].first > 1){
                    cout << Pellets[i].second.first  << " " << Pellets[i].second.second;
                }
                //全部normalになったら
                else{
                    auto p = search(MyPacs[i].x, MyPacs[i].y);
                    if(p.first >= 0){
                        cout << p.first << " " << p.second;
                    }
                    else{
                        if(nx[i] >= 0 && ny[i] >= 0){
                            cout << nx[i] << " " << ny[i];
                        }
                        else {
                            int idx = XorShift()%visiblePelletCount;
                            nx[i] = Pellets[idx].second.first;
                            ny[i] = Pellets[idx].second.second;
                            cout << nx[i] << " " << ny[i];
                        }
                    }
                }
            }
            cout << "|";
        }
        cout << endl;
        swap(PreMyPacs, MyPacs);
        turnnum++;
    }
}
int main(){
    field_input();
    game_loop();
}
