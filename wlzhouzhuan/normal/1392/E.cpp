// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

int n, q;

int main() {
  scanf("%d", &n); 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%lld ", (ll)(i % 2 == 0) << i + j - 3);
    }
    puts("");
  }
  fflush(stdout);
  scanf("%d", &q);
  while (q--) {
    ll num;
    scanf("%lld", &num);
    int x = 1, y = 1, bit = 0;
    printf("1 1\n");
    for (int i = 1; i <= 2 * n - 2; i++) {
      if ((num >> (i - 1) & 1) == (x & 1)) x++;
      else y++;
      printf("%d %d\n", x, y);
    }
    fflush(stdout);
  }
}