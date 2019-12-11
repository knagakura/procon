#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> a(4);
    int summ = 0;
    rep(i,4){
        cin>>a[i];
        summ += a[i];
    }
    sort(all(a));
    /*
    昇順にソート済みのvector（またはstring）を入れると
    辞書順で次の並びのvectorに置き換えてくれる
    辞書順最後になったら -1 を返し止まる
    */
    string ans = "NO";
    do{
        if(a[0] + a[1] == a[2] + a[3]){
            ans = "YES";
        }
        else if(a[0] == a[1] + a[2] + a[3]){
            ans = "YES";
        }
    }while(next_permutation(all(a)));
    cout<<ans<<endl;
}