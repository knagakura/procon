#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define bit(k) (1LL<<(k))
typedef long long ll;

int main() {

    ll M, K;
    cin >> M >> K;
    ll K_max = bit(M) - 1;
    if(K > K_max){
        cout << -1 << endl;
        return 0;
    }
    if(K == 0){
        rep(i,bit(M)){
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }
    if(K == 1 && M == 1){
        cout << -1 << endl;
        return 0;
    }
    // 1 <= K <= Kmax
    deque<int> ans;
    ans.push_back(K);
    for(int i = 1; i < bit(M); i++){
        if(i == K)continue;
        ans.push_back(i);
        ans.push_front(i);
    }
    ans.push_back(0);
    ans.push_back(K);
    ans.push_back(0);
    for(auto a: ans){
        cout << a << " ";
    }
    cout << endl;
}
