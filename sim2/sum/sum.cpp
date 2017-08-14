#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>

#define N 500
#define L 1000
#define bx 1000000
#define wx 6

using namespace std;

ifstream fin("sum.in");
ofstream fout("sum.out");

long n, m;
long x[N + 10], x2[N + 10];
long k[L + 10];

static inline void out(long a[]);

static inline void in(long a[]);

static inline long b_gcd(long a, long b) {
    if (b == 0) return a;
    else return b_gcd(b, a % b);
}

static inline void b_mul(long a[], long b = 1) {
    for (long i = L; i >= 1; i--) a[i] *= b;
    for (long i = L; i >= 1; i--) {
        a[i - 1] += a[i] / bx;
        a[i] %= bx;
    }
}

static inline void b_sub(long a[], long b = 1) {
    a[L] -= b;
    for (long i = L; i >= 1; i--)
        while (a[i] < 0) {
            a[i - 1]--;
            a[i] += bx;
        }
}

static inline long b_mod(long a[], long b = 1) {
    long ret = 0;
    long i = 1;
    while (i <= L && a[i] == 0) i++;
    for (long qx; i <= L; i++) {
        qx = ret * bx + a[i];
        ret = qx % b;
    }
    return ret;
}

static inline void b_div(long a[], long b = 1) {
    long i = 1, c = 0;
    while (i <= L && a[i] == 0) i++;
    for (long qx; i <= L; i++) {
        qx = c * bx + a[i];
        c = qx % b;
        a[i] = qx / b;
    }
}

int main(int argc, char *argv[]) {
    fin >> n >> m;
    memset(k, 0, sizeof(k));
    k[L] = 1;
    memset(x, 0, sizeof(x));
    for (long i = 1; i < m; i++)
        b_mul(k, x[i] = i + n);
    memcpy(x2, x, sizeof(x2));
    for (long i = 2, qx; i < m; i++) {
        long px = i;
        for (long j = 1; j < m && px > 1; j++)
            while ((px > 1) && ((qx = b_gcd(px, x[j])) > 1)) {
                b_div(k, qx);
                x[j] /= qx;
                px /= qx;
            }
    }
    memcpy(x, x2, sizeof(x));
    b_sub(k, 1);
    x[m] = m - 1;
    for (long i = 1, qx, px; i <= m; i++)
        if (x[i] > 1) {
            if ((qx = b_mod(k, x[i])) == 0) {
                b_div(k, x[i]);
                x[i] = 1;
            } else if ((px = b_gcd(qx, x[i])) > 1) {
                b_div(k, px);
                x[i] /= px;
            }
        }
    out(k);
    memset(k, 0, sizeof(k));
    k[L] = 1;
    for (long i = 1; i <= m; i++)
        b_mul(k, x[i]);
    out(k);
    return 0;
}

char ch[6];

static inline string turn(long a) {
    sprintf(ch, "m", a);
    for (long i = 0; i < 6; i++)
        if (ch[i] <= '0')
            ch[i] = '0';
    return string(ch);
}

static inline void out(long a[]) {
    long i = 0;
    while (i < L && a[i] == 0) i++;
    fout << a[i];
    for (i++; i <= L; i++)
        fout << turn(a[i]);
    fout << endl;
}

static inline void in(long a[]) {
    long i = 0;
    while (i < L && a[i] == 0) i++;
    cout << a[i];
    for (i++; i <= L; i++)
        cout << "," << turn(a[i]);
    cout << endl;
}