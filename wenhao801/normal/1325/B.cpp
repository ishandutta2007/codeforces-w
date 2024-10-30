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

int a[100100];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        sort(a + 1, a + n + 1);
        n = unique(a + 1, a + n + 1) - a - 1;
        cout << n << endl;
    }
    return 0;
}