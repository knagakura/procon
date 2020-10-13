#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    int N, H;
    cin >> N >> H;
    rep(i, N){
        int a;
        cin >> a;
        a += H;
        cout << a << " ";
    }
    cout << endl;

}
