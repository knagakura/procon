#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int H,W,K;
vector<string> s;
int ans[324][324];
/*------------------------------------/
for library*/
void debug(){
    cerr<<endl;
    rep(i,H){
        cout<<s[i]<<endl;
    }
}
void debug_ans(){
    cerr<<endl;
    rep(i,H)rep(j,W){
        cerr<<ans[i][j];
        if(j == W-1)cerr<<endl;
        else cerr<<" ";
    }
    cerr<<endl;
}

void out_ans(){
    rep(i,H)rep(j,W){
        cout<<ans[i][j];
        if(j == W-1)cout<<endl;
        else cout<<" ";
    }
}
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}


/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>H>>W>>K;
    s.resize(H);
    rep(i,H){
        cin>>s[i];
    }
    vector<bool> kara(H,false);
    rep(i,H){
        int cnt = 0;
        rep(j,W){
            if(s[i][j] == '#')cnt++;
        }
        if(cnt == 0){
            kara[i] = true;
        }
    }
    //debug();
    int cnt = 0;
    rep(i,H)rep(j,W){
        if(s[i][j] == '#'){
            cnt++;
            ans[i][j] = cnt;
            for(int k = j+1;k<W;k++){
                if(s[i][k] == '.'){
                    ans[i][k] = cnt;
                }
                else{
                    break;
                }
            }
        }
    }
    //debug_ans();
    rep(i,H){
        for(int j = W-1;j >= 0;j--){
            if(ans[i][j] == 0){
                if(ans[i][j+1] == 0)continue;
                ans[i][j] = ans[i][j+1];
            }
        }
    }
    //debug_ans();;

    rep(i,H){
        if(kara[i]&&!kara[i+1]){
            while(i >= 0 && kara[i]){
                rep(j,W){
                    ans[i][j] = ans[i+1][j];
                }
                kara[i] = false;
                i--;
            }
        }
    }
    //debug_ans();
    rep(i,H)kara[i] = false;
    rep(i,H){
        rep(j,W){
            if(ans[i][j] == 0)kara[i] = true;
        }
    }
    rep1(i,H){
        if(!kara[i-1]&&kara[i]){
            while(i < H && kara[i]){
                rep(j,W){
                    ans[i][j] = ans[i-1][j];
                }
                kara[i] = false;
                i++;
            }
        }
    }
    //debug_ans();
    out_ans();
}