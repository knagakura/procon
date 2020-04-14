#include<bits/stdc++.h>
using namespace std;
using Int = long long;

signed main(){
  Int n;
  cin>>n;
  vector<vector<Int> > G(n);
  for(Int i=1;i<n;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  priority_queue<Int,vector<Int>,greater<Int> > pq;
  vector<Int> ans,used(n,0);
  pq.emplace(0);
  used[0]=1;
  while(!pq.empty()){
    Int v=pq.top();pq.pop();
    ans.emplace_back(v);
    for(Int u:G[v]){
      if(used[u]) continue;
      used[u]=1;
      pq.emplace(u);
    }
  }
  
  for(Int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}
