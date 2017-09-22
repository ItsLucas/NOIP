/*
 * if(sum[i]-sum[j]>=0)f[i]+=f[j]
 * then Tree.
 */
#include <algorithm>
#include <cstdio>
#include <iostream>

typedef long long ll;

const int N = 100001;
const int mod = 1000000009;

using namespace std;

int a[N], id[N], n;
ll Tree[N * 4], sum[N], b[N], f[N];

int pf(ll x) {
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (b[mid] == x)
            return mid;
        if (x > b[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

void add(int sta, ll x) {
    for (int i = sta; i <= n; i += (i & (-i)))
        Tree[i] += x, Tree[i] %= mod;
}

ll getsum(int sta) {
    ll sum = 0;
    for (int i = sta; i >= 1; i -= (i & (-i)))
        sum += Tree[i], sum %= mod;
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        b[i] = sum[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        id[i] = pf(sum[i]);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = getsum(id[i]);
        if (sum[i] >= 0) {
            f[i]++;
        }
        f[i] %= mod;
        add(id[i], f[i]);
    }
    cout << f[n] % mod << endl;
    return 0;
}