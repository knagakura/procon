#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, ans;
  cin >> A >> B;
  ans = A;
  if (A.size() < B.size()){
  	ans = B;
  }
  cout <<  ans << endl;
}