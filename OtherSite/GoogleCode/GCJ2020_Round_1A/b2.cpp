#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

void solve(){
    ll N;
    cin >> N;
    if(N <= 500){
        rep1(i,N+1){
            cout << i << " " << 1 << endl;
        }
        return;
    }
    ll tmpN = N - 34;
    ll sum = 0;
    int r = 0;
    vector<pair<int, int>> ans;
    ans.push_back({0,0});
    sum++;
    tmpN--;
    for(int i = 1; i <= 29;i++){
        //i行目を走査するかどうかを決める
        if(bit(i) & tmpN){
            sum += bit(i);
            //今左側にいる
            if(r == 0){
                for(int j = 0;j <= i;j++){
                    ans.push_back({i, j});
                }
                r = 1;
            }
            else{
                for(int j = i; j>= 0;j--){
                    ans.push_back({i, j});
                }
                r = 0;
            }
        }
        else{
            sum++;
            if(r == 0){
                ans.push_back({i, 0});
            }
            else{
                ans.push_back({i, i});
            }
        }
    }
    cerr << N <<" "<< sum << endl;
    while(N - sum > 0){
        auto tmp = ans.back();
        if(tmp.second == 0){
            ans.push_back({tmp.first+1, 0});
        }
        else if(tmp.first == tmp.second){
            ans.push_back({tmp.first+1, tmp.second+1});
        }
        sum++;
    }
    cerr << ans.size() << endl;
    for(auto& p: ans){
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}
int main() {
    int t;
    cin >> t;
    rep1(i, t+1){
        cout << "Case #" << i << ":" << endl;
        solve();
    }
}