#include <bits/stdc++.h>
using namespace std;

vector<string> S(3);
int turn_n;
char next_turn;

int solve(char turn){
	turn_n=turn-'a';
	if(S[turn_n].size()==0){
		cout<<char(turn+'A'-'a')<<endl;
		return 0;
	}
	next_turn = S[turn_n][0];
	S[turn_n].erase(S[turn_n].begin());
	solve(next_turn);
}
int main() {
	cin>>S[0]>>S[1]>>S[2];
	solve(S[0][0]);
}