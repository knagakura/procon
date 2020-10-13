#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int N;
vec<string> S;
vvec<string> A;
string match(vector<string>& B){
    string maxst = "";
    rep(i,B.size()){
        if(maxst.size() < B[i].size()){
            maxst = B[i];
        }
    }
    bool ok = true;
    rep(j, maxst.size()){
        rep(i,N){
            if(j >= (int)B[i].size())continue;
            if(maxst[j] != B[i][j])ok = false;
        }
    }
    return ok ? maxst: "-";
}

void Case(int t){
    cout << "Case #" << t << ": ";
}
void input(){
    cin >> N;
    S.resize(N);
    A.assign(N, vec<string>());
    rep(i,N){
        cin >> S[i];
        S[i].push_back('*');
    }
}
void solve(){
    input();
    string ans[3] = {"", "", ""};
    rep(i,N){
        string tmp = "";
        for(auto c: S[i]){
            if(c == '*'){
                A[i].push_back(tmp);
                tmp = "";
            }
            else tmp.push_back(c);
        }
    }
    //prefix
    {
        vector<string> x;
        rep(i,N)x.push_back(A[i].front());
        ans[0] = match(x);
    }
    //suffix 
    {
        vector<string> x;
        rep(i,N)x.push_back(A[i].back());
        rep(i,N)reverse(all(x[i]));
        ans[2] = match(x);
        reverse(all(ans[2]));
    }
    //middle
    {
        rep(i,N){
            for(int j = 1; j < (int)A[i].size()-1;j++){
                for(auto &c: A[i][j]){
                    ans[1].push_back(c);
                }
            }
        }
    }
    if(ans[0] == "-"|| ans[2] == "-"){
        cout << "*" << endl;
    }
    else{
        cout << ans[0] << ans[1] << ans[2] << endl;
    }
}
int main() {
    
    int t;
    cin >> t;
    rep1(i, t+1){
        Case(i);
        solve();
    }
}