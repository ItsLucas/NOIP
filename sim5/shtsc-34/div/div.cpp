#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map<int, int> mp;

int a[210], num[210];

int n;

inline void find(int x) {
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            int t = x / i;
            if (mp[i])
                num[mp[i]]--;
            mp[i]++, num[mp[i]]++;
            if (t != i && t <= n) {
                if (mp[t])
                    num[mp[t]]--;
                mp[t]++, num[mp[t]]++;
            }
        }
    }
}

int main() {
    int m, sum = 0;
    freopen("div.in", "r", stdin);
    freopen("div.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]), find(a[i]);
    for (int i = 1; i <= m; ++i)
        sum += num[i];
    printf("%d\n", n - sum);
    for (int i = 1; i <= m; ++i)
        printf("%d\n", num[i]);
    return 0;
}