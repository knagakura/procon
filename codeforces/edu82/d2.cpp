#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

ll N,M;
vector<ll> a;
vector<ll> beki;
vector<ll> Nbeki;

int log_2(ll X){
    int res = 0;
    while(X > 1){
        res++;
        X /= 2;
    }
    return res;
}

void solve(){
    cin >> N >> M;
    Nbeki.assign(70, 0);
    rep(i,60){
        if(N & bit(i))Nbeki[i] = 1;
    }
    a.assign(M, 0);
    beki.assign(70, 0);
    ll suma = 0;
    rep(i,M){
        cin>>a[i];
        suma += a[i];
        beki[log_2(a[i])]++;
    }
    if(suma < N){
        cout<< -1 << endl;
        return;
    }
    //print(Nbeki);print(beki);
    ll ans = 0;
    int i = 0;
    while(i <= 60){
        //箱が必要な場合
        if(Nbeki[i] == 1){
            //すでに箱があるなら
            if(beki[i] > 0){
                beki[i]--;
                Nbeki[i]--;
            }
            //ないなら上に探しにく
            //一個上に行くごとに分割が増える
            //上に到達したとき、戻る必要がない
            //なぜなら、それ以下の箱は到達した場所から分割された過程で
            //全て一個以上用意されているからである
            else{
                while(i <= 60){
                    Nbeki[i] = 0;
                    i++;
                    ans++;
                    if(beki[i] > 0)break;
                }
                //上の桁から取る
                beki[i]--;
                //到達したところから次のループを始めるため
                continue;
            }
        }
        beki[i+1] += beki[i] / 2;
        i++;
    }
    cout<<ans<<endl;
    return;
}
int main() {

    int Q;
    cin>>Q;
    while(Q--){
        solve();
    }
}