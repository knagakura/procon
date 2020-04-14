#include<bits/stdc++.h>
using namespace std;
struct DisjointSet{
  vector<int>data;
  DisjointSet(int size){data.assign(size, -1);}
  bool unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return false;
    if(data[x]>data[y])swap(x, y);
    data[x]+=data[y];
    data[y]=x;
    return true;
  }
  int find(int k){
    if(data[k]<0)return k;
    return data[k]=find(data[k]);
  }
  int size(int k){
    return -data[find(k)];
  }
};
long N,M,A[1<<17],B[1<<17],i,c;
vector<long>r;
int main(){
  cin>>N>>M;
  DisjointSet ds(N);
  for(i=0;i<M;i++)cin>>A[i]>>B[i],A[i]--,B[i]--;
  r.resize(M);
  for(i=M-1;i>=0;i--){
    r[i]=N*(N-1)/2-c;
    if(ds.find(A[i])!=ds.find(B[i])){
      c+=ds.size(A[i])*ds.size(B[i]);
      ds.unite(A[i],B[i]);
    }
  }
  for(auto e:r)cout<<e<<endl;
}
