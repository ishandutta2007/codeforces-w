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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
vector<pii> f, f1;
int a[1000500], b[1005000];
int main() {
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    int l = 500000, r = 500001;
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '?') {
            printf("%d\n", min(b[x]-l, r-b[x])-1);
        } else if (c == 'L') {
            b[x] = l--;
        } else {
            b[x] = r++;
        }
    }
    return 0;
}