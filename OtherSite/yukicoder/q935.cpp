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

    int N;
    string S;
    cin>>N>>S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    int Q;
    cin>>Q;
    vector<int> K(Q);
    rep(i,Q)cin>>K[i];
    auto solve = [&](int k){
        int res = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        for(int l = 0;l < N;l++){
            while(r < N&&sum+A[r] <= k){
                sum += A[r];
                if(S[r] == 'E')cnt++;
                r++;
            }
            chmax(res, cnt);
            if(l == r){
                r++;
            }
            else{
                sum -= A[l];
                if(S[l] == 'E')cnt--;
            }
        }
        return res;
    };
    rep(i,Q){
        cout<<solve(K[i])<<endl;;
    }

}