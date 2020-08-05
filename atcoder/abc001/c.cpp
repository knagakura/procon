#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int a,b;
	cin >> a >> b;
	a *= 10;
	string x;
	if(a<1125)x = "N";
	else if(a<3375) x = "NNE";
	else if(a<5625) x = "NE";
	else if(a<7875) x = "ENE";
	else if(a<10125) x = "E";
	else if(a<12375) x = "ESE";
	else if(a<14625) x = "SE";
	else if(a<16875) x = "SSE";
	else if(a<19125) x = "S";
	else if(a<21375) x = "SSW";
	else if(a<23625) x = "SW";
	else if(a<25875) x = "WSW";
	else if(a<28125) x = "W";
	else if(a<30375) x = "WNW";
	else if(a<32625) x = "NW";
	else if(a<34875) x = "NNW";
	else  x = "N";
	

	int y;
	if(b<15)y = 0;
	else if(b<93)y=1;
	else if(b<201)y=2;
	else if(b<327)y=3;
	else if(b<477)y=4;
	else if(b<645)y=5;
	else if(b<831)y=6;
	else if(b<1029)y=7;
	else if(b<1245)y=8;
	else if(b<1467)y=9;
	else if(b<1707)y=10;
	else if(b<1959)y=11;
	else y=12;
	if(y==0)x = "C";
	cout<< x << ' ' << y << endl;
	
	

}
