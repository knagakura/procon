#include<iostream>
#include<math.h>

using namespace std;

int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}

int main(){
    int number;
    cout<<"2進数に変換したい10進数の数字を入力して下さい"<<endl;
    cin>>number;
    cout<<"入力した10進数の数値："<<number<<endl;
    cout<<"2進数に変換した数値："<<binary(number)<<endl;
}