#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> a(N);
    vector<pair<int, ll>> v;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        int cnt = 0;
        ll tmp = a[i];
        while(tmp % 3 == 0){
            tmp /= 3;
            cnt++;
        }
        v.push_back({-cnt, a[i]});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        cout << v[i].second << " ";
    }
    cout << endl;
}