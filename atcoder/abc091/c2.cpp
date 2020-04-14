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
        A.push_back({x,y});
    }
    rep(i,N){
        int x,y;cin>>x>>y;
        B.push_back({x,y});
    }
    sort(all(A));sort(all(B));
    vector<bool> f(N,false);
    rep(i,N){
        int j = lower_bound(all(B),A[i])-B.begin();
        if(j == N)continue;
        while(j<N){
            if(A[i].second < B[i].second){
                if(f[j]){
                    j++;
                }
                else{
                    f[j] = true;
                    cerr<<"pair: "<<i<<" "<<j<<endl;
                    break;
                }
            }
            else{
                j++;
            }
        }
    }
    int cnt = 0;
    rep(i,N){
        if(f[i])cnt++;
    }
    printpair(A);printpair(B);
    cout<<cnt<<endl;
}