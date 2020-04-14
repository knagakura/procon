#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	string A,B;
	cin>>A>>B;
	string ans="EQUAL";
	if(!(A==B)){
		if(A.size()==B.size()){
			if(A>B)ans="GREATER";
			else ans="LESS";
		}
		else{
			if(A.size()>B.size())ans="GREATER";
			else ans="LESS";
		}
	}
	cout<<ans<<endl;
}