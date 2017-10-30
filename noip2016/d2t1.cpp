#include <bits/stdc++.h>

using namespace std;

const int maxn = 2003;

int f[maxn][maxn], s[maxn][maxn];

int main() {
    int n, m, t, k;
    cin >> t >> k;

    for (int i = 1; i < maxn; i++) {
        f[i][0] = 1, f[i][i] = 1;
        for (int j = 1; j < i; j++) {
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % k;
        }
    }

    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = s[i][j - 1];
            if (f[i][j] == 0)
                s[i][j]++;
        }
    }

    for (int i = 1; i <= t; i++) {
        cin >> n >> m;
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            int x = min(j, m);
            ans += s[j][x];
        }
        cout << ans << endl;
    }

    return 0;
}