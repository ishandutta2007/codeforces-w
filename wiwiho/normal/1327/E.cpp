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

const ll MOD = 998244353;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll fp(ll a, ll b){
    ll now = 1;
    ll base = a;
    while(b > 0){
        if(b & 1) now = now * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return now;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(i == n){
            cout << "10 ";
            continue;
        }
        else if(i == n - 1){
            cout << "180 ";
            continue;
        }
        ll ans = 0;
        ans += (9 * fp(10, n - i - 1)) * 10 % MOD * 2 % MOD;
        ans %= MOD;
        ans += 9 * 9 * fp(10, n - 2 - i) * 10 % MOD * (n - i - 1) % MOD;
        ans %= MOD;
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}