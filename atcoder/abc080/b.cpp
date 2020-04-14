#include <bits/stdc++.h>
using namespace std;


int f(int n){
  int res = 0;
  while(n>0){
    res += n%10;
    n /=10;
  }
  return res;
}
int main() {
  int N;
  string ans = "No";
  cin >> N;
  if (N % f(N) ==0){
    ans = "Yes";
  }
  cout << ans << endl;
}