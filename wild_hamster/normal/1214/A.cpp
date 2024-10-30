#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 228228
#define MOD 1000000007
ll n, x, k, z, m, a[200500], b[200500], ra[200500], rb[200500], pa, pb;

int main() {
    ll x,y;
    cin >> n >> x >> y;
    ll ans = MOD;
    for (int i = 0; i * x <= n; i++) {
        ll d = (n - i*x);
        ans = min(ans, d % (5*y));
    }
    cout << ans << endl;




    return 0;
}