#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int main() {
    int N;
    cin>>N;
    vector<ll> x(N),y(N),h(N);
    int id = 0;
    for(int i = 0; i < N; ++i){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]>0){
            id = i;
        }
    }

    for(int a = 0; a <= 100; ++a){
        for(int b = 0; b <= 100; ++b){
            bool AllOK = true;
            ll H = h[id] + abs(a - x[id]) + abs(b - y[id]);
            for(int i = 0; i < N; ++i){
                ll nowH = max(ll(0),H - abs(a-x[i]) - abs(b-y[i]));
                if(nowH != h[i]){
                    AllOK = false;
                }
            }
            if(AllOK){
                cout<<a<<" "<<b<<" "<<H<<endl;
                return 0;
            }
        }
    }
}