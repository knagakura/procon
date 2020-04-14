#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int c;
  c = 1;
  for (int i = 0; i < S.size(); ++i)
  {
  	if (S.at(i) == '+'){
  		c += 1;
  	}

  	else if (S.at(i) == '-'){
  		c -= 1;
  	}
  }
	
  cout << c << endl;
}
