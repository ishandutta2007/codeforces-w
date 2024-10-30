#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1010;
int n, a[MAXN], b[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        for (i = 1; i <= n; i++) b[i] = read();
        sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
        for (i = 1; i <= n; i++) if (b[i] - a[i] < 0 || b[i] - a[i] > 1) {
            puts("NO"); break;
        }
        if (i > n) puts("YES");
    }
    return 0;
}