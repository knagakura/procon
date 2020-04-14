#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  string op;
  cin >> a >> op >> b;
  int ans;

  if (op == "+"){
  	ans = a + b;
  }

  if (op == "-"){
  	ans = a - b;
  }
  cout << ans << endl;
}
