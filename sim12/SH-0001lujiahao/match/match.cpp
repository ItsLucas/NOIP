#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int N = 100005, MOD = 99999997;

struct node {
    int i, v;
};

bool cmp(node &x, node &y) { return x.v < y.v; }

int n, c[N], cnt = 0;

node a[N], b[N];

int t[N];

inline int lowbit(int x) { return x & (-x); }

void update(int x) {
    while (x <= n) {
        t[x]++;
        x += lowbit(x);
    }
}

int getSum(int x) {
    int tmp = 0;
    while (x > 0) {
        tmp += t[x];
        x -= lowbit(x);
    }
    return tmp;
}

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].v), a[i].i = i;
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i].v), b[i].i = i;

    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        c[a[i].i] = b[i].i;
    }

    for (int i = 1; i <= n; i++) {
        update(c[i]);
        cnt = (cnt + i - getSum(c[i])) % MOD;
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}