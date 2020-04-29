#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        if(S[i] == 'o')v.emplace_back(i);
    }
    //前から見たときのやつ
    vector<int> mae(K);
    int sz = v.size();
    int cnt = 0;
    for(int l = 0; l < sz;){
        int r = l+1;
        while(r < sz && v[l] + C + 1 >  v[r]){
            r++;
        }
        mae[cnt] = v[l];
        cnt++;
        if(cnt == K)break;
        l = r;
    }
    vector<int> usi(K);
    cnt = K - 1;
    for(int r = sz-1; r >= 0;){
        int l = r - 1;
        while(l >= 0 && v[l] > v[r] - C - 1){
            l--;
        }
        usi[cnt] = v[r];
        cnt--;
        if(cnt == -1)break;
        r = l;
    }
    for (int i = 0; i < K; ++i) {
        if(mae[i] == usi[i]){
            cout << mae[i]+1 << endl;
        }
    }
}