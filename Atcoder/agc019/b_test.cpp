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
    string A;
    cin>>A;
    int N = A.size();
    map<char, int> map;
    for(int i = 0; i < N; ++i){
        map[A[i]]++;
    }
    int cnt =  1;
    vs vt;
    for(int i = 0; i < N; ++i){
        char ai =  A[i];
        for(int j = i+1; j < N; ++j){
            string T = A;
            char tj =  T[j];
            if(ai!=tj){
                T[j] = ai;
                T[i] = tj;
                cerr<<T<<endl;
                vt.push_back(T);
                cnt++;
            }
        }
    }
    sort(all(vt));
    print(vt);
    cerr<<vt.size()<<endl;
    cerr<<cnt<<endl;
}