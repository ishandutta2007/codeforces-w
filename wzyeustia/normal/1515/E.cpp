#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define _1 first
#define _2 second

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
// ll pow2(ll n) {return 1ll << n;}

ll n, m; 
vvl dp(800, vl(800, 0)), done(800, vl(800, 0));
vl pow2(802);

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}
// factor precalculation
const ll FAC_SIZE = 1e4+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz, ll MOD) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD, inv[i] = getInv(fac[i], MOD);
    // inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1], MOD);
    // ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}
// combinatorics
ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}


ll calc(ll x, ll y) {
    // dbg(x, y, done[x][y]);
    if (done[x][y]) return dp[x][y];
    done[x][y] = 1;

    // dbg(2*y-3, x-2);
    
    FOR(len, 2*y-3, x-2) {
        ll seg = x-1 - len;
        // dbg(len, seg);
        dp[x][y] += calc(seg, 1) * calc(len, y-1)%m * comb(x-y+1, seg)%m;
        dp[x][y] %= m;
    }
    return dp[x][y];
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> m;
        MOD = m;
        initFac(500, m);

        pow2[0] = 1;
        FOR(i, 1, n) pow2[i] = pow2[i-1]*2%m;
        FOR(i, 1, n) dp[i][1] = pow2[i-1], done[i][1] = 1;

        ll ans = 0;
        FOR(i, 1, (n+1)/2) {
            ans = (ans + calc(n, i))%m;
            // dbg(ans);
        }

        dbg(ans);
        cout << ans << endl;

        
    }
    return 0;
}