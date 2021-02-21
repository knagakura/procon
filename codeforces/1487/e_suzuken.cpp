#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
const vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>void debag(const vector<T> &a){cerr<<"debag :";for(auto v:a)cerr<<v<<" ";cerr<<"\n";}
template<class T>void print(const vector<T> &a){for(auto v:a)cout<<v<<" ";cout<<"\n";}
void solve(){
    V<ll>  n(4);
    for(int i=0;i<4;i++)cin>>n[i];
    V<V<ll>> d(4);
  //  V<V<P>> cp(4);
    int N=*max_element(all(n));
    V<ll> dp(N,inf);
    for(int i=0;i<4;i++){
         d[i].resize(n[i]);
         for(int j=0;j<n[i];j++)cin>>d[i][j];
         if(i==0){
             for(int j=0;j<n[i];j++){
                  dp[j]=d[i][j];
             }
         }
    }
    for(int i=0;i<3;i++){
        int m;
        cin>>m;
        V<set<int>> g(n[i]);
        for(int j=0;j<m;j++){
            int a,b;
            cin>>a>>b;
            --a;--b;
            g[a].insert(b);
        }
        V<P> cp(n[i]);
        for(int j=0;j<n[i];j++){
            cp[j]=P(dp[j],j);
        }
        sort(all(cp));
    //     for(int j=0;j<n[i];j++){
    //         cout<<cp[j].se<<" ";
    //     }
    //    // cout<<"\n";
        V<ll> ndp(N,inf);
        set<int> s;
        for(int j=0;j<n[i+1];j++)s.insert(j);
        for(int j=0;j<n[i];j++){
              if(s.size()==0)break;
              int st=cp[j].se;
              V<int> tmp={};
              for(auto v:s){
                   if(g[st].count(v))continue;
                   ndp[v]=dp[st]+d[i+1][v];
                   tmp.emplace_back(v);
              }
              for(int v:tmp)s.erase(v);
        }
        swap(dp,ndp);
    }
    ll ans=*min_element(all(dp));
    cout<<(ans>=inf?-1:ans)<<"\n";
}
int main(){
  int t=1;
  //cin>>t;
  while(t--)solve();
}