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

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


ll n, m;
vl val, sz;
vvl G;

vector<vector<pll>> dp;
vector<pll> buffer;
void dfs(ll u, ll par) {
    dp[u][0] = {0, val[u]}, sz[u] = 1;
    for (auto v : G[u]) if (v != par) {
        dfs(v, u);
        buffer.assign(m, {-1, -1});
        REP(i, min(m, sz[u])) REP(j, min(m-i, sz[v])) {
            ll k1 = dp[u][i].first + dp[v][j].first;
            ll k2 = dp[u][i].second + dp[v][j].second;
            chkmax(buffer[i+j], mp(k1, k2));
            if (i+j+1 < m) {
                k1 = k1 + (dp[v][j].second > 0);
                k2 = dp[u][i].second;
                chkmax(buffer[i+j+1], mp(k1, k2));
            }
        }

        sz[u] = min(m, sz[u] + sz[v]);
        dbg(u, sz[u]);
        REP(i, sz[u]) {
            dp[u][i] = buffer[i];
            auto [win, head] = buffer[i];
            dbg(win, head);
        }
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n >> m;
        G = vvl(n+2), val = vl(n+2), sz = vl(n+2);
        dp = vector<vector<pll>>(n+1, vector<pll>(m+1));

        FOR(i, 1, n) cin >> val[i];
        FOR(i, 1, n) {ll tmp; cin >> tmp; val[i] = tmp - val[i];}
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }
        dbg(val);

        dfs(1, 0);
        auto [win, head] = dp[1][m-1];
        dbg(win, head);
        cout << win + (head > 0) << endl;
    }
    return 0;
}