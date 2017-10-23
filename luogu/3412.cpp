#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int maxn = 100001;

vector<int> G[maxn];
int siz[maxn];

inline void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int dfs(int u, int fa) {
    siz[u] = 1;
    for (int v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            siz[u] += siz[v];
        }
    }
}

int main() {
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    dfs(1, 0);
}