#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int fa[50001];

struct edge {
    int u, v;
    friend bool operator<(edge A, edge B) {
        if (A.u != B.u)
            return A.u < B.u;
        return A.v < B.v;
    }
} e[100001];

inline int f(int u) { return fa[u] == u ? fa[u] : fa[u] = f(fa[u]); }

int main() {
    freopen("graphchecker.in", "r", stdin);
    freopen("graphchecker.out", "w", stdout);
    int t, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            if (u > v)
                swap(u, v);
            e[i].u = u;
            e[i].v = v;
        }
        sort(e + 1, e + m + 1);
        int zh = 0, cb = 0;
        for (int i = 1; i <= m; i++) {
            if (e[i].u == e[i].v)
                zh = 1;
            if (i > 1 && e[i].u == e[i - 1].u && e[i].v == e[i - 1].v)
                cb = 1;
        }
        int s = 1;
        for (int i = 1; i <= m; i++) {
            u = f(e[i].u);
            v = f(e[i].v);
            if (u == v)
                s = 0;
            else
                fa[u] = v;
        }
        int cnt = 0;
        int lt;
        for (int i = 1; i <= n; ++i)
            if (f(i) == i)
                ++cnt;
        if (cnt == 1)
            lt = 1;
        else
            lt = 0;
        if (lt && s)
            cout << "1 ";
        else
            cout << "0 ";
        if (zh)
            cout << "1 ";
        else
            cout << "0 ";
        if (cb)
            cout << "1 ";
        else
            cout << "0 ";
        if (lt)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
}