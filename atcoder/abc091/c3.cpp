#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    vector<pair<int,int>> A,B;
    rep(i,N){
        int x,y;cin>>x>>y;
        A.push_back({y,x});
    }
    rep(i,N){
        int x,y;cin>>x>>y;
        B.push_back({x,y});
    }
    sort(all(A), greater<pair<int, int>>());
    sort(all(B));
    vector<bool> f(N, false);
    //cの小さい順
    rep(i,N){
        int c = B[i].first;
        int d = B[i].second;
        //bの大きい順
        rep(j,N){
            int a = A[j].second;
            int b = A[j].first;
            if(f[j])continue;
            if(a < c && b < d){
                f[j] = true;
                break;
            }
        }
    }
    int cnt =0;
    rep(i,N){
        if(f[i])cnt++;
    }
    cout<<cnt<<endl;
}