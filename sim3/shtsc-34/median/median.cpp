#include <cstdio>
#include <iostream>

using namespace std;

int a[100010], L[200010], R[200010];

int main() {
    int n, b, num, ans;
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == b) {
            num = i;
            a[i] = 0;
            continue;
        }
        if (a[i] > b)
            a[i] = 1;
        else
            a[i] = -1;
    }
    int l = n, r = n;
    for (int i = num; i > 0; --i)
        l += a[i], L[l]++;
    for (int i = num; i <= n; ++i)
        r += a[i], R[r]++;
    int len = 2 * n;
    for (int i = 0; i <= len; ++i)
        ans += (L[i] * R[len - i]);
    printf("%d\n", ans);
    return 0;
}
