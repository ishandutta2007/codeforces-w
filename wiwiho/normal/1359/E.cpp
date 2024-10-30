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
#define tomax(a, b) (a = max(a, b))
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

const ll MOD = 998244353;
const ll MAX = 1000000000;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll inv(ll n){
    ll t = MOD - 2;
    ll base = n;
    ll now = 1;
    while(t > 0){
        if(t & 1) now = now * base % MOD;
        base = base * base % MOD;
        t >>= 1;
    }
    return now;
}
vector<ll> f;

ll c(ll n, ll k){
    return f[n] * inv(f[n - k]) % MOD * inv(f[k]) % MOD;
}

int main(){
    StarBurstStream

    int n, k;
    cin >> n >> k;

    f.resize(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(n / i < k) continue;
        ans += c(n / i - 1, k - 1);
        ans %= MOD;
    }

    cout << ans << "\n";

    return 0;
}