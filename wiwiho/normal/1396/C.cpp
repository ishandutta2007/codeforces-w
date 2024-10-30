//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    ll r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    ll d;
    cin >> d;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> dp0(n + 1), dp1(n + 1);
    dp0[0] = dp1[0] = -d;
    for(int i = 1; i <= n; i++){
        dp0[i] = dp1[i] = 1LL << 60;

        tomin(dp1[i], dp0[i - 1] + d + r1 * (a[i] + 1));
        tomin(dp1[i], dp1[i - 1] + d + r1 * (a[i] + 1) + d + r1 + d);
        tomin(dp1[i], dp0[i - 1] + d + r2);
        tomin(dp1[i], dp1[i - 1] + d + r2 + d + r1 + d);

        tomin(dp0[i], dp0[i - 1] + d + r1 * (a[i] + 1) + d + d + r1);
        tomin(dp0[i], dp1[i - 1] + d + r1 * (a[i] + 1) + d + r1 + d + r1);
        tomin(dp0[i], dp0[i - 1] + d + r2 + d + d + r1);
        tomin(dp0[i], dp1[i - 1] + d + r2 + d + r1 + d + r1);
        tomin(dp0[i], dp0[i - 1] + d + r1 * a[i] + r3);
        tomin(dp0[i], dp1[i - 1] + d + r1 * a[i] + r3 + d + r1 + (i != n) * d);
    }
//    printv(dp0, cerr);
//    printv(dp1, cerr);

    cout << dp0[n] << "\n";

    return 0;
}