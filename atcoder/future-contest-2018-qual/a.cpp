#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int A[100][100];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N = 100;
    rep(i,N)rep(j,N){
        cin>>A[i][j];
    }
    vector<pair<int,pair<int,int>>> v;
    rep(i,N)rep(j,N){
        v.push_back({A[i][j],{i,j}});
    }
    sort(all(v));
    vector<pair<int, pair<int,int>>> ans;
    rep(i,(int)v.size()-1){
        if(v[i].first != v[i+1].first){
            ans[v[i]];
        }
    }
}