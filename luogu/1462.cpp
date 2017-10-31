#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int v, w;
    node(int v = 0, int w = 0) : v(v), w(w){};
    bool operator<(const node &a) const { return w > a.w; }
};

const int maxn = 20001;
const int INF = 0x6f6f6f6f;

vector<node> G[maxn];
bool vis[maxn];
int dis[maxn];
int f[maxn];
int n, b;

inline void add(int u, int v, int w) { G[u].push_back(node(v, w)); }

void init() {
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
}

bool dijkstra(int x) {
    if (x < f[1] || x < f[n])
        return false;
    int i;
    for (i = 1; i <= n; i++)
        dis[i] = INF;
    for (i = 1; i <= n; i++)
        if (f[i] > x)
            vis[i] = true;
        else
            vis[i] = false;
    priority_queue<node> Q;
    Q.push(node(1, 0));
    dis[1] = 0;
    while (!Q.empty()) {
        node now = Q.top();
        Q.pop();
        int v = now.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto i : G[v]) {
            int v2 = i.v;
            int len = i.w;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                Q.push(node(v2, dis[v2]));
            }
        }
    }
    return dis[n] < b;
}

int main() {
    init();
    int m, u, v, w;
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    int l = 1, r = n, mid;
    if (!dijkstra(f[n])) {
        printf("AFK\n");
        return 0;
    }
    int ans = f[n];
    while (l <= r) {
        mid = (l + r) >> 1;
        if (dijkstra(f[mid])) {
            ans = f[mid];
            r = mid - 1;
        } else
            l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}
