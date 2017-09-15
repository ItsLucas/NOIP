#include <cstdio>

using namespace std;

const int maxn = 100001;
const double eps = 1e-7;

long long a[maxn], s[maxn];
double t[maxn], tmp[maxn];

// 统计 t[l]..t[r] 中 有多少组(i,j)满足
// t[i] >= t[j]

long long count(int l, int r) {
    if (l >= r)
        return 0;
    int m = (l + r) / 2;
    long long ret = count(l, m) + count(m + 1, r);
    int i = l;
    int j = m + 1;
    for (int k = l; k <= r; k++) {
        if ((i <= m) && (j > r || t[i] < t[j])) {
            tmp[k] = t[i];
            i++;
        } else {
            ret += m - i + 1;
            tmp[k] = t[j];
            j++;
        }
    }
    for (int k = l; k <= r; k++) {
        t[k] = tmp[k];
    }
    return ret;
}

int main() {
    int n;
    long long k;
    freopen("ave.in", "r", stdin);
    freopen("ave.out", "w", stdout);
    scanf("%d %lld", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = a[i] + s[i - 1];
    }
    // s[0]..s[n]

    double low = 0;
    double high = 1e9 + 1;
    while (high - low > eps) {
        double mid = (low + high) * 0.5;
        for (int i = 0; i <= n; i++)
            t[i] = s[i] - i * mid;
        if (count(0, n) < k)
            low = mid;
        else
            high = mid;
    }
    printf("%.4f\n", low);
}