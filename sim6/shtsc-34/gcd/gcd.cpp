#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>

#define ll long long

using namespace std;

map<ll, ll> m;

inline ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        m.clear();
        ll n, x;
        cin >> n;
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (!m.count(x))
                m[x] = i;
            // Why NOIP doesn't allow C++11?
            // for (auto it : m)
            // Much better, right?
            for (map<ll, ll>::iterator it = m.begin(); it != m.end();) {
                ll t = gcd(x, it->first);
                ans = max(ans, t * (i - it->second + 1));
                if (!m.count(t))
                    m[t] = it->second;
                else
                    m[t] = min(m[t], it->second);
                if (t < it->first)
                    m.erase(it++);
                else
                    it++;
            }
        }
        cout << ans << endl;
    }
}