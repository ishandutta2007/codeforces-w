// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define debug(x) cerr << #x << " = " << x << '\n';
#define pll pair <ll, ll>

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

const int N = 200005;

ll a[N], w[N];
int n, k;

void solve() {
  n = read(), k = read();
  for (rint i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1, [&](ll x, ll y) {
    return x > y;
  });
  for (rint i = 1; i <= k; i++) w[i] = read();
  sort(w + 1, w + k + 1);
  ll ans = 0;
  int cur = 0;
  for (rint i = 1; i <= k; i++) {
    ans += a[i];
    if (w[i] == 1) cur = i, ans += a[i];
  } 
  for (rint i = k + 1; i <= n; i++) {
    i += w[++cur] - 2;
    ans += a[i];
  }
  printf("%lld\n", ans);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}