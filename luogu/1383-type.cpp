#include <bits/stdc++.h>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

const int N = 1e5 + 5;

int n;
int d[N];

rope<char> *m[N];
inline int lowbit(int x) { return x & -x; }
inline void update(int x) {
    while (x <= n) {
        d[x]++;
        x += lowbit(x);
    }
}

inline int get(int x) {
    int res = 0;
    while (x) {
        res += d[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    cin >> n;
    char c;
    m[0] = new rope<char>();
    for (int i = 1; i <= n; i++) {
        cin >> c;
        int x = 0;
        m[i] = new rope<char>(*m[i - 1]);
        if (c == 'T') {
            char x;
            cin >> x;
            m[i]->push_back(x);
            update(i);
        } else if (c == 'U') {
            update(i);
            scanf("%d", &x);
            int l = 1, r = i, now = get(i);
            while (l < r) {
                int mid = (l + r) >> 1;
                if (now - get(mid) > x)
                    l = mid + 1;
                else
                    r = mid;
            }
            m[i] = m[l - 1];
        } else if (c == 'Q') {
            scanf("%d", &x);
            putchar(m[i]->at(x - 1));
            puts("");
        }
    }
}
