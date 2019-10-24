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
    int N;
    cin>>N;
    string S;
    cin>>S;
    int ans = 0;
    string T = "";
    for(int i = 0; i < N; i+=2){
        if(S[i] == 'a'&&S[i+1]=='b'){
            T.push_back(S[i]);
            T.push_back(S[i+1]);
            continue;
        }
        else if(S[i] == 'b'&&S[i+1] == 'a'){
            T.push_back(S[i]);
            T.push_back(S[i+1]);
            continue;
        }
        else if(S[i] == 'a'&&S[i+1] == 'a'){
            ans++;
            T.push_back('a');
            T.push_back('b');
        }
        else{
            ans++;
            T.push_back('a');
            T.push_back('b');
        }
    }
    cout<<ans<<endl;
    cout<<T<<endl;
}