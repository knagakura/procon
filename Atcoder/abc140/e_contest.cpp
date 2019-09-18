#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    int N;
    cin>>N;
    vector<ll> P(N);
    rep(i,N)P[i]=i+1;
    sort(all(P));
    do{
        ll ans = 0;
        for(int l = 0; l < N; ++l){
            for(int r = l+1; r < N; ++r){
                vector<int> v;
                for(int i = l; i <= r; ++i){
                    v.push_back(P[i]);
                }
                sort(all(v));
                ans+=v[int(v.size())-2];
            }
        }
        print(P);
        cerr<<ans<<endl;
    }while(next_permutation(all(P)));
}
/*
昇順にソート済みのvector（またはstring）を入れると
辞書順で次の並びのvectorに置き換えてくれる
辞書順最後になったら -1 を返し止まる
*/
