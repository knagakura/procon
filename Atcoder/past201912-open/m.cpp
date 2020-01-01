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

    
    int N,M;
    cin>>N>>M;
    vector<long double> A(N),B(N);
    vector<long double> C(M),D(M);

    rep(i,N)cin>>A[i]>>B[i];
    rep(i,M)cin>>C[i]>>D[i];
    print(A);print(B);print(C);print(D);
    auto check = [&](long double x){
        vector<long double> E,F;
        rep(i,N){
            E.push_back(B[i]-x * A[i]);
        }
        rep(i,M){
            F.push_back(D[i]-x * C[i]);
        }
        sort(all(E),greater<long double>());
        sort(all(F),greater<long double>());
        double res = 0;
        rep(i,4){
            res += E[i];
        }
        res += max(E[4],F[0]);
        //print(E);print(F);
        //cerr<<"(x,res): "<<x<<" "<<res<<endl;
        return res >= 0;
    };

    long double ok = 0;
    long double ng = 1e7;
    int cnt = 0;
    while(cnt < 100){
        cnt++;
        long double mid = (ng + ok)/2;
        //cerr<<ok<<" "<<ng<<endl;
        if(check(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}