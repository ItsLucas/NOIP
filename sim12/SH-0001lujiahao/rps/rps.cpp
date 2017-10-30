#include <cstdio>
#include <iostream>

using namespace std;

int a[201], b[201];

const int r[5][5] = {{0, 0, 1, 1, 0},
                     {1, 0, 0, 1, 0},
                     {0, 1, 0, 0, 1},
                     {0, 0, 1, 0, 1},
                     {1, 1, 0, 0, 0}};

int main() {
    freopen("rps.in", "r", stdin);
    freopen("rps.out", "w", stdout);
    int n, na, nb, ta, tb, ra = 0, rb = 0;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        ta = a[i % na];
        tb = b[i % nb];
        ra += r[ta][tb];
        rb += r[tb][ta];
    }
    cout << ra << " " << rb << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}