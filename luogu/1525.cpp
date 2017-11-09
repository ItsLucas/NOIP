#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int ans;
int f[40001];

struct edge {
    int a, b, c;
} h[100001];

bool cmp(edge x, edge y) { return x.c > y.c; }

int find(int x) {
    if (x == f[x])
        return x;
    else
        return find(f[x]);
}

void unite(int x, int y) { f[find(y)] = find(x); }

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> h[i].a >> h[i].b >> h[i].c;
    }
    sort(h + 1, h + m + 1, cmp);
    for (int i = n + 1; i <= 2 * n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++) {
        int j = find(h[i].a);
        int k = find(h[i].b);
        if (j == k) {
            cout << h[i].c;
            return 0;
        }
        if (j == find(h[i].b + n) || k == find(h[i].a + n))
            continue;
        unite(j, k + n);
        unite(k, j + n);
    }
    cout << 0 << endl;
    return 0;
}