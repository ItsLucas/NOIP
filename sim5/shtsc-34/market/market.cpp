#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 301;
const double inf = 1.1e9;

int f[maxn][maxn * maxn];

struct S {
    int c, v, t;
} a[maxn];

inline bool operator<(S a, S b) { return a.t < b.t; }

int main() {
    int n, m, sum;

    freopen("market.in", "r", stdin);
    freopen("market.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i].c, &a[i].v, &a[i].t);
        sum += a[i].v;
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= sum; i++)
        f[0][i] = inf;
    int pos = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++)
            f[i][j] = f[i - 1][j];
        for (; a[pos].t <= i && pos <= n; pos++) {
            for (int j = sum; j >= a[pos].v; j--)
                f[i][j] = min(f[i][j], f[i][j - a[pos].v] + a[pos].c);
            for (int j = a[pos].v - 1; j; j--)
                f[i][j] = min(f[i][j], f[i][0] + a[pos].c);
        }
    }

    int x, y;
    while (m--) {
        scanf("%d%d", &x, &y);
        int ans = 0, l = 0, r = sum + 10;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (f[x][mid] <= y)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}