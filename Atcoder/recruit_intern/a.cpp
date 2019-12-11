#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

const int INF = 1e9;


//連結なグラフそれぞれに対して、その妥当性が検証される
//ある年齢が決まっていない点（age[i] ==INF)からdfsを開始する。
//最初を0として、負の年齢を許す。
//そこから始まった連結なグラフにおいて、年齢の最大値、最小値を管理する。
//条件1. グラフ中の年齢で矛盾が生じないこと（生じたら、flagをfalseにする)
//条件2. 条件1を満たしている場合、グラフ内の年齢の差が最大値-最小値で決まる
//それが100を超えなければ、候補に加え、最後に連結なグラフの数だけ候補があるので、それの最大値を出力する
//一つでも100を超えていたら、-1

using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;

int N,Q;
bool flag = true;
long long max_age = 0, min_age = 0;

void dfs(const Graph &G, int v, int p, int sum, vector<long long> &age) {
    age[v] = sum;
    //最大値、最小値の更新
    max_age = max(max_age, age[v]);
    min_age = min(min_age, age[v]);
    for (auto e : G[v]) {
        //親の場合は行かない
        if (e.first == p) continue;
        //まだ年齢が計算されていなければ
        if(age[e.first] == INF){
            //続ける
            dfs(G, e.first, v, sum+e.second, age);
        }
        //すでに年齢が計算されているのであれば、
        else{
            //矛盾するかを確認
            if(age[e.first] != sum + e.second){
                //矛盾していたらflagをfalseにする
                flag = false;
                return;
            }
        }
    }
}

int main() {
    cin>>N>>Q;
    Graph G(N);
    vector<long long> age(N, INF);
    rep(i,Q){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        if(c<0){
            swap(a,b);
            c*=-1;
        }
        G[a].push_back({b,c});
        G[b].push_back({a,-c});
    }
    long long ans = 0;
    rep(i,N){
        //まだ年齢が決定していなければ
        if(age[i] == INF){
            //年齢の最大値、最小値を初期化し
            max_age = 0, min_age = 0;
            //そこから連結なグラフをdfs
            dfs(G,i,-1,0,age);
            //差が100を超えていたら
            if(max_age - min_age >100){
                //flagをfalseにしてbreak
                flag = false;
                break;
            }
            //差が100以内なら
            else{
                //ansを更新
                ans = max(ans, max_age-min_age);
            }
        }
    }
    if(!flag){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
