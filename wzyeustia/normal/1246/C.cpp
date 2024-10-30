#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll RIGHT = 0, DOWN = 1;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        char ma[n+1][m+1];
        FOR(i, 1, n) FOR(j, 1, m) cin >> ma[i][j];

        ll hor[n+2][m+2], ver[n+2][m+2]; 
        FILL(hor, 0), FILL(ver, 0);
        ROF(i, n, 1) ROF(j, m, 1) {
            hor[i][j] = hor[i][j+1] + (ma[i][j] == 'R');
            ver[i][j] = ver[i+1][j] + (ma[i][j] == 'R');
        }

        // dbg("rock");
        // FOR(i, 1, n) {
        //     FOR(j, 1, m) cout << ver[i][j] << " ";
        //     cout << endl;
        // }

        ll dp[n+2][m+2][2], del[n+2][m+2][2]; FILL(dp, 0);
        dp[1][1][RIGHT] = dp[1][1][DOWN] = 1;
        dp[2][1][RIGHT] = dp[1][2][DOWN] = -1;

        FOR(i, 1, n) FOR(j, 1, m) {
            dbg(dp[i][j][DOWN], dp[i][j-1][DOWN]);
            dp[i][j][RIGHT] = (dp[i][j][RIGHT] + dp[i-1][j][RIGHT])%MOD;
            dp[i][j][DOWN] = (dp[i][j][DOWN] + dp[i][j-1][DOWN])%MOD;
            ll right = dp[i][j][RIGHT], down = dp[i][j][DOWN];
            dbg(i, j, right, down);

            ll colEnd = m - hor[i][j+1], rowEnd = n - ver[i+1][j];
            dp[i][j+1][DOWN] = (dp[i][j+1][DOWN] + right)%MOD;
            dp[i][colEnd+1][DOWN] = (dp[i][colEnd+1][DOWN] + MOD - right)%MOD;

            dp[i+1][j][RIGHT] = (dp[i+1][j][RIGHT] + down)%MOD;
            dp[rowEnd+1][j][RIGHT] = (dp[rowEnd+1][j][RIGHT] + MOD - down)%MOD;
        }

        ll ans = (dp[n][m][DOWN] + dp[n][m][RIGHT])%MOD;
        if (n == 1 && m == 1) ans = 1;
        cout << ans << endl;
    }
    return 0;
}