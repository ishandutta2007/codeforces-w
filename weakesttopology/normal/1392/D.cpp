#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

ll solve()
{
    int n; cin >> n;
    string s; cin >> s;

    int ct[2] = { 0 };
    for (int i = 0; i < n; ++i)
        ct[(s[i] == 'L') ? 0 : 1]++;

    if (max(ct[0], ct[1]) == n)
        return (n + 2) / 3;

    int i = 0;
    while (s[i] == s[i + 1]) ++i;

    int cur = 0, ans = 0;
    for (int j = i + 1; j != i; j = (j + 1) % n)
    {
        if (s[j] == s[(j + 1) % n]) ++cur;
        else
        {
            ans += (cur + 1) / 3;
            cur = 0;
        }
    }
    ans += (cur + 1) / 3;
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}