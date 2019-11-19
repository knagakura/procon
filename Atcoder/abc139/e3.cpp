#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef pair<int,int> P;
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
    vector<vector<int>> A(N,vector<int>(N-1,0));
    vector<vector<bool>> done(N,vector<bool>(N,false));
    rep(i,N){
        rep(j,N-1){
            cin>>A[i][j];
            A[i][j]--;
        }
        reverse(all(A[i]));
    }
    vector<P> q;
    auto check = [&](int i){
        if(A[i].size() == 0)return;
        int j = A[i].back();
        if(A[j].size() ==  0)return;
        if(i  != A[j].back())return;
        if(j < i)swap(i,j);
        if(done[i][j])return;
        q.push_back({i,j});
        done[i][j] = true;
    };
    rep(i,N)check(i);
    int ans = 0;
    while(!q.empty()){
        ans++;
        vector<P> prevQ;
        swap(prevQ, q);
        //prevQに入ってる試合を消化する（vectorから削除する）
        for(auto match: prevQ){
            int i = match.first;
            int j = match.second;
            A[i].pop_back();
            A[j].pop_back();
        }
        //試合が終わった選手に対してのみ、次の試合を考える
        //qに試合を突っ込み直す
        for(auto match: prevQ){
            int i = match.first;
            int j = match.second;
            check(i);
            check(j);
        }

    }
    rep(i,N){
        if(A[i].size() != 0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}