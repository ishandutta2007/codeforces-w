#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    ll m = 2, k = 1;

    for (int i = 0; i < n; ++i, ++k)
    {
        ll res = k * k * k + 2 * k * k - m + k;

        cout << res << endl;

        m = k;
    }

    exit(0);
}