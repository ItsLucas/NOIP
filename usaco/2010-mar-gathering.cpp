#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

const int maxn = 200100;

using namespace std;

struct P {
    long long to;
    long long cost;
};

vector<P> e[maxn];
long long dis[maxn], f[maxn], C[maxn], Q[maxn], cnt = 1, N, sum = 0;

inline void Add(int u, int v, int w) {
    P p;
    p.to = v;
    p.cost = w;
    e[u].push_back(p);
}
// dis[i] 以i为根的子树到根的距离之和
long long dfs1(long long u, long long ff) {
    long long tot = 0;
    for (auto i : e[u]) {
        long long v = i.to;
        if (v != ff) {
            long long s = dfs1(v, u);
            dis[u] += dis[v] + i.cost * s;
            tot += s;
        }
    }
    return Q[u] = tot + C[u];
}

//假设走到当前节点的父节点
//再让当前点所有牛退回来，父节点的所有牛走过去即可
void dfs2(long long u, long long ff) {
    for (auto i : e[u]) {
        long long v = i.to;
        if (v != ff) {
            long long ss = i.cost;
            f[v] = f[u] - Q[v] * ss + (sum - Q[v]) * ss;
            dfs2(v, u);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &C[i]);
        sum += C[i];
    }
    long long u, v, w;
    for (int i = 1; i <= N - 1; i++) {
        scanf("%lld %lld %lld", &u, &v, &w);
        Add(u, v, w);
        Add(v, u, w);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    long long ans = 1000000000000000000;
    for (long long i = 1; i <= N; ++i)
        ans = min(ans, f[i]);
    cout << ans + dis[1] << endl;
    return 0;
}