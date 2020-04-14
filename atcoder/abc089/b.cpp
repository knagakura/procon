#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string ans = "Three";
  for (int i = 0; i < N; ++i)
  {
  	string s;
  	cin >> s;
  	if (s == "Y"){
  		ans = "Four";
  	}
  }
  cout << ans << endl;
}