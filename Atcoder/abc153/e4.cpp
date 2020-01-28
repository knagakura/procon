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

    int H,N;
    cin>>H>>N;
    vector<pair<double,pair<ll,ll>>> AB;
    ll maxa = 0;
    rep(i,N){
        ll a,b;
        cin>>a>>b;
        chmax(maxa, a);
        AB.push_back({double(a/double(b)),{-b,a}});
    }
    sort(all(AB));
    reverse(all(AB));
    ll sumb = 0;
    while(H>0){
        int idx = 0;
        if(H > maxa){
            ll a0 = AB[0].second.second;
            ll b0 = -AB[0].second.first;
            H -= a0;
            sumb += b0;
        }
        else{
            ll minb = INFLL;
            rep(i,N){
                ll a = AB[i].second.second;
                ll b = -AB[0].second.first;
                if(H <= a){
                    if(chmin(minb, b)){
                    idx = i;
                    }
                }
                sumb += minb;
                H = 0;
            }
        }
        cerr<<H<<endl;
        cerr<<idx<<endl;
    }
    cout<<sumb<<endl;
}