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
int d[105][105] = {0};

int main() {
    int N;
    cin>>N;

    vector<P> A,B;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        A.push_back({a,b});
    }
    rep(i,N){
        int c,e;
        cin>>c>>e;
        B.push_back({c,e});
    }
    int ans = 0;
    rep(i,N)rep(j,N){
        int x1,y1,x2,y2;
        x1 = A[i].first;
        y1 = A[i].second;
        x2 = B[j].first;
        y2 = B[j].second;
        //cerr<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        if(x1<x2&&y1<y2){
            d[i][j] = 1;
        }
    }
    rep(i,N)rep(j,N){
        cerr<<d[i][j];
        if(j == N-1)cerr<<endl;
        else cerr<<" ";
    }
    cout<<ans<<endl;

}