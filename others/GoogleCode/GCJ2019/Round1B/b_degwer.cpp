#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int d[6];
ll ask(int t)
{
	printf("%d\n", t);
	fflush(stdout);
	ll r = 0;
	scanf("%lld", &r);
	/*for (int i = 0; i < 6; i++)
	{
		if (t / (i + 1)>63)continue;
		r += ((ll)(d[i])) << (t / (i + 1));
	}*/
	return r;
}
int main()
{
	int data,gen;
	scanf("%d%d", &data, &gen);
	for (int p = 1; p <= data; p++)
	{
	//	for (int i = 0; i < 6; i++)scanf("%d", &d[i]);
		ll r1 = ask(55);
		ll r2 = ask(168);
		ll a1 = r1 >> 55;
		r1 -= a1 << 55;
		ll a2 = r1 >> 27;
		r1 -= a2 << 27;
		ll a3 = r2 >> 56;
		r1 -= a3 << 18;
		r2 -= a3 << 56;
		ll a4 = r2 >> 42;
		r1 -= a4 << 13;
		r2 -= a4 << 42;
		ll a5, a6;
		for (ll i = 0; i <= 100; i++)for (ll j = 0; j <= 100; j++)if (((i << 11) + (j << 9) == r1) && ((i << 33) + (j << 28) == r2))a5 = i, a6 = j;
		printf("%lld %lld %lld %lld %lld %lld\n", a1, a2, a3, a4, a5, a6);
		fflush(stdout);
		int z;
		scanf("%d", &z);
		if (z == -1)return 0;
	}
}