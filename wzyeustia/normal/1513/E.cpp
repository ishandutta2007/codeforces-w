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
#define reset(x, y) memset(x, y, sizeof(x))
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
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) 
            return sqr(half)%MOD * num % MOD;
        else 
            return sqr(half)%MOD;
    }
}
 
// number theory
ll getInv(ll y) {return fastPow(y, MOD-2)%MOD;}

// factor precalculation
const ll FAC_SIZE = 1e5+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD;
    inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1]);
    ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}
// combinatorics
ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    initFac(FAC_SIZE);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vl a(n); ll sum = 0;

        map<ll, ll> ma;
        REP(i, n) {
            cin >> a[i];
            ma[a[i]]++;
            sum += a[i];
        }

        ll offset = 1;
        for (auto [key, val] : ma) {
            offset = (offset * inv[val])%MOD;
        }

        bool can = true; ll avg = sum / n;
        if (avg * n != sum) can = false;

        const ll SOURCE = 0, SINK = 1, FREE = 2;
        ll source = 0, sink = 0, free = 0;
        vl stat(n);
        REP(i, n) {
            if (a[i] > avg) stat[i] = SOURCE, source++;
            if (a[i] < avg) stat[i] = SINK, sink++;
            if (a[i] == avg) stat[i] = FREE, free++;
        }

        ll ans;
        if (source <= 1 || sink <= 1) {
            ans = fac[n];
        } else {
            ans = (fac[n] * inv[n-free])%MOD;
            ans = (ans * fac[source])%MOD;
            ans = (ans * fac[sink])%MOD;
            ans = (ans * 2)%MOD;
        }

        if (can) {
            cout << (ans * offset)%MOD << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}