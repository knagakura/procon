#include <bits/stdc++.h>
using namespace std;

void SuperFizzBuzz(int x){
    for(int n = 1; n <= x;n++){
        bool f = true;
        for(int i = 2;i <= 6; ++i){
            if(n % i == 0){
                cout<<char('a'+i-2);
                f = false;
            }
        }
        if(f)cout<<n<<endl;
        else cout<<endl;
    }

}
int main() {
    int N;
    cin>>N;
    SuperFizzBuzz(N);
}