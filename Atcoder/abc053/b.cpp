#include <bits/stdc++.h>
using namespace std;

int main() {
	int a = -1;
	int b;
	string s;
	cin >> s;
	int N = s.size();
	for (int i = 0; i < N; ++i){
		if(s[i] == 'A' and a == -1){
			a = i;
		}
		else if (s[i]=='Z')
		{
			b = i;
		}
	}
	cout << b-a+1 << endl;
}