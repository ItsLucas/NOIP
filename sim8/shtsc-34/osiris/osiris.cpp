#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    freopen("osiris.in", "r", stdin);
    freopen("osiris.out", "w", stdout);
    int T;
    int a, b, c, x, y, z;
    int m, l;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> x >> y >> z;
        if (a > x)
            m += (a - x) / 2;
        else
            l += (x - a);
        if (b > y)
            m += (b - y) / 2;
        else
            l += (y - b);
        if (c > z)
            m += (c - z) / 2;
        else
            l += (z - c);
        if (m >= l)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        m = 0;
        l = 0;
    }
    return 0;
}