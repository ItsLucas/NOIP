#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int v, t;
    node(int v = 0, int t = 0) : v(v), t(t) {}
    bool operator<(const node &a) const { return t > a.t; }
};

vector<node> e[10001];
int dis[10001];
bool vis[10001];
node a;

inline void add(int u, int v, int t) {
    a.v = v;
    a.t = t;
    e[u].push_back(a);
}

void init() {
    for (int i = 0; i < 10001; i++) {
        e[i].clear();
        vis[i] = false;
        dis[i] = 2143000000;
    }
}

int dijkstra(int s, int to) {
    priority_queue<node> q;
    q.push(node(s, 0));
    dis[s] = 0;
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        int v = now.v;
        if (vis[v])
            continue;
        vis[v] = true;
        for (auto i : e[v]) {
            int v2 = i.v;
            int len = i.t;
            if (!vis[v2] && dis[v2] > dis[v] + len) {
                dis[v2] = dis[v] + len;
                q.push(node(v2, dis[v2]));
            }
        }
    }
    return dis[to];
}

int main() {
    init();
    int n, m, k, u, v, t;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &t);
        add(u, v, t);
        add(v, u, t);
    }
}