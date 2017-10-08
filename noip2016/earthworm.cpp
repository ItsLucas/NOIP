#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
int a[100010], n, m, q, u, v, t;
int now = 0;

queue<int> orig, cl, cs; // original,cut_long,cut_short

inline int front(queue<int> &q) {
    if (q.empty())
        return -0x3f3f3f3f;
    else
        return q.front() + now;
}

inline int get() {
    int mx = max(front(orig), max(front(cl), front(cs)));
    if (mx == front(orig))
        orig.pop();
    else if (mx == front(cl))
        cl.pop();
    else
        cs.pop();
    return mx;
}

inline bool cmp(int a, int b) { return a > b; }

int main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        orig.push(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        int tt = get();
        int l1 = (ll)tt * u / v;
        int l2 = tt - l1;
        cl.push(l1 - now - q);
        cs.push(l2 - now - q);
        if (i % t == 0)
            cout << tt << " ";
        now += q;
    }
    cout << endl;
    for (int i = 1; i <= n + m; i++) {
        int tt = get();
        if (i % t == 0)
            cout << tt << " ";
    }
    cout << endl;
    return 0;
}