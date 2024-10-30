#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define debug(x) cerr << #x << " == " << (x) << '\n'
#define mp(x, y) make_pair(x, y)
#define ALL(X) X.begin(), X.end()
#define READ(X) for (int i_ = 0; i_ < (int)X.size(); ++i_) cin >> X[i_]
#define SZ(X) (int)X.size()

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
    vi a(m); READ(a);

    vvi E(n);
    for (int j = 0; j + 1 < m; ++j)
    {
        int x = a[j] - 1, y = a[j + 1] - 1;

        if (x != y)
        {
            E[x].pb(y);
            E[y].pb(x);
        }
    }

    ll ans = 0;
    ll M = 0;
    for (int i = 0; i < n; ++i)
    {
        sort(ALL(E[i]));

        if (SZ(E[i]) == 0)
            continue;

        ll T = 0;
        for (auto j : E[i])
            T += abs(i - j);

        ans += T;

        int l = SZ(E[i]);
        int med = l % 2 ? E[i][l / 2] : (E[i][l / 2 - 1] + E[i][l / 2]) / 2;

        ll N = 0;
        for (auto j : E[i])
            N += abs(med - j);

        M = max(M, T - N);

        if (l % 2 == 0)
        {
            med += 1, N = 0;

            for (auto j : E[i])
                N += abs(med - j);

            M = max(M, T - N);
        }
    }

    ans = (ans - 2 * M) / 2;

    cout << ans << endl;

    exit(0);
}

/*
 * INT_MAX      ~  2 * 1e9  ~ 2^31 - 1
 * LLONG_MAX    ~  9 * 1e18 ~ 2^63 - 1
 * ULLONG_MAX   ~ 18 * 1e18 ~ 2^64 - 1
 *
 * INF  ~ 1.0 * 1e9
 * LINF ~ 4.5 * 1e18
 *
 * CHECK:
 *      OVERFLOW
 *      IF/LOOP CONDITIONS
 *      CREATION OF STL CONTAINERS
 */