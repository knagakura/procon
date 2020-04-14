#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,K;
    cin>>N>>K;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    //print(A);
    vector<ll> ans;
    auto check = [&](ll X){
        ll res = 0;
        rep(i,N){
            if(A[i] == 0){
                ll cnt = 0;
                if(X > 0)cnt += N-1;
                //cerr<<A[i]<<" "<<cnt<<endl;
                res += cnt;
                continue;
            }
            ll aite = X / A[i];
            if(A[i] < 0){
                //aite以上のものを調べる
                ll cnt = A.end() -lower_bound(all(A), aite);
                int low_idx = N - cnt;
                //cerr<<"low_idx: "<<low_idx<<endl;
                if(low_idx <= i)cnt--;
                //cerr<<A[i]<<" "<<cnt<<endl;
                res += cnt;
            }
            else if(A[i] > 0){
                //aite以下のものを調べる
                ll cnt = upper_bound(all(A), aite) - A.begin();
                int high_idx = cnt - 1;
                //cerr<<"high_idx: "<<high_idx<<endl;
                if(i<=high_idx)cnt--;
                //cerr<<A[i]<<" "<<cnt<<endl;
                res += cnt;
            }
        }
        cerr<<X<<"の時 "<<res/2<<"個"<<endl;
        return res/2 >= K-1;
    };
    //積がX未満の数がK個以上かどうかの判定
    ll ok = 1e18;
    ll ng = -1e18;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        //cerr<<ok<<" "<<ng<<" "<<mid<<endl;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    /*
    auto warizan = [&](ll X){
        rep(i,N){
            if(A[i] == 0){
                if(X == 0)return true;
                continue;
            }
            if(abs(X) % abs(A[i]) == 0){
                if(*lower_bound(all(A), X/A[i]) == X/A[i]){
                    return true;
                }
            }
        }
        return false;
    };*/
    /*
    while(true){
        if(warizan(ok)){
             break;
        }
        ok++;
    }*/
    cerr<<ng<<" "<<ok<<endl;
    cout<<ok<<endl;
    /*
    check(-7);
    check(-6);
    check(-5);
    check(-4);
    check(0);
    check(100);
    check(1e9);*/
}