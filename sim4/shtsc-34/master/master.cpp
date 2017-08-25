#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define S 3000
int n, k;
char sa[S], sb[S];

int main() {
    freopen("master.in", "r", stdin);
    freopen("master.out", "w", stdout);
    scanf("%d%d%s%s", &n, &k, sa, sb);
    int ans = 0;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            int cur = 0;
            for (int l = 1; a + l <= n && b + l <= n; l++) {
                cur += (sa[l + a - 1] != sb[l + b - 1]);
                if (cur > k)
                    break;
                ans = max(ans, l);
            }
        }
    }
    printf("%d\n", ans);
}
