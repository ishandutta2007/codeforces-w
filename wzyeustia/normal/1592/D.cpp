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
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vvl G;

queue<ll> que;
vl vec, par;

ll query(ll k) {
    // set<ll> se;
    // REP(i, end) se.em(vec[i]);
    cout << "? " << k << " ";
    REP(i, k) cout << vec[i] << " ";
    cout << endl; cout.flush();

    ll ret; cin >> ret;
    return ret;
}

void answer(ll a, ll b) {
    cout << "! " << a << " " << b << endl;
    cout.flush();
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        G = vvl(n+2);
        REP(i, n-1) {
            ll u, v; cin >> u >> v;
            G[u].eb(v), G[v].eb(u);
        }

        que.em(1), vec.eb(1);
        par = vl(n+2, 0);
        while (!que.empty()) {
            auto u = que.front(); que.pop();
            for (auto v : G[u]) if (v != par[u]) {
                par[v] = u; que.em(v), vec.eb(v);
            }
        }
        dbg(vec);

        ll mx = query(n);

        ll lo = 2, hi = n, ans = n;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            ll ret = query(mid);
            if (ret == mx) {
                hi = mid-1, ans = mid;
            } else lo = mid+1;
        }

        dbg(mx, ans);
        ll a = vec[ans-1], b = par[vec[ans-1]];
        answer(a, b);
    }
    return 0;
}