#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  int i = 0;

  for(;i < N;){
	int B;
	string s;
	cin >> s >> B;
	if (s == '+'){
		A += B;
		cout << i + 1 << ':' << A << endl;
	}
	else if (s == '-'){
		A -= B;
		cout << i + 1 << ':' << A << endl;
	}
	else if (s == '*'){
		A *= B;
		cout << i + 1 << ':' << A << endl;
	}
	else if (s == '/'){
		if (B == 0){
			cout << "error" << endl;
			break;
		}
		else if (B != 0){
			A /= B;
			cout << i + 1 << ':' << A << endl;
		}
	}
	i++;
}
}