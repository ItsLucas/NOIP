#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> s, t;
const int maxn = 200010;
int a[maxn], f[maxn], g[maxn];
bool b[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = true;
    }
    for (int i = 1; i <= (n << 1); i++) {
        if (!b[i]) {
            s.insert(i);
            t.insert(-i);
        }
    }
    for (int i = 1; i <= n; i++) {
        auto it = s.lower_bound(a[i]);
        if (it != s.end()) {
            s.erase(it);
            f[i] = f[i - 1] + 1;
        } else
            f[i] = f[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        auto it = t.lower_bound(-a[i]);
        if (it != t.end()) {
            t.erase(it);
            g[i] = g[i + 1] + 1;
        } else
            g[i] = g[i + 1];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, f[i] + g[i + 1]);
    }
    cout << ans << endl;
    return 0;
}