#include <bits/stdc++.h>

using namespace std;

using ll = long long;

//引数unzipには圧縮前のvectorを入れる
int compress(vector<int>& unzip, map<int, int>& zip) {
    sort(unzip.begin(), unzip.end());
    unzip.erase(unique(unzip.begin(), unzip.end()), unzip.end());
    for (int i = 0; i < unzip.size(); i++) {
        zip[unzip[i]] = i;
    }
    return unzip.size();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int case_num;
    cin >> case_num;
    for (int case_id = 1; case_id <= case_num; case_id++) {
        int p, q;
        cin >> p >> q;
        vector<int> x(p), y(p);
        vector<char> d(p);
        for (int i = 0; i < p; i++) {
            cin >> x[i] >> y[i] >> d[i];
            if (d[i] == 'N') {
                y[i]++;
            } else if (d[i] == 'E') {
                x[i]++;
            }
        }

        vector<int> unzip_x = x, unzip_y = y;
        unzip_x.push_back(0);
        unzip_y.push_back(0);
        map<int, int> zip_x, zip_y;
        int sz_x = compress(unzip_x, zip_x);
        int sz_y = compress(unzip_y, zip_y);

        vector< vector<int> > cnt(sz_x + 1, vector<int>(sz_y + 1, 0));
        for (int i = 0; i < p; i++) {
            if (d[i] == 'N') {
                int yi = zip_y[y[i]];
                cnt[0][yi]++;
                cnt[0][sz_y]--;
                cnt[sz_x][yi]--;
                cnt[sz_x][sz_y]++;
            } else if (d[i] == 'S') {
                int yi = zip_y[y[i]];
                cnt[0][0]++;
                cnt[0][yi]--;
                cnt[sz_x][0]--;
                cnt[sz_x][yi]++;               
            } else if (d[i] == 'E') {
                int xi = zip_x[x[i]];
                cnt[xi][0]++;
                cnt[sz_x][0]--;
                cnt[xi][sz_y]--;
                cnt[sz_x][sz_y]++;
            } else {
                int xi = zip_x[x[i]];
                cnt[0][0]++;
                cnt[xi][0]--;
                cnt[0][sz_y]--;
                cnt[xi][sz_y]++;
            }
        }

        for (int i = 0; i < sz_x; i++) {
            for (int j = 1; j < sz_y; j++) {
                cnt[i][j] += cnt[i][j-1];
            }
        }

        for (int i = 1; i < sz_x; i++) {
            for (int j = 0; j < sz_y; j++) {
                cnt[i][j] += cnt[i-1][j];
            }
        }

        int maxv = -1;
        int ansx = -1, ansy = -1;
        for (int i = 0; i < sz_x; i++) {
            for (int j = 0; j < sz_y; j++) {
                if (maxv < cnt[i][j]) {
                    maxv = cnt[i][j];
                    ansx = unzip_x[i];
                    ansy = unzip_y[j];
                }
            }
        }

        cout << "Case #" << case_id << ": " << ansx << " " << ansy << "\n";
    }
    return 0;
}