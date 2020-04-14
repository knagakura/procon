#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, ans;
  cin >> S;
  ans = "NO";
  if (S.at(S.size() - 1) == 'T'){
    ans = "YES";
  }
  cout <<  ans << endl;
}