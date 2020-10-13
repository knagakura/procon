#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int N, Q;

void Case(int i){
    cout << "Case #" << i << ": ";
}
void solve(){
    cin >> N >> Q;
    vector<int> tate(Q + 2), yoko(Q + 2);   
    rep(i,N){
        int x, y;
        char d;
        cin >> x >> y >> d;
        if(d == 'N'){
            tate[y+1]++;
            tate[Q+1]--;
        }
        if(d == 'S'){
            tate[0]++;
            tate[y]--;
        }
        if(d == 'W'){
            yoko[0]++;
            yoko[x]--;
        }
        if(d == 'E'){
            yoko[x+1]++;
            yoko[Q+1]--;
        }
    }
    for(int i = 0;i <= Q;i++){
        tate[i+1] += tate[i];
        yoko[i+1] += yoko[i];
    }
    int mxyoko = *max_element(all(yoko));
    int mxtate = *max_element(all(tate));
    rep(i,Q+1){
        if(yoko[i] == mxyoko){
            cout << i << " ";
            break;
        }
    }
    rep(i,Q+1){
        if(tate[i] == mxtate){
            cout << i << endl;
            return;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        Case(i);
        solve();
    }
}
