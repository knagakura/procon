#pragma GCC optimize ("O3")
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sys/time.h>

#define SIZE 5005

const int M = 1 << 29;
const double eps = 1e-9;

int dist[SIZE][SIZE] = {};

inline unsigned int randxor() {
    static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned int t = (x ^ (x << 11));
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

void copy(int n, int a[][2], int b[][2]) {
    int i;
    for (i = 0; i < n; ++i) {
        b[i][0] = a[i][0];
        b[i][1] = a[i][1];
    }
}

void output(int n, int edge[][2]) {
    int now = 0, i;
    for (i = 0; i < n; ++i) {
        printf("%d%c", now, i < n - 1 ? ' ' : '\n');
        now = edge[now][1];
    }
}

inline long long get_millisec() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (long long)now.tv_sec * 1000000 + now.tv_usec;
}

double fill_dist(int n, double p[][2]) {
    int i, j;
    double sum = 0;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            dist[i][j] = dist[j][i] = (int)(sqrt((p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1])) + 0.5 + eps);
            sum += dist[i][j];
        }
    }
    return sum * 2 / n / (n - 1);
}

double dot(double a[], double b[]) {
    return a[0] * b[0] + a[1] * b[1];
}
double cross(double a[], double b[]) {
    return a[0] * b[1] - a[1] * b[0];
}
double norm(double a[]) {
    return a[0] * a[0] + a[1] * a[1];
}

int ccw(double a[], double b[], double c[]) {
    double ab[2] = { b[0] - a[0], b[1] - a[1] };
    double ac[2] = { c[0] - a[0], c[1] - a[1] };
    if (cross(ab, ac) > eps) return 1;
    if (cross(ab, ac) < -eps) return -1;
    if (dot(ab, ac) < -eps) return 2;
    if (norm(ab) < norm(ac) - eps) return -2;
    return 0;
}


int length(int edge[][2]) {
    int res = 0, now = 0;
    while (1) {
        res += dist[now][edge[now][1]];
        now = edge[now][1];
        if (now == 0) break;
    }
    return res;
}

void change_better(int n, int better[][2], int edge[][2]) {
    if (length(better) > length(edge)) {
        copy(n, edge, better);
    }
}

//   -o  o-      -o--o-
//     \/    ->
//     /\    ->
//   -o  o-      -o--o-
inline int swap_delta_2opt(int edge[][2], int p, int q) {
    if (p == q) return M;
    return - dist[p][edge[p][1]] - dist[q][edge[q][1]] + dist[p][q] + dist[edge[p][1]][edge[q][1]];
}

inline void swap_edges_2opt(int edge[][2], int p, int q) {
    // int now, np, nq;
    // assert(p != q);
    int np = edge[p][1];
    int nq = edge[q][1];
    int now = np;
    while (1) {
        int nex = edge[now][1];
        edge[now][1] = edge[now][0];
        edge[now][0] = nex;
        if (now == q) break;
        now = nex;
    }
    edge[p][1] = q;
    edge[q][0] = p;
    edge[np][1] = nq;
    edge[nq][0] = np;
}


//   -o---o-      -o   o-
//            ->    \ /
//      o     ->     o
//     / \    ->
//   -o   o-      -o---o-
inline int swap_delta_1_5opt(int edge[][2], int p, int q) {
    int pp = edge[p][0], np = edge[p][1];
    int nq = edge[q][1];
    if (p == q || p == nq) return M;
    return - dist[pp][p] - dist[p][np] - dist[q][nq] + dist[pp][np] + dist[q][p] + dist[p][nq];
}

inline void swap_edges_1_5opt(int edge[][2], int p, int q) {
    int pp = edge[p][0], np = edge[p][1];
    int nq = edge[q][1];
    // assert(p != q && p != nq);
    edge[pp][1] = np;
    edge[np][0] = pp;
    edge[q][1] = p;
    edge[p][0] = q;
    edge[p][1] = nq;
    edge[nq][0] = p;
}


