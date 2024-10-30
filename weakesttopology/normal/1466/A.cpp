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

int solve()
{
    int n; cin >> n;

    vector<int> x(n);

    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<int> a;

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            a.push_back(x[j] - x[i]);

    sort(all(a));

    return (int)distance(begin(a), unique(all(a)));
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}