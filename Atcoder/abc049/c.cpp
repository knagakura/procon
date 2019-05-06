#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin>>S;
	int N = S.size();
	bool f = true;
	string T = "";
	int cnt = 0;
	for (int i = N-1; i >= 0; --i){
		T+=S[i];
		cnt = T.size();
		if(cnt == 5){
			if(T == "maerd"||T == "esare"){
				T ="";
			}
			else continue;
		}
		else if(cnt == 6){
			if(T == "resare"){
				T = "";
			}
		}
		else if(cnt == 7){
			if(T == "remaerd"){
				T = "";
			}
			else{
				f = false;
				break;
			}
		}
	}
	string ans = "NO";
	if(f)ans = "YES";
	cout<<ans<<endl;
}