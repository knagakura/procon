#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<vector<pair<Int,Int>>> G(n);
  for(Int i=1;i<n;i++){
    Int u,v,w;
    cin>>u>>v>>w;
    u--;v--;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
  }
  priority_queue<Int,vector<Int>,greater<Int> > pq;
  vector<Int> ans(n),used(n,0);
  pq.emplace(0);
  used[0]=1;
  ans[0] = 1;
  while(!pq.empty()){
    Int v=pq.top();pq.pop();
    for(pair<Int,Int> u:G[v]){
    	Int x = u.first;
    	Int y = u.second;
      if(used[x]) continue;
      if(y%2 == 0){
      	ans[x] = ans[v];
      }
      else{
      	if(ans[v] == 0){
      		ans[x] = 1;
      	}
      	else{
      		ans[x] = 0;
      	}
      }
      used[x]=1;
      pq.emplace(x);
    }
  }
  
  for(Int i=0;i<n;i++){
  	cout<<ans[i]<<endl;
  }
  return 0;
}
