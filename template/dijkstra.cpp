#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int v, w;
    node(int v, int w) : v(v), w(w){};
    bool operator<(const node &a) const { return w > a.w; }
};

const int maxn = 10001;
const int INF = 0x3f3f3f3f;

vector<node> G[maxn];
bool vis[maxn];
int dis[maxn];

inline void add(int u, int v, int w) { G[u].push_back(node(v, w)); }

void init() {
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
        vis[i] = false;
        dis[i] = INF;
    }
}

void dijkstra(int s) {
    priority_queue<node> Q;
    Q.push(node(s, 0));
    dis[s] = 0;
    while (!Q.empty()) {
        node now = Q.top();
        Q.pop();
        int v = now.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (node i : G[v]) {
            int v2 = i.v;
            int len = i.w;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                Q.push(node(v2, dis[v2]));
            }
        }
    }
}

int main() {
    init();
    int n, m, s, u, v, w;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (s == i)
            cout << 0 << " ";
        else {
            if (dis[i] == 0x7f7f7f7f)
                cout << 2147483647 << " ";
            else
                cout << dis[i] << " ";
        }
    }
    return 0;
}
