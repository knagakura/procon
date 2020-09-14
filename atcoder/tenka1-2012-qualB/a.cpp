#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 1; i <= 127; i++){
        if(i%3 == a && i % 5 == b && i % 7 == c){
            cout << i << endl;
        }
    }
}
