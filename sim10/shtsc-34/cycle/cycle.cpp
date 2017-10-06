#include <cstdio>
#include <iostream>

using namespace std;

int a[100];
int b = 0, c = 0;

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        a[i] = a[i - n];
    }
    for (int i = n; i >= 1; i--) {
        if (a[i])
            b++;
        else
            break;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        if (a[i])
            c++;
        else
            break;
    }
    if (b & 1 || c & 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}