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
#define sec second

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

int dp[N][3];
int pre[N], fir[N], lst[N], siz[N];
int a[N], b[N], n;

void solve() {
  n = read();
  for (rint i = 1; i <= n; i++) {
    fir[i] = lst[i] = pre[i] = siz[i] = 0;
    dp[i][0] = dp[i][1] = dp[i][2] = 0;
  }
  for (rint i = 1; i <= n; i++) {
    a[i] = read();
    b[i] = a[i];    
  }
  sort(b + 1, b + n + 1);
  int tot = unique(b + 1, b + n + 1) - (b + 1);
  for (rint i = 1; i <= n; i++) {
    a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    lst[a[i]] = i;
    if (!fir[a[i]]) fir[a[i]] = i;
    siz[a[i]]++;
  }
  int ans = 1;
  for (rint i = 1; i <= n; i++) {
    dp[i][0] = dp[pre[a[i]]][0] + 1;
    dp[i][1] = max(dp[pre[a[i]]][1] + 1, max(dp[pre[a[i] - 1]][0], dp[pre[a[i] - 1]][2]) + 1);
    if (i == lst[a[i]]) {
      dp[i][2] = max(dp[fir[a[i]]][0], dp[fir[a[i]]][1]) + siz[a[i]] - 1;
    }
    pre[a[i]] = i;
    ans = max(ans, *max_element(dp[i], dp[i] + 3));
  }
  printf("%d\n", n - ans);
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}