#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define FILL0(arr) memset(arr, 0, sizeof(arr))

#define ln cout << endl;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e5+5; 

const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll getInv(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    return (a % b == 0)? b: gcd(b, a%b);
}

vector<pll> divisors;
vl fac, inv;
map<ll, ll> result;

ll comb(ll n, ll m) {
    if (m > n) return 0;
    return M(M(fac[n] * inv[m]) * inv[n-m]);
} 
 

void dfs(ll num, ll idx, ll tot, ll val) {
    if (!result[num]) result[num] = val;
    if (idx >= divisors.size()) return;

    auto [div, cnt] = divisors[idx];
    FOR(i, 0, cnt) {
        dfs(num, idx+1, tot+i, val * comb(tot+i, i));
        num *= div;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    ll MX_NUM = 64;
    fac = vl(MX_NUM, 1), inv = vl(MX_NUM, 1);
    FOR(i, 1, MX_NUM-1) fac[i] = M(fac[i-1] * i), inv[i] = getInv(fac[i], MOD);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        // After reading other grandmaster's code...
        // much better than what I write...
        ll D, q; cin >> D >> q;

        FOR(i, 2, 1e8) {
            if (sqr(i) > D) break;
            ll cnt = 0;
            while (D%i == 0) cnt++, D/=i;
            if (cnt) divisors.eb(i, cnt);
        }
        if (D > 1) divisors.eb(D, 1);

        dfs(1, 0, 0, 1);

        REP(i, q) {
            ll u, v; cin >> u >> v;
            ll k = gcd(u, v);

            ll ans = M(result[u/k] * result[v/k]);
            dbg(ans);
            cout << ans << endl;
        }
    }
    return 0;
}