#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[300500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[s[i]-'0']++;
    }
    if (a[0] == 0) {
        cout << 1 << endl;
    } else if (a[1] == 0) {
        cout << 0 << endl;
    } else {
        cout << 1;
        for (int i = 0; i < a[0]; i++)
            cout << 0;
        cout << endl;
    }
    return 0;
}