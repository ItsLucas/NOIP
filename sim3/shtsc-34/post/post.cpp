#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

#define inf INT_MAX
#define mod 1000000007

using namespace std;

const int N = 1005;
const int M = 100005;

int cost[N][N];
long long d[N], D[N];

int n, m;
long long ans = 0;

bool vis[N];

void spfa(int s) {
    int now;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        d[i] = inf;
    }
    d[s] = 0;
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        vis[now] = false;
        for (int i = 1; i <= n; i++) {
            if (d[i] > d[now] + cost[now][i]) {
                d[i] = d[now] + cost[now][i];
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++)
        ans += d[i];
}

int main() {
    freopen("post.in", "r", stdin);
    freopen("post.out", "w", stdout);
    int a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; j++) {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = cost[j][i] = inf;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        cost[a][b] = min(cost[a][b], c);
    }
    spfa(1);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            swap(cost[i][j], cost[j][i]);
    spfa(1);
    cout << ans << endl;
    return 0;
}