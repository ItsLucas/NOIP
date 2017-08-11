#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const double PI = 3.1415926535897932384626;

int main() {
    int n, r;
    cin >> n >> r;
    vector<pair<double, double>> a;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        double alpha = acos(r / sqrt(1.0 * x * x + 1.0 * y * y));
        double alpha0 = atan2(y, x) - alpha;
        if (alpha0 < 0)
            alpha0 += 2 * PI;
        a.push_back(make_pair(alpha0, alpha0 + 2 * alpha));
    }
    sort(a.begin(), a.end());
    int result = 0;
    priority_queue<double, vector<double>, greater<double>> q;
    for (int iters = 0; iters < 2; iters++) {
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.top() < a[i].first) {
                q.pop();
            }
            if (iters == 1) {
                result += q.size();
            }

            q.push(a[i].second);
            a[i].first += 2 * PI;
            a[i].second += 2 * PI;
        }
    }
    cout << result << endl;
    return 0;
}