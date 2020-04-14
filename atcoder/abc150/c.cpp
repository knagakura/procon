#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    vector<ll> P(N);
    rep(i,N)cin>>P[i];
    vector<ll> Q(N);
    rep(i,N)cin>>Q[i];
    vector<ll> v(N);
    rep(i,N)v[i] = i+1;
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    int cnt = 0;
    int a = 0;
    int b = 0;
    sort(all(v));
    do{
        cnt++;
        //print(v);
        if(v == P)a = cnt;
        if(v == Q)b = cnt;
    }while(next_permutation(all(v)));
    cout<<abs(a - b)<<endl;
};