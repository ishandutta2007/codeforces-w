#include <time.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <stdint.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 200500
#define MOD 998244353
#define OFF 2001
ll n, x, k, z, m, pos, q, ans_v, y;
ll x1, p1, x2;
set<pii> f;
ll a[200500], b[205000], c[200500];
void solve() {
    cin >> n >> m;
    for (int i = 0; i <n ; i++) {
        cin >> a[i];
        c[a[i]] = i;
    }
    ll mx = -1;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (c[b[i]] > mx) {
            ans += (c[b[i]] - i) * 2 + 1;
            mx = c[b[i]];
        } else {
            ans++;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}