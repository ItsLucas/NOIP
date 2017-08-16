#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 100000;

int buf[maxn * 2 + 1];
int *cnt = buf + maxn;

int main() {
    freopen("median.in", "r", stdin);
    freopen("median.out", "w", stdout);
    int n, b;
    cin >> n >> b;
    long long ans = 0;
    bool flag = false;
    int sum = 0;
    cnt[0] = 1;
    while (n--) {
        int a;
        cin >> a;
        if (a == b) {
            flag = true;
        } else if (a < b) {
            sum--;
        } else if (a > b) {
            sum++;
        }
        if (!flag) {
            cnt[sum]++;
        } else {
            ans += cnt[sum];
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
