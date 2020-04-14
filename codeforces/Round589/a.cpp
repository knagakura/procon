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
    int l,r;
    cin>>l>>r;
    for(int x = l; x <= r; ++x){
        int cnt[10]={};
        string s = to_string(x);
        bool flag = true;
        rep(i,(int)s.size()){
            if(cnt[s[i]-'0']>0){
                flag = false;
            }
            cnt[s[i]-'0']++;
        }
        if(flag){
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}