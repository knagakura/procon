#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;

struct UnionFind{
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int n):Parent(n),sizes(n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
};

int N;
vector<int> A,B;
vector<pair<int, int>> A_sorted,B_sorted;

void INPUT(){
    cin>>N;
    A.resize(N);B.resize(N);
    rep(i,N){
        cin>>A[i];
        A_sorted.push_back({A[i],i});
    }
    rep(i,N){
        cin>>B[i];
        B_sorted.push_back({B[i],i});
    }
    sort(all(A_sorted));
    sort(all(B_sorted));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    INPUT();

    //sortしてA[i]<=B[i]を満たないならいかなる置換でも達成できない
    rep(i,N){
        if(A_sorted[i].first>B_sorted[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    //sortして達成可能な場合
    //sortしたときの対応関係から、互いに素な巡回置換の数を数える
    UnionFind uni(N);
    rep(i,N){
        uni.unite(A_sorted[i].second,B_sorted[i].second);
    }
    //互いに素な巡回置換の個数（つまり、UnionFindのグループの数）
    int cnt = 0;
    rep(i,N){
        if(uni.Parent[i] == i)cnt++;
    }
    /*
    互いに素な巡回置換が1つのとき、N-1回の互換（swap）で表現でき、
    そこから互いに素な循環が1つ増えるたびに、必要な互換の数は1ずつ減るので、
    cnt > 1のときはN-2回以内のswapで達成可能
    */
    if(cnt > 1){
        cout<<"Yes"<<endl;
        return 0;
    }
    /*
    互いに素な巡回置換が1つのとき
    Bの要素をswapしてもよければ、1つの巡回置換を2つに分解できる
    一番簡単なswapは隣り合う要素なので、そこを確認する
    A[i]<=A[i+1]
    ∧||   ∧||
    B[i]<=B[i+1]
    B[i]とB[i+1]をswapしてもいい条件は
    ・A[i]<=B[i+1]（自明）
    ・A[i+1]<=B[i]（確認）
    */
    rep(i,N-1){
        if(A_sorted[i+1].first <= B_sorted[i].first){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}