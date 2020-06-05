#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

void solve() {
    string _sx, _sy, _gx, _gy;
    cin >> _sx >> _sy >> _gx >> _gy;
    __int128 sx,sy,gx,gy;
    sx = parse(_sx);
    sy = parse(_sy);
    gx = parse(_gx);
    gy = parse(_gy);
    auto ret = [&](__int128 i, __int128 j) {
        __int128 syoko = 1 + (j - 1) * j / 2;
        __int128 res = syoko * i;
        res += (j + 1) * (i - 1) * i / 2;
        __int128 tmp = (i * (i + 1) * (2 * i + 1) / 6) - 3 * i * (i + 1) / 2 + 2 * i;
        tmp /= 2;
        res += tmp;
        return res;
    };
    auto gyo = [&](__int128 i, __int128 j) {
        __int128 syoko = i * (i + 1) / 2;
        __int128 res = syoko * j;
        res += i * (j - 1) * j / 2;
        __int128 tmp = (j * (j + 1) * (2 * j + 1) / 6) - 3 * j * (j + 1) / 2 + 2 * j;
        tmp /= 2;
        res += tmp;
        return res;
    };

    __int128 l = gyo(sx, gy-1) - gyo(sx, sy - 1);//
    l += ret(gx, gy) - ret(sx - 1, gy);//
    __int128 r = gyo(gx, gy) - gyo(gx, sy - 1);
    r += ret(gx-1, sy) - ret(sx-1, sy);
    cout << r - l + 1 << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while (t--) solve();
}