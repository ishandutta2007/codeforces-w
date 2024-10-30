#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i = 0; i < (int)X.size(); ++i) cin >> X[i];

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n, m; cin >> n >> m;
    vi x(n); READ(x);

    queue<int> Q;
    map<int, int> H;

    for (int i = 0; i < n; ++i)
    {
        H[x[i]] = 1;
        Q.push(x[i] + 1);
        Q.push(x[i] - 1);
    }

    vi y;

    int c = 0;
    while (c < m)
    {
        int v = Q.front(); Q.pop();

        if (not H[v])
        {
            y.pb(v);
            H[v] = 1;

            Q.push(v + 1); Q.push(v - 1);
            c++;
        }
    }

    ll sum = 0;
    sort(ALL(x));
    for (int i = 0; i < m; ++i)
    {
        if (y[i] < x[0])
            sum += x[0] - y[i];
        else if (y[i] > x[n - 1])
            sum += y[i] - x[n - 1];
        else
        {
            auto l = lower_bound(ALL(x), y[i]); --l;
            auto u = upper_bound(ALL(x), y[i]);

            sum += min(y[i] - *l, *u - y[i]);
        }
    }

    cout << sum << endl;
    for (auto z : y)
        cout << z << " ";
    cout << endl;

    exit(0);
}