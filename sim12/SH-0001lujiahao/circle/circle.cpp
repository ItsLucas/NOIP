#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll pow(ll x, int p, int n) {
    ll ans = 1;
    for (; p; p >>= 1) {
        if (p & 1)
            (ans *= x) %= n;
        (x *= x) %= n;
    }
    return ans;
}

int main() {
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    cout << pow(10, k, n) * m % n + x << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}