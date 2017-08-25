#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define S 100000

using namespace std;

long long cc[S];
char rp[1505][1505];
bitset<1503> bs[1505];
int main() {
    int n;
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        gets(rp[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cc[j] += (rp[i][j] == '1');
            bs[i][j] = rp[i][j] - '0';
        }
    }
    long long ans = 0, cyc = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (rp[i][j] != '1')
                continue;
            ans += (cc[i] - 1) * (cc[j] - 1) * 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            if (rp[i][j] == '1')
                cyc += (bs[i] & bs[j]).count();
    }
    cout << ans - cyc * 2 << "\n";
}