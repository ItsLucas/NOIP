#include <cmath>
#include <cstdio>
#include <iostream>

typedef long long ll;
using namespace std;
const int N = 3000001;

ll a[N], b[N];
ll p;
ll n, k;
void f(ll s) { //分解质因数
    ll j = 0;
    for (ll i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            ll count = 0;
            a[j] = i;
            while (s % i == 0) {
                count++;
                s /= i;
            }
            b[j++] = count;
        }
    }
    if (s > 1) {
        a[j] = s;
        b[j++] = 1;
    }
    p = j;
}

ll g(ll x, ll y) {
    if (x < y)
        return 0;
    else
        return x / y + g(x / y, y);
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0x7fffffffffffffff;
    ll tmp;
    f(k);
    for (int i = 0; i < p; i++) {
        tmp = g(n, a[i]);
        tmp /= b[i];
        ans = ans > tmp ? tmp : ans;
    }
    cout << ans << endl;
    return 0;
}