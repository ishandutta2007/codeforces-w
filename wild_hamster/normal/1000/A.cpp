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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,tot,y,INF, ans;
ll a[1200005], b[1205000], fac[1205000], dp[100500][4];
map<string, ll> x;
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        x[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        x[s]--;
    }
    for (auto itr = x.begin(); itr != x.end(); itr++) {
        if ((*itr).Y > 0)
            ans += (*itr).Y;
    }
    cout << ans << endl;
    return 0;
}