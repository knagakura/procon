#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
    int a[4];
    rep(i,4)cin >> a[i];
    if(a[0] < a[1] && a[2] > a[3]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
