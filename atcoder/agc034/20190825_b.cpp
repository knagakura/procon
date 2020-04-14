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
    string s;
    cin>>s;
    int N = s.size();
    s.push_back('.');
    string T = "";
    rep(i,N){
        if(s[i] == 'A')T.push_back('A');
        else if(s[i] == 'B'){
            if(s[i+1] == 'C'){
                T.push_back('D');
                i++;
            }
            else{
                T.push_back('X');
            }
        }
        else{
            T.push_back('X');
        }
    }
    cerr<<T<<endl;
    ll ans = 0;
    ll cnta = 0;
    for (int i = 0; i < int(T.size()); i++){
        if(T[i] == 'A')cnta++;
        else if(T[i] == 'D'){
            ans += cnta;
        }
        else{
            cnta = 0;
        }
    }
    cout<<ans<<endl;

}