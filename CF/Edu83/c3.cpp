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
int N,K;
void solve(){
    cin>>N>>K;
    vector<ll> a(N);
    vector<bool> ans(N, false);
    rep(i,N){
        cin>>a[i];
        if(a[i] == 0)ans[i] = true;
    }
    int cnt1 = 0;
    rep(i,N){
        if((a[i] % K) != 1 && (a[i] % K) != 0){
            cout<<NO<<endl;
            return;
        }
        else if(a[i] % K == 1){
            cnt1++;
        }
    }
    if(cnt1 > 1){
        cout<<NO<<endl;
        return;
    }
    //1 mod Kが一個だけ
    //他はすべて 0 mod K;
    //K^x のxを格納するリスト
    vector<int> list;
    rep(i,N){
        if(a[i] % K == 1){
            a[i]-= 1;
            list.push_back(0);
        }
        int cnt = 0;
        while(a[i]>1){
            //cerr<<a[i]<<endl;
            while(a[i] % K == 0 && a[i] > 1){
                //cerr<<a[i]<<endl;
                cnt++;
                a[i] /= K;
            }
            list.push_back(cnt);
            if(a[i] == 1)break;
            else if(a[i] % K == 1){
                a[i]-=1;
                continue;
            }
            else{
                cout<<NO<<endl;
                return;
            }
        }
    }
    //print(list);
    set<int> s;
    rep(i,list.size()){
        s.insert(list[i]);
    }
    if(s.size() == list.size()){
        cout<<YES<<endl;
    }
    else cout<<NO<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}