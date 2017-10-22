#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int z[4] = {0, 0, 1, -1}, c[4] = {1, -1, 0, 0};
int n, x, y, x1, y2, mapp[1010][1010], q1[1001000], q2[1001000], d[1010][1010];
bool v[1011][1011];
void inti() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> x1 >> y2, mapp[x1][y2] = 1;
}
void spfa(int x, int y) {
    memset(d, 127, sizeof(d));
    v[x][y] = 1;
    d[x][y] = mapp[x][y];
    q1[0] = x;
    q2[0] = y;
    int head = 0, tail = 1;
    while (head != tail) {
        int nx = q1[head], ny = q2[head];
        head = (head + 1) % 100000;
        for (int i = 0; i < 4; i++) {
            int sx = nx + c[i], sy = ny + z[i];
            if (sx >= 0 && sx <= 1001 && sy >= 0 && sy <= 1001 &&
                d[sx][sy] > d[nx][ny] + mapp[sx][sy]) {
                d[sx][sy] = d[nx][ny] + mapp[sx][sy];
                if (!v[sx][sy]) {
                    v[sx][sy] = 1;
                    tail = (1 + tail) % 100000;
                    q1[tail] = sx;
                    q2[tail] = sy;
                }
            }
        }
        v[nx][ny] = 0;
    }
}
void work() {
    spfa(x, y);
    cout << d[0][0];
}
int main() {
    inti();
    work();
    return 0;
}