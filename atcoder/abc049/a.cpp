#include <bits/stdc++.h>
using namespace std;

int main() {
  string c;
  cin >> c;
  string ans = "consonant";
  if (c == "a" or c == "e" or c == "i" or c == "o" or c == "u"){
    ans ="vowel";
  }
  cout << ans << endl;
}