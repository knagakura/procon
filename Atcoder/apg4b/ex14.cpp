#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int x,n;
  x = max(max(A, B) , C);
  n = min(min(A, B), C);
  cout << x - n << endl;
}
