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
    string S,T;
    cin>>S>>T;
    vector<string> A;
    int N = S.size();
    int M = T.size();
    for(int i = 0; i+M-1 < N; ++i){
        //iが始まりで、そこから含まれているとすることができるか
        string x = "";
        bool flag = true;
        rep(j,N){
            if(i<=j&&j<i+M){
                if(S[j] == T[j-i]){
                    x.push_back(S[j]);
                }
                else if(S[j] == '?'){
                    x.push_back(T[j-i]);
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                if(S[j] == '?'){
                    x.push_back('a');
                }
                else{
                    x.push_back(S[j]);
                }
            }
        }
        if(flag){
            A.push_back(x);
        }
    }
    sort(all(A));
    //print(A);
    if(A.size()){
        cout<<A[0]<<endl;
    }
    else{
        cout<<"UNRESTORABLE"<<endl;
    }
}