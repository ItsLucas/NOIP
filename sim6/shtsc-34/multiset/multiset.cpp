#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>

const int maxn = 1000001;

using namespace std;

struct card {
    int w, h;
    bool operator<(const card &b) const {
        if (w != b.w)
            return w < b.w;
        else
            return h < b.h;
    }
} a[maxn], b[maxn];

int main() {
    freopen("multiset.in", "r", stdin);
    freopen("multiset.out", "w", stdout);
    int t;
    scnaf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].w, &a[i].h);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &b[i].w, &b[i].h);
        }
        sort(a, a + n);
        sort(b, b + n);
        multiset<int> s;
        int k = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (k < n && B[k].w <= A[i].w)
                s.insert(B[k++].h);
            if (s.empty())
                continue;
            // Why NOIP doesn't allow C++11?
            // auto it = s.upper_bound(a[i].h)
            // Much better, right?
            multiset<int>::iterator it = s.upper_bound(a[i].h);
            if (it != s.begin()) {
                ans++;
                s.erase(--it);
            }
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
