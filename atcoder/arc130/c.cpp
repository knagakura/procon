#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for(int i = 0; i < int(N); ++i)
#define rep1(i, N) for(int i = 1; i < int(N); ++i)
#define all(a) (a).begin(), (a).end()
#define bit(k) (1LL << (k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios {
    fast_ios() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for(T &x : vec)
        is >> x;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(auto _ : v)
        os << _ << ", ";
    os << "]";
    return os;
};
template <typename T> ostream &operator<<(ostream &os, set<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp) {
    os << "[";
    for(auto _ : mp) {
        os << _ << ", ";
    }
    os << "]";
    return os;
}

#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
    DUMPOUT << head;
    if(sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#ifdef DEBUG
#define dbg(...)                                                               \
    { dump_func(__VA_ARGS__) }
#define dump(...)                                                              \
    DUMPOUT << string(#__VA_ARGS__) << ": ";                                   \
    dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18 + 1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

uint32_t XorShift(void) {
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

char getDigit() { return char(XorShift() % 9 + 1 + '0'); }

ll calc_val(string re) {
    ll res = 0;
    for(auto c : re) {
        res += c - '0';
    }
    return res;
}

string get_random_string(int max_length = 9) {
    int size = XorShift() % max_length;
    string res;
    rep(i, size) { res.push_back(getDigit()); }
    return res;
}

ll random_test(string &a, string &b) {
    sort(all(a));
    sort(all(b));
    ll minimum_val = INFLL;
    do {
        do {
            string ta = a;
            string tb = b;
            if(ta.size() > tb.size()) {
                swap(ta, tb);
            }
            reverse(all(ta));
            reverse(all(tb));
            int min_sz = min(ta.size(), tb.size());
            int max_sz = max(ta.size(), tb.size());
            bool kuri = false;
            string tr;
            rep(i, min_sz) {
                int val = ta[i] - '0' + tb[i] - '0';
                if(kuri) {
                    val++;
                }
                tr.push_back(char('0' + val % 10));
                if(val > 9) {
                    kuri = true;
                } else {
                    kuri = false;
                }
            }
            for(int i = min_sz; i < max_sz; i++) {
                int val = tb[i] - '0';
                if(kuri) {
                    val++;
                }
                tr.push_back(char('0' + val % 10));
                if(val > 9) {
                    kuri = true;
                } else {
                    kuri = false;
                }
            }
            if(kuri) {
                tr.push_back('1');
            }
            string re = tr;
            reverse(all(re));
            // assert(stoll(a) + stoll(b) == stoll(re));
            ll val = calc_val(re);
            if(chmin(minimum_val, val)) {
                dump(val, "-----------");
            }
            // if(minimum_val == val) {
            dump(val);
            dump(ta);
            dump(tb);
            dump(tr);
            // }
        } while(next_permutation(all(b)));
    } while(next_permutation(all(a)));
    return minimum_val;
}

int main() {
    string a, b;
    cin >> a >> b;
    bool swapped = false;
    if(a.size() > b.size()) {
        swap(a, b);
        swapped = true;
    }
    int sza = a.size();
    int szb = b.size();
    map<int, int> mpa, mpb;
    for(const auto &c : a) {
        mpa[c - '0']++;
    }
    for(const auto &c : b) {
        mpb[c - '0']++;
    }
    vector<int> ansa(sza, -1), ansb(szb, -1);
    int idx = min(sza, szb) - 1;
    dump(mpa, mpb);
    // 足して9になるペアはまとめる
    for(int c = 2; c <= 4; c++) {
        // {2, 8}
        int s = c;
        int t = 9 - c;
        rep(_, 2){
            int minsz = min(mpa[s], mpb[t]);
            rep(_, minsz) {
                ansa[idx] = s;
                ansb[idx] = t;
                idx--;
            }
            mpa[s] = mpa[s] - minsz;
            mpb[t] = mpb[t] - minsz;
            if(s == t){
                break;
            }
            swap(s, t);
        }
    }
    dump(ansa);
    dump(ansb);
    dump(mpa, mpb);
    // 2以上で足して10になるペアはまとめる
    for(int c = 1; c <= 4; c++) {
        // {2, 8}
        int s = c;
        int t = 10 - c;
        rep(_, 2){
            int minsz = min(mpa[s], mpb[t]);
            rep(_, minsz) {
                ansa[idx] = s;
                ansb[idx] = t;
                idx--;
            }
            mpa[s] = mpa[s] - minsz;
            mpb[t] = mpb[t] - minsz;
            if(s == t){
                break;
            }
            swap(s, t);
        }
    }
    dump(ansa);
    dump(ansb);
    dump(mpa, mpb);

    if(swapped) {
        swap(ansa, ansb);
    }
    reverse(all(ansa));
    reverse(all(ansb));
    for(auto aa: ansa){
        cout << aa;
    }
    cout << endl;
    for(auto bb: ansb){
        cout << bb;
    }
    cout << endl;
}
