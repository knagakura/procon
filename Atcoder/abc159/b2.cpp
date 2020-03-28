#include <bits/stdc++.h>
using namespace std;

bool pal(string s){
    return s == string(s.rbegin(), s.rend());
}
int main() {

    string S;
    cin >> S;
    int N = S.size();
    if(pal(S) && pal(S.substr(0, (N-1)/2)) && pal(S.substr((N+3)/2-1))){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}