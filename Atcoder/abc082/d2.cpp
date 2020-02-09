#include <bits/stdc++.h>
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define reprrev(i,a,b) for(int i=b-1;i>=a;i--) // [a, b)
#define reprev(i,n) reprrev(i,0,n)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    cin.tie(0);
    ios::sync_with_stdio(false);<- これら、printfとかと併用しない方が良さそう

*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n==0) return 1;
    ll res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };


// 線分 ab の偏角 返り値は[-π, π]
double argument(const pair<double, double> &a, const pair<double, double> &b){
    double ax=a.first, ay=a.second, bx=b.first, by=b.second;
    return atan2(by-ay, bx-ax);
}

/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */
/* <-----------------------------------------------------------------------------------> */

vector<pair<int, char>> RLE(const string &s){
    int cnt=0;
    vector<pair<int, char>> res;
    rep(i, s.size()){
        ++cnt;
        if(i == s.size()-1){
            res.push_back(make_pair(cnt, s[i]));
        }
        else if(s[i] != s[i+1]){
            res.push_back(make_pair(cnt, s[i]));
            cnt=0;
        }
    }
    return res;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s; cin >> s;
    int x, y; cin >> x >> y;

    auto rle = RLE(s);
    bool first_flg = (rle[0].second == 'F');
    vector<int> yoko, tate;

    int tcnt = 0;
    for(auto p : rle){
        if(p.second == 'T') tcnt += p.first;
        if(p.second == 'F'){
            if(tcnt%2 == 0) yoko.push_back(p.first);
            if(tcnt%2 == 1) tate.push_back(p.first);
        }
    }

    print(yoko);
    print(tate);
    int base = 8500;
    vector<vector<bool>> dpyoko(yoko.size()+5, vector<bool>(2*base, false));
    vector<vector<bool>> dptate(tate.size()+5, vector<bool>(2*base, false));

    dpyoko[0][base] = true;
    dptate[0][base] = true;
    rep(i, yoko.size()){
        rep(j, 2*base) if(dpyoko[i][j]) {
            if(i == 0){
                dpyoko[i+1][j+yoko[i]] = true;
                if(!first_flg) dpyoko[i+1][j-yoko[i]] = true;
            }
            else{
                dpyoko[i+1][j+yoko[i]] = true;
                dpyoko[i+1][j-yoko[i]] = true;
            }
        }
    }

    rep(i, tate.size()) rep(j, 2*base) if(dptate[i][j]) {
        dptate[i+1][j+tate[i]] = true;
        dptate[i+1][j-tate[i]] = true;
    } 

    if(dpyoko[yoko.size()][base+x] && dptate[tate.size()][base+y]) cout << "Yes\n";
    else cout << "No\n";

    // cout << base+x << ' ' << base+y << endl;
    //cout << first_flg << endl;
    
    return 0;
}
