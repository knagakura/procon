#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v).begin(), (v).end()
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define DEBUG
#define int long long
#define INF 1e18
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<"\n";}
typedef long long ll;

int f(int num){
    int cnt = 0;
    while (num > 0)
    {
        num /= 2;
        cnt++;
    }
    return cnt;
}
int tt;
int T;
int solve()
{
    int xx, yy;
    cin >> xx >> yy;
    int x = abs(xx);
    int y = abs(yy);
   // vector<int> x1(30), x2(30), y1(30), y2(30);
    int a = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (a >= x)
        {
            break;
        }
        else
        {
            a *= 2;
        }
    }
    int X = a - x;
    X += a;
    if(x==0){
        X = 0;
    }
    int b = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (b >= y)
        {
            break;
        }
        else
        {
            b *= 2;
        }
    }
    int Y = b  - y;
    Y += b;
    if(y==0){
        Y = 0;
    }
  //  cerr << X << " " << Y << endl;
    int ss = f(x);
    int t = f(y);
    string s, u, v, z;
    if (x + y == (1 << (max(ss, t))) - 1)
    {
        
        //cerr << "a";
        for (int i = 0; i < max(ss, t) ; i++)
        {
            if ((1 << i) & x)
            {
                s.push_back('E');
            }
            else
            {
                s.push_back('N');
            }
        }
        if (xx < 0)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'E')
                {
                    s[i] = 'W';
                }
                else if (s[i] == 'W')
                {
                    s[i] = 'E';
                }
            }
        }
        if (yy < 0)
        {
           // cerr << "aa";
            for (int i = 0; i < s.size(); i++)
            {
               // cerr << s[i];
                if (s[i] == 'N')
                {
                    s[i] = 'S';
                }
                else if (s[i] == 'S')
                {
                    s[i] = 'N';
                }
                //cerr << s[i];
            }
        }
       // cerr << s << endl;
    }
     ss = f(x);
     t = f(Y);
    if (x + Y == (1 << (max(ss, t))) - 1)
    {
      //  cerr << "b";
        for (int i = 0; i < max(ss, t); i++)
        {
            if ((1 << i) & x)
            {
                u.push_back('E');
            }
            else
            {
                if (i == t - 1)
                {
                    u.push_back('N');
                }
                else
                {
                    u.push_back('S');
                }
            }
        }
        if(xx<0){
            for (int i = 0; i < u.size(); i++)
            {
                if(u[i]=='E'){
                    u[i] = 'W';
                }
                else if(u[i]=='W'){
                    u[i] = 'E';
                }
            }
            
        }
        if (yy < 0)
        {
            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == 'N')
                {
                    u[i] = 'S';
                }
                else if (u[i] == 'S')
                {
                    u[i] = 'N';
                }
            }
        }
    }
    ss = f(X);
    t = f(y);
    if (X + y == (1 << max(ss, t)) - 1)
    {
      //  cerr << "c";
        for (int i = 0; i < max(ss, t); i++)
        {
            if ((1 << i) & X)
            {
                if (i == ss - 1)
                {
                    v.push_back('E');
                }
                else
                {
                    v.push_back('W');
                }
            }
            else
            {
                v.push_back('N');
            }
        }
        if (xx < 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == 'E')
                {
                    v[i] = 'W';
                }
                else if (v[i] == 'W')
                {
                    v[i] = 'E';
                }
            }
        }
        if (yy < 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == 'N')
                {
                    v[i] = 'S';
                }
                else if (v[i] == 'S')
                {
                    v[i] = 'N';
                }
            }
        }
        

    }
    ss = f(X);
    t = f(Y);
    if (X + Y == (1 << max(ss, t)) - 1)
    {
     //   cerr << "d";
        for (int i = 0; i < max(ss, t); i++)
        {
            if ((1 << i) & X)
            {
                if (i == ss - 1)
                    z.push_back('E');
                else
                {
                    z.push_back('W');
                }
            }
            else
            {
                if (i == t - 1)
                {
                    z.push_back('N');
                }
                else
                {
                    z.push_back('S');
                }
            }
        }
        //cerr << s;
        if (xx < 0)
        {
            for (int i = 0; i < z.size(); i++)
            {
                if (z[i] == 'E')
                {
                    z[i] = 'W';
                }
                else if (z[i] == 'W')
                {
                    z[i] = 'E';
                }
            }
        }
        if (yy < 0)
        {
            for (int i = 0; i < z.size(); i++)
            {
                if (z[i] == 'N')
                {
                    z[i] = 'S';
                }
                else if (z[i] == 'S')
                {
                    z[i] = 'N';
                }
            }
        }

    }
   // cerr << s << " " << u << " " << v << " " << z << endl;
    vector<pair<int, string>> c;
    c.push_back(make_pair((int)s.size(),s));
    c.push_back(make_pair((int)u.size(),u));
    c.push_back(make_pair((int)v.size(),v));
    c.push_back(make_pair((int)z.size(),z));
    sort(ALL(c));
    for (int i = 0; i < 4; i++)
    {
        if(c[i].first!=0){
            cout << "Case #" << tt - T << ": " << c[i].second << endl;
            return 0;
        }
    }
    

    
    cout << "Case #" <<tt-T<< ": " <<"IMPOSSIBLE"<< endl;
}

signed main()
{
    cin >> T;
    tt = T;
    while (T--)
    {

        solve();
    }
    return 0;
}