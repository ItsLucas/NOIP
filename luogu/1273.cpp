// f(i,j)=max(f(i,j),f(i)(j-k)+f(p)(k) (p=allson(i))
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int v, w;
    edge(int v, int w = 0) : v(v), w(w) {}
};

const int maxn = 5000;

int n, m, w[maxn], s[maxn], f[maxn][maxn];

vector<edge> e[maxn];

void dfs(int p, int fa) {
    f[p][0] = 0;
    for (auto i : e[p]) {
        int v = i.v;
        if (v != fa) {
            dfs(v, p);
            for (int j = s[p]; j > -1; j--) {
                for (int k = s[v]; k > -1; k--) {
                    f[p][j + k] = max(f[p][j + k], f[p][j] + f[v][k] - i.w);
                }
            }
            s[p] += s[v];
        }
    }
    if (s[p] == 0) {
        f[p][1] = w[p];
        s[p] = 1;
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 3000; ++i) {
        for (int j = 0; j < 3000; ++j)
            f[i][j] = -1e9;
    }
    for (int i = 1; i < n - m + 1; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int A, C;
            cin >> A >> C;
            e[i].push_back(edge(A, C));
            e[A].push_back(edge(i, C));
        }
    }
    for (int i = n - m + 1; i < n + 1; ++i)
        cin >> w[i];
    dfs(1, -1);
    for (int i = m; i > -1; --i) {
        if (f[1][i] >= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