int dp[1 << 20][20];
int prev[1 << 20][20];
void bitdp(int n, int edge[][2]) {
    int i, j;
    int mind = M, now = -1;
    int bit = (1 << n) - 1;
    for (i = 0; i < (1 << n); ++i) {
        for (j = 0; j < n; ++j) {
            dp[i][j] = M;
            prev[i][j] = -1;
        }
    }
    dp[1][0] = 0;
    for (i = 0; i < (1 << n); ++i) {
        for (j = 0; j < n; ++j) {
            int k;
            if (dp[i][j] == M) continue;
            for (k = 0; k < n; ++k) {
                if (!((i >> k) & 1)) {
                    if (dp[i | (1 << k)][k] > dp[i][j] + dist[j][k]) {
                        dp[i | (1 << k)][k] = dp[i][j] + dist[j][k];
                        prev[i | (1 << k)][k] = j;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; ++i) {
        if (mind > dp[bit][i] + dist[i][0]) {
            mind = dp[bit][i] + dist[i][0];
            now = i;
        }
    }
    edge[0][0] = now;
    edge[now][1] = 0;
    while (now != 0) {
        int prv = prev[bit][now];
        edge[now][0] = prv;
        edge[prv][1] = now;
        bit ^= 1 << now;
        now = prv;
    }
}

void nearest_neighbor(int n, int edge[][2]) {
    int s = 0, now;
    int visited[SIZE] = {};
    now = s;
    while (1) {
        int i, mind = M, nex = -1;
        visited[now] = 1;
        for (i = 0; i < n; ++i) {
            if (!visited[i] && mind > dist[now][i]) {
                mind = dist[now][i];
                nex = i;
            }
        }
        if (nex == -1) break;
        edge[now][1] = nex;
        edge[nex][0] = now;
        now = nex;
    }
    edge[s][0] = now;
    edge[now][1] = s;
}

void division_nearest_neighbor(int n, double point[][2], int edge[][2]) {
    int p1[SIZE], p2[SIZE];
    int c1 = 0, c2 = 0;
    int maxd = 0, s = -1, t = -1;
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (maxd < dist[i][j]) {
                maxd = dist[i][j];
                s = i;
                t = j;
            }
        }
    }
    for (i = 0; i < n; ++i) {
        if (i == s || i == t) continue;
        if (ccw(point[s], point[t], point[i]) >= 0) {
            p1[c1] = i;
            ++c1;
        }
        else {
            p2[c2] = i;
            ++c2;
        }
    }
    {
        int now = s;
        int visited[SIZE] = {};
        while (1) {
            int mind = M, nex = -1;
            visited[now] = 1;
            for (i = 0; i < c1; ++i) {
                int k = p1[i];
                if (!visited[k] && mind > dist[now][k]) {
                    mind = dist[now][k];
                    nex = k;
                }
            }
            if (nex == -1) break;
            edge[now][1] = nex;
            edge[nex][0] = now;
            now = nex;
        }
        edge[t][0] = now;
        edge[now][1] = t;

        now = t;
        while (1) {
            int mind = M, nex = -1;
            visited[now] = 1;
            for (i = 0; i < c2; ++i) {
                int k = p2[i];
                if (!visited[k] && mind > dist[now][k]) {
                    mind = dist[now][k];
                    nex = k;
                }
            }
            if (nex == -1) break;
            edge[now][1] = nex;
            edge[nex][0] = now;
            now = nex;
        }
        edge[s][0] = now;
        edge[now][1] = s;
    }
}

void annealing(int n, int edge[][2], long long timelim, double avedist) {
    long long start_time = get_millisec();
    long long elapsed = 0;
    long long calctime = timelim - start_time;
    unsigned int k;
    int i, j;
    double st = avedist * (n >= 3000 ? 0.001   : n >= 300 ? 0.01   : 0.1);
    double et = avedist * (n >= 3000 ? 0.00005 : n >= 300 ? 0.0005 : 0.005);
    double c = pow(2, 32);
    for (k = 0; ; ++k) {
        if (!(k & 511)) {
            elapsed = get_millisec() - start_time;
            if (elapsed > calctime)
                return;
        }
        i = randxor() % n;
        j = randxor() % n;
        // if (i == j) continue;
        if (randxor() & 1) {
            int delta = swap_delta_2opt(edge, i, j);
            if (delta < 0) {
                swap_edges_2opt(edge, i, j);
            }
            else if (delta < M) {
                double temp = st + (et - st) * elapsed / calctime;
                double prb = exp(-delta / temp) * c;
                if (prb > randxor()) {
                    swap_edges_2opt(edge, i, j);
                }
            }
        }
        else {
            // int delta;
            // if (i == edge[j][1]) continue;
            int delta = swap_delta_1_5opt(edge, i, j);
            if (delta < 0) {
                swap_edges_1_5opt(edge, i, j);
            }
            else if (delta < M) {
                double temp = st + (et - st) * elapsed / calctime;
                double prb = exp(-delta / temp) * c;
                if (prb > randxor()) {
                    swap_edges_1_5opt(edge, i, j);
                }
            }
        }
    }
}

void greedy_swap(int n, int edge[][2], long long timelim) {
    int i, j;
    while (1) {
        int changed = 0;
        for (i = 0; i < n; ++i) {
            if (get_millisec() > timelim) return;
            for (j = 0; j < n; ++j) {
                if (swap_delta_2opt(edge, i, j) < 0) {
                    swap_edges_2opt(edge, i, j);
                    changed = 1;
                }
                if (swap_delta_1_5opt(edge, i, j) < 0) {
                    swap_edges_1_5opt(edge, i, j);
                    changed = 1;
                }
            }
        }
        if (!changed) return;
    }
}


int main() {
    int n, i;
    double point[SIZE][2];
    int edge[SIZE][2];
    int bestedge[SIZE][2];
    long long start_time = get_millisec();
    int tl = 1450000, tl2;
    double avedist;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lf%lf", &point[i][0], &point[i][1]);
    }
    avedist = fill_dist(n, point);
    if (n <= 20) {
        bitdp(n, edge);
        output(n, edge);
        return 0;
    }
    tl2 = n >= 3000 ? 800000 : 1400000;
    nearest_neighbor(n, bestedge);

    nearest_neighbor(n, edge);
    annealing(n, edge, start_time + tl2, avedist);
    greedy_swap(n, edge, start_time + tl);
    change_better(n, bestedge, edge);

    division_nearest_neighbor(n, point, edge);
    annealing(n, edge, start_time + tl + tl2, avedist);
    greedy_swap(n, edge, start_time + tl * 2);
    change_better(n, bestedge, edge);

    output(n, bestedge);
    return 0;
}