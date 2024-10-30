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
const ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        ll xGCD = 0, yGCD = 0;
        
        bool B = 0, Y = 0;
        vector<pll> pts(n);
        REP(i, n) {
            ll x, y; cin >> x >> y;
            pts[i] = {x, y};
        }

        FOR(i, 1, n-1) {
            pts[i].first -= pts[0].first, pts[i].second -= pts[0].second;
        } pts[0] = {0, 0};

        while (true) {
            REP(i, n) {
                auto [x, y] = pts[i];
                if ((x+y)%2) B = 1;
                else Y = 1;
            }
            if (B && Y) break;

            FOR(i, 1, n-1) {
                auto [lx, ly] = pts[i];
                pts[i] = {(lx+ly)/2, (lx-ly)/2};
            }
        }

        if (B && Y) {
            vl ans;
            REP(i, n) {
                auto [x, y] = pts[i];
                if ((x+y)%2) ans.eb(i+1);
            }
            dbg(ans.size());
            ll sz = ans.size();
            cout << sz << endl;
            dbg(ans);
            REP(i, sz) cout << ans[i] << " ";
            cout << endl;
        }
    }
    return 0;
}