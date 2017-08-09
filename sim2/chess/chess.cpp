#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[100001], b[100001];

int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }
    sort(b + 1, b + n);
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += b[i];
    }
    cout << ans << endl;
    return 0;
}
