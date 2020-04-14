#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

int N,M;
vector<vector<pair<int,int>>> Graph;
vector<int> A;
void INPUT(){
    cin>>N>>M;
    Graph.resize(N);
    A.assign(N,-1);
    rep(i,M){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        z %= 2;
        Graph[x].push_back({y,z});
        Graph[y].push_back({x,z});
    }
}
int solve(){
    queue<int> Q;
    int cnt = 0;
    rep(i,N){
        if(A[i]==-1){
            Q.push(i);
            cnt++;
            while(!Q.empty()){
                auto xi = Q.front();
                Q.pop();
                A[xi] = 1;
                for(auto nx:Graph[xi]){
                    int cost = nx.second;
                    if(A[nx.first]!=-1)continue;
                    A[nx.first] =1;
                    Q.push(nx.first);
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    INPUT();
    cout<<solve()<<endl;
}