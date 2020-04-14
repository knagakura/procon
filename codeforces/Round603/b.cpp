#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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

    int t;cin>>t;
    rep(_,t){
        int N;
        cin>>N;
        map<string,int> map;
        vector<string> p(N);
        rep(i,N){
            cin>>p[i];
            map[p[i]]++;
        }
        //print(p);
        int cnt = 0;
        rep(i,N)rep(l,N){
            if(i==l)continue;
            if(p[i] == p[l]){
                map[p[i]]--;
                rep(j,4)rep(k,10){
                    p[i][j] = char(k+'0');
                    if(map[p[i]] == 0){
                        map[p[i]]++;
                        cnt++;
                        j = k = INF;
                    }
                }
            }
        }
        cout<<cnt<<endl;
        rep(i,N){
            cout<<p[i]<<endl;
        }
    }
}