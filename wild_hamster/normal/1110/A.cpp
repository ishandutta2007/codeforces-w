#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x,  y, z, l, r, i, j, p[335], q;
ll a[100500], b[100500];
ll binpow(ll x, ll y) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2);
    tmp = tmp * tmp % MOD;
    if (y % 2)
        return x * tmp % MOD;
    return tmp;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b,a%b);
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (i != m-1)
        ans += n * x;
        else
            ans += x;
    }
    cout << (ans%2 ? "odd":"even") << endl;
    return 0;
}