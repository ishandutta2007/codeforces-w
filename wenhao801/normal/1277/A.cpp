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

int main () {
	int T = read();
	while (T--) {
		int ans = 0;
		int i, j;
		int n = read();
		for (i = 1; i <= 9; i++) {
			long long s = 0;
			while (true) {
				if (s * 10 + i > n) break;
				else s = s * 10 + i, ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}