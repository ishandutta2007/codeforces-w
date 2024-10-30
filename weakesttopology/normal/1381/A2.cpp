#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string a, b; cin >> a >> b;

        int X = 0;
        auto C = [&X](char c){ return X ? '0' + !(c -'0') : c; };

        vi ans;
        for (int s = 0, e = n - 1, j = n - 1; j >= 0; --j)
        {
            int i = X ? s : e;
            int z = X ? e : s;

            if (C(a[i]) != b[j])
            {
                if (a[i] != a[z])
                {
                    a[z] = a[i];
                    ans.pb(0);
                }
                ans.pb(j);

                if (!X)
                    ++s;
                else
                    --e;

                X = !X;
            }
            else
            {
                if (X)
                    ++s;
                else
                    --e;
            }
        }

        cout << SZ(ans);
        for (auto z : ans)
            cout << " " << z + 1;
        cout << endl;
    }
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