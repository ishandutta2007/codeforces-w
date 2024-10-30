#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool distinct(int n)
{
    bool t[10] = { false };

    for (int i = 0; i < 10 && n; ++i)
    {
        if (t[n  % 10])
            return false;

        t[n % 10] = true;
        n /= 10;
    }

    return true;
}

int main()
{ _
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; ++i)
    {
        if (distinct(i))
        {
            cout << i << endl;
            exit(0);
        }
    }

    cout << -1 << endl;
    exit(0);
}