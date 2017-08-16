#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 55;

int a[maxn][maxn];
int sum[maxn][maxn];
int f[maxn][maxn][maxn * 10];

int main() {
    freopen("brike.in", "r", stdin);
    freopen("brike.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= n; j++) {
        for (int i = j; i <= n; i++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    }
    int ans = -1;
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][0][0] = 0, f[i][1][1] = a[i][1];
    for (int i = 1; i <= n; i++) {         // the ith line
        for (int j = 0; j <= i; j++) {     // got j bricks
            for (int k = 0; k <= m; k++) { // k bricks in total
                if (j <= k) {
                    int p;
                    if (j - 1 >= 0) {
                        p = j - 1;
                    } else {
                        p = 0;
                    }
                    for (p; p <= i - 1; p++) {
                        if (f[i - 1][p][k - j] != -1) {
                            f[i][j][k] =
                                max(f[i][j][k], f[i - 1][p][k - j] + sum[i][j]);
                            // f[i][j][k]=max{f[i][j][k-j],f[i][j][k]+sum[i][j]
                        }
                    }
                }
                if (k == m)
                    ans = max(ans, f[i][j][k]);
            }
        }
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
}