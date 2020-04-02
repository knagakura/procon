#include <iostream>
using namespace std;

bool isin(int s, int l, int r){
    return l <= s && s <= r;
}

bool check(int a, int b, int sx, int x1, int x2){
    if(a == b){
        return a == 0 || isin(sx + 1, x1, x2) || isin(sx - 1, x1, x2);
    }
    return isin(sx + b - a, x1, x2);
}
bool solve(){
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    return check(a, b, x, x1, x2) && check(c, d, y, y1, y2);
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << (solve() ? "Yes" : "No") << endl;
    }
}