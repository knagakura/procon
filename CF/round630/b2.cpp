#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

int primes[] = {2,3,5,7,11,13,17,19,23,29,31};

void solve(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    vector<int> ans(N);
    vector<bool> ok(N, false);
    int cnt = 1;
    bool used = false;
    for(int i = 0;i < 11;i++){
        used = false;
        rep(j,N){
            if(ok[j])continue;
            if(a[j] % primes[i]== 0){
                ans[j] = cnt;
                used = true;
                ok[j] = true;
            }
        }
        if(used)cnt++;
    }
    cout << *max_element(all(ans))<<endl;
    rep(i,N)cout <<ans[i] <<" ";
    cout <<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}