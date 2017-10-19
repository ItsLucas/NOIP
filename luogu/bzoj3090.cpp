#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> G[2001];
int w[2001];
int bro[2001], son[2001], fa[2001];
int f[2000][2000];
int n, x, u, v;

void dfs(int u, int p) {
    bro[u] = son[p];
    son[p] = u;
    for (auto i : G[u]) {
        if (i != p) {
            dfs(i, u);
        }
    }
}

int best(int u) { return 0; }

int dfs2(int u) {
    if (u == 0)
        return 0;
    int s = son[u];
    int b = bro[u];
    int sz = dfs2(s);
    int bz = dfs2(b);
    int a = best(s);
    for (int k = 0; k <= n; k++) {
        if (k - a >= 0)
            f[u][k] = f[b][k - a];
        else
            f[u][k] = -100000000;
    }
    for (int i = 0; i <= sz; i++) {
        for (int j = 0; j <= bz; j++) {
            int k = i + j + 1;
            f[u][k] = max(f[u][k], f[s][i] + f[b][j] + x - w[u]);
        }
    }
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}