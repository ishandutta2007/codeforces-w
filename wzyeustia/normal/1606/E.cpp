#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
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
#define lb_pos(arr, key) lower_bound(all(arr), key) - (arr).begin()
#define ub_pos(arr, key) upper_bound(all(arr), key) - (arr).begin()

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

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

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ld EPS = 1e-8;
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll getInv(ll a, ll p) {
 return (a == 1 ? 1 : (1 - p * getInv(p % a, a)) / a + p);
}

// factor precalculation
const ll FAC_SIZE = 1e4+3;
ll fac[FAC_SIZE], inv[FAC_SIZE];
void initFac(ll sz) {
    fac[0] = 1, inv[0] = 1;
    FOR(i, 1, sz-1) fac[i] = fac[i-1]*i%MOD;
    inv[FAC_SIZE-1] = getInv(fac[FAC_SIZE-1], MOD);
    ROF(i, sz-2, 1) inv[i] = inv[i+1]*(i+1)%MOD;
}
// combinatorics
ll comb(ll x, ll y) { // select y from x
    if (x < y) return 0;
    return fac[x] * inv[y]%MOD * inv[x-y]%MOD;
}

const ll MX = 500;
ll po[MX+2][MX+2];
ll dp[MX+2][MX+2]; 

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    initFac(FAC_SIZE);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, x; cin >> n >> x;
        
        FOR(i, 1, MX) po[i][0] = 1;
        FOR(i, 1, MX) FOR(j, 1, MX) {
            po[i][j] = po[i][j-1] * i %MOD;
        }

        FILL(dp, 0); // [people][max_health]
        REP(i, MX+2) dp[0][i] = 1;

        FOR(i, 2, n) FOR(j, 1, x) {
            FOR(k, 0, i) { // k: GG guys
                ll cnt1 = po[min(j, i-1)][k];
                ll cnt2 = dp[i-k][j-min(j, i-1)];
                ll cnt3 = comb(i, k);
                // dbg(k, cnt1, cnt2, cnt3);
                dp[i][j] = (dp[i][j] + cnt1*cnt2%MOD *cnt3)%MOD;
            }
            // dbg(i, j, dp[i][j]);
        }

        cout << dp[n][x] << endl;
    }
    return 0;
}