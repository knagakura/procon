#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
ll M[1005][1005] = {0};
ll M_dash[1005][1005] = {0};
ll R[1005][1005] = {0};

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main() {
    int N;
    cin>>N;
    vector<ll> ans(N);
    rep(i,N)rep(j,N){
        cin>>M[i][j];
        if(i!=j){
            ans[i] = M[i][j];
        }
    }
    rep(i,N)rep(j,N){
        if(i == j)continue;
        ans[i] = gcd(ans[i],M[i][j]);
    }

    rep(i,N)rep(j,N){
        if(i==j)M_dash[i][j] = 0;
        else M_dash[i][j] = ans[i]*ans[j];
    }
    vector<int> row_r(N);
    rep(i,N)rep(j,N){
        if(i == j)continue;
        R[i][j] = M_dash[i][j]/M[i][j];
        row_r[i] = R[i][j];
    }
    rep(i,N)rep(j,N){
        row_r[i] = gcd(row_r[i], R[i][j]);
    }
    rep(i,N){
        ll x = ans[i]/row_r[i];
        cout<<x;
        if(i == N-1)cout<<endl;
        else cout<<" ";
    }
    /*
    print(ans);
    cerr<<"M_dash"<<endl;
    rep(i,N)rep(j,N){
        if(i==j)cerr<<0;
        else cerr<<M_dash[i][j];
        if(j==N-1)cerr<<endl;
        else cerr<<" ";
    }
    cerr<<"R"<<endl;
    rep(i,N)rep(j,N){
        if(i==j)cerr<<0;
        else cerr<<R[i][j];
        if(j==N-1)cerr<<endl;
        else cerr<<" ";
    }
    print(row_r);
    */
}