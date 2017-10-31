#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
const int inf = 1111111;

int n, m, u, v;
int g[maxn][maxn];

bool vis[maxn][maxn];
int dis[maxn][maxn];

void init_floyd() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = inf;
        }
    }
}

void floyd() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init_lucastra() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            dis[i][j] = inf;
            vis[i][j] = false;
        }
}

void lucastra(int s) {
    dis[s][s] = 1;
    while (true) {
        int a = -1, b = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (vis[i][j])
                    continue;
                if (a == -1 || dis[i][j] < dis[a][b]) {
                    a = i;
                    b = j;
                }
            }
        if (a == 0 && b == 0) {
            break;
        }
        vis[a][b] = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i == a || i == b || j == a || j == b)
                    continue;
                dis[i][j] =
                    min(dis[i][j], dis[a][b] + g[b][i] + g[i][j] + g[j][a] - 1);
            }
    }
}

int main() {
    cin >> n >> m;
    init_floyd();
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u - 1][v - 1] = 1;
    }
    floyd();
    init_lucastra();
    lucastra(1);
    cout << dis[0][0] << endl;
    return 0;
}