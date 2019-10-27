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
    cout << fixed << setprecision(20);
    int Q;
    cin>>Q;
    //逆からみる
    while(Q--){
        int a,b,c;
        cin>>a>>b>>c;
        int a2 = a;
        int cnt1 = 1;
        while(a>0){
            //cerr<<a<<endl;
            if(a%c == 0){
                a /= c;
            }
            else{
                a -= a%c;
            }
            cnt1++;
        }
        //cerr<<a<<endl;
        cerr<<cnt1<<endl;
        ll x =  1;
        while(a2>x*c){
            x *= c;
        }
        cerr<<x<<endl;
    }
}