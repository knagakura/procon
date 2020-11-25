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

// #ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
// #else
// #define dbg(...)
// #define dump(...)
// #endif


struct Action{
    int actionId; // the unique ID of this spell or recipe
    string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
    int delta0; // tier-0 ingredient change
    int delta1; // tier-1 ingredient change
    int delta2; // tier-2 ingredient change
    int delta3; // tier-3 ingredient change
    int price; // the price in rupees if this is a potion
    int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
    int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
    bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
    bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
    Action(int actionId_, string actionType_, int delta0_, int delta1_, int delta2_, int delta3_, int price_, int tomeIndex_, int taxCount_, bool castable_, bool repeatable_):
        actionId(actionId_), 
        actionType(actionType_),
        delta0(delta0_),
        delta1(delta1_),
        delta2(delta2_),
        delta3(delta3_),
        price(price_),
        tomeIndex(tomeIndex_),
        taxCount(taxCount_),
        castable(castable_),
        repeatable(repeatable_){}
};

struct Status{
    int inv0; // tier-0 ingredients in inventory
    int inv1;
    int inv2;
    int inv3;
    int score; // amount of rupees
};
vector<Action> Actions;
vector<Action> Casts, Brews;
Status St[2];
bool checkBREW(const Action& a){
        return
        a.actionType == "BREW" && 
        a.delta0 + St[0].inv0 >= 0 && 
        a.delta1 + St[0].inv1 >= 0 && 
        a.delta2 + St[0].inv2 >= 0 && 
        a.delta3 + St[0].inv3 >= 0;
}
int main(){
    // game loop
    while (1) {
        Actions.clear();
        Casts.clear();
        Brews.clear();
        int actionCount; // the number of spells and recipes in play
        cin >> actionCount; cin.ignore();
        rep(i, actionCount) {
            int actionId; // the unique ID of this spell or recipe
            string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
            int delta0; // tier-0 ingredient change
            int delta1; // tier-1 ingredient change
            int delta2; // tier-2 ingredient change
            int delta3; // tier-3 ingredient change
            int price; // the price in rupees if this is a potion
            int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
            int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
            bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
            bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
            cin >> actionId >> actionType >> delta0 >> delta1 >> delta2 >> delta3 >> price >> tomeIndex >> taxCount >> castable >> repeatable; cin.ignore();
            Actions.emplace_back(actionId, actionType, delta0, delta1, delta2, delta3, price, tomeIndex, taxCount, castable, repeatable);
            if(actionType == "CAST"){
                Casts.emplace_back(actionId, actionType, delta0, delta1, delta2, delta3, price, tomeIndex, taxCount, castable, repeatable);
            }
            if(actionType == "BREW"){
                Brews.emplace_back(actionId, actionType, delta0, delta1, delta2, delta3, price, tomeIndex, taxCount, castable, repeatable);
            }
        }
        int sumInv = 0;
        rep(i,2){
            int inv0; // tier-0 ingredients in inventory
            int inv1;
            int inv2;
            int inv3;
            int score; // amount of rupees
            cin >> inv0 >> inv1 >> inv2 >> inv3 >> score; cin.ignore();
            St[i] = {inv0, inv1, inv2, inv3, score};
            if(i == 0){
                sumInv += inv0;
                sumInv += inv1;
                sumInv += inv2;
                sumInv += inv3;
            }
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // in the first league: BREW <id> | WAIT; later: BREW <id> | CAST <id> [<times>] | LEARN <id> | REST | WAIT
        sort(Brews.begin(), Brews.end(), [](const Action&a, const Action &b){
            return a.price < b.price;
        });
        for(auto &a: Casts){
            cerr << a.actionId << " " << a.delta0 << " " << a.delta1 << " " << a.delta2 << " " << a.delta3 << endl;
        }
        auto maxBrew = Brews.back();
        if(checkBREW(maxBrew)){
            cout << "BREW" << " " << maxBrew.actionId << endl;
        }
        else if(maxBrew.delta3 + St[0].inv3 < 0){
            if(Casts[3].castable && St[0].inv2 > 0){
                cout << "CAST" << " " << Casts[3].actionId << endl;
            }
            else if(Casts[2].castable && St[0].inv1 > 0){
                cout << "CAST" << " " << Casts[2].actionId << endl;
            }
            else if(Casts[1].castable && St[0].inv0 > 0){
                cout << "CAST" << " " << Casts[1].actionId << endl;
            }
            else if(Casts[0].castable && sumInv <= 8){
                cout << "CAST" << " " << Casts[0].actionId << endl;
            }
            else{
                cout << "REST" << endl;
            }
        }
        else if(maxBrew.delta2 + St[0].inv2 < 0){
            if(Casts[2].castable && St[0].inv1 > 0){
                cout << "CAST" << " " << Casts[2].actionId << endl;
            }
            else if(Casts[1].castable && St[0].inv0 > 0){
                cout << "CAST" << " " << Casts[1].actionId << endl;
            }
            else if(Casts[0].castable && sumInv <= 8){
                cout << "CAST" << " " << Casts[0].actionId << endl;
            }
            else{
                cout << "REST" << endl;
            }
        }
        else if(maxBrew.delta1 + St[0].inv1 < 0){
            if(Casts[1].castable && St[0].inv0 > 0){
                cout << "CAST" << " " << Casts[1].actionId << endl;
            }
            else if(Casts[0].castable && sumInv <= 8){
                cout << "CAST" << " " << Casts[0].actionId << endl;
            }
            else{
                cout << "REST" << endl;
            }
        }
        else if(maxBrew.delta0 + St[0].inv0 < 0){
            if(Casts[0].castable && sumInv <= 8){
                cout << "CAST" << " " << Casts[0].actionId << endl;
            }
            else{
                cout << "REST" << endl;
            }
        }
        else{
            cout << "REST" << endl;
        }
        // auto checkCAST = [&](const Action& a)->bool{
        //     int af0 = a.delta0 + St[0].inv0;
        //     int af1 = a.delta1 + St[0].inv1;
        //     int af2 = a.delta2 + St[0].inv2;
        //     int af3 = a.delta3 + St[0].inv3;
        //     int afSum = af0 + af1 + af2 + af3;
        //     return
        //     a.actionType == "CAST" &&
        //     a.castable &&
        //     af0 >= 0 && 
        //     af1 >= 0 && 
        //     af2 >= 0 && 
        //     af3 >= 0 && 
        //     afSum <= 10;
        // };
    }
}