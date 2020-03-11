#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long MAX = 5100000;
const long long INF = 1LL << 60;
//const long long mod = 1000000007LL;
//const long long mod = 998244353LL;

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll x, ll y)
{
	ll r;
	if (x < y) {
		swap(x, y);
	}
	while (y > 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}
map<ll, ll> prime_factor(ll a) {
	map<ll, ll> ret;
	for (ll i = 2; i * i <= a; i++) {
		while (a % i == 0 && a != 0) {
			ret[i]++;
			a /= i;
		}
	}
	if (a != 1) {
		ret[a]++;
	}
	return ret;
}
ll lcm(ll a, ll b) {
	if (a == 0 && b == 0) return 0;
	return a / gcd(a, b) * b;
}
int main()
{
	/*
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	*/
	ll T; cin >> T;
	while (T--) {
		ll a, m; scanf("%lld %lld", &a, &m);
		ll g = gcd(a, m);
		a /= g;
		m /= g;
		if (m == 1) {
			cout << "1" << "\n";
		}
		else {
            
			map<ll, ll> mp = prime_factor(m);
			vector<ll> v;
			ll res = 0;
			for (auto p : mp) {
				v.push_back(p.first);
			}
			ll sz = v.size();
			for (ll S = 0; S < (1 << sz); S++) {
				ll cnt = 0;
				for (ll i = 0; i < sz; i++) if (S >> i & 1)cnt++;
				ll lc = 1;
				for (ll i = 0; i < sz; i++) if (S >> i & 1) lc = lcm(lc, v[i]);
				if (cnt & 1) res -= (a + m - 1) / lc - (a - 1) / lc;
				else res += (a + m - 1) / lc - (a - 1) / lc;
			}
			cout << res << "\n";
		}
	}

	return 0;
}
