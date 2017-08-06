#include <cstdio>
#include <iostream>

using namespace std;

int solve(int n) {
    int num = 0;
    while (n > 0) {
        n = n - (n & (-n));
        num++;
    }
    return num;
}

int main() {
    int n, k;
    int ans = 0;
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
    scanf("%d %d", &n, &k);
    while (solve(n) > k) {
        ans = ans + (n & (-n));
        n = n + (n & (-n));
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}