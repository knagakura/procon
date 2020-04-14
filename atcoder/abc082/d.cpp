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

bool dp1[8888][8888 * 2];
bool dp2[8888][8888 * 2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string s;
    int x,y;
    cin>>s>>x>>y;
    int N = s.size();
    vector<int> v;
    int cnt = 0;
    rep(i,N){
        if(s[i] == 'F')cnt++;
        else{
            v.push_back(cnt);
            cnt = 0;
        }
    }
    v.push_back(cnt);
    //print(v);
    vector<int> dx;
    vector<int> dy;
    rep(i,v.size()){
        if(i % 2 == 0)dx.push_back(v[i]);
        else dy.push_back(v[i]);
    }

    print(v);
    print(dx);
    print(dy);



    rep(i,8888)rep(j,8888 * 2){
        dp1[i][j] = false;
        dp2[i][j] = false;
    }
    int base = 8005;
    dp1[0][base] = true;
    dp2[0][base] = true;
    bool first_flag = (s[0] == 'F');
    rep(i, (int)dx.size()){
        rep(j, base * 2){
            if(dp1[i][j]){
                if(i == 0){
                    dp1[i+1][j + dx[i]] = true;
                    if(!first_flag)dp1[i+1][j-dx[i]] = true;
                }
                else{
                    dp1[i+1][j + dx[i]] = true;
                    dp1[i+1][j - dx[i]] = true;
                }
            }
        }
    }
    rep(i, (int)dy.size()){
        rep(j, base * 2){
            if(dp2[i][j]){
                dp2[i+1][j + dy[i]] = true;
                dp2[i+1][j - dy[i]] = true;
            }
        }
    }
    if(dp1[(int)dx.size()][base + x] && dp2[(int)dy.size()][base + y]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}