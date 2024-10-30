//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

bool check(ll n, ll g, ll b, ll d){

    ll t = d / (g + b);
    ll s = min(t * b, n / 2) + t * g;
    d %= g + b;
    if(d <= g) s += d;
    else s += g + max(0LL, min(n / 2 - t * b, d - g));

    return s >= n;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        ll n, g, b;
        cin >> n >> g >> b;

        ll l = 1, r = iceil(n, g) * (g + b);
        while(l < r){
            ll m = (l + r) / 2;
            if(check(n, g, b, m)) r = m;
            else l = m + 1;
        }
        cout << l << "\n";

    }

    return 0;
}