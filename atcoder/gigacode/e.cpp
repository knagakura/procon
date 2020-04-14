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
 
 const ll INF = 1e12;
 const ll INFLL = 1e18;
 const ll MOD = 1e9+7;
 const double PI = acos(-1.0);
 
 const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
 const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
 
 ll N,L;
 /*------------------------------------/
 for library*/
 
 /*------------------------------------*/
 
 int main() {
     cin.tie(0);
     ios::sync_with_stdio(false);
     cout << fixed << setprecision(20);
     cin>>N>>L;
     vector<ll> X(N+1),V(N+1),D(N+1);
     vector<pair<ll,pair<int,int>>> XVD;
     ll xin,vin,din;
     cin>>vin>>din;

     XVD.push_back({0, {vin,din}});
     rep1(i,N+1){
         cin>>xin>>vin>>din;
         XVD.push_back({xin, {vin,din}});
     }
     sort(all(XVD));
     rep(i,N+1){
         X[i] = XVD[i].first;
         V[i] = XVD[i].second.first;
         D[i] = XVD[i].second.second;
     }
     vector<vector<pair<double,pair<ll,ll>>>> dp(N+1);
     dp[0].push_back({0,{V[0],D[0]}});
     rep1(i,N+1){
         dp[i].push_back({-1,{V[i],D[i]}});
     }
     /*
     double dp_time[N+1];
     dp_time[0] = 0;
     rep1(i,N+1){
         dp_time[i] = INF;;
     }
     */
     for(int i = 0; i < N; i++){
         double min_time = INF;
         for(auto car: dp[i]){
             double t = car.first;
             if(t == -1)continue;
             chmin(min_time, t);
         }
         if(min_time == INF){
             break;
         }
         for(auto car: dp[i]){
             double t = car.first;
             int v = car.second.first;
             int d = car.second.second;
             if(t == -1){
                 t = min_time;
             }
             if(X[i+1]-X[i] <= d){
                 double time = (X[i+1]-X[i])/(double)v;
                 t += time;
                 d -= X[i+1]-X[i];
                 dp[i+1].push_back({t, {v,d}});
                 /*
                 chmin(dp_time[i+1], dp_time[i]+time);
                 dp[i+1].push_back({v, d-X[i+1]+X[i]});
                 */
                 
             }
         }
      } 

     if(dp[N].size() == 1&&dp[N][0].first == -1){
         cout<<"impossible"<<endl;
         return 0;
     }
     else{
         double ans = INF;
         double min_time = INF;
         for(auto car: dp[N]){
             double t = car.first;
             if(t == -1)continue;
             chmin(min_time, t);
         }
         for(auto car: dp[N]){
             double t = car.first;
             int v = car.second.first;
             int d = car.second.second;
             if(t == -1)t = min_time;
             if(L-X[N]<= d){
                 double time = (L-X[N])/(double)v;
                 t += time;
                 chmin(ans, t);
             }
         }
         cout<<ans<<endl;
     }
     //print(X);print(V);print(D);
 }