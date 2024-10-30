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
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

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
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

ll n;

bool can(string str) {
    dbg(str);

    ll tot = 0;
    REP(i, n) {
        if (str[i] == '(') tot++;
        else tot--;
        if (tot < 0) {
            return false;
        }
    }
    if (tot == 0) return true;
    else return false;
}

const ll UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll n, m; cin >> n >> m;
        vl box(n); REP(i, n) cin >> box[i];
        vl pos(m); REP(i, m) cin >> pos[i];

        auto rBox = lower_bound(all(box), 0);
        ll rPos = lower_bound(all(pos), 0) - pos.begin();

        vl offset(m+1, 0);
        ROF(i, m-1, rPos) {
            offset[i] = offset[i+1];
            if (*lower_bound(all(box), pos[i]) == pos[i]) 
                offset[i]++;
        }
        // dbg(offset);

        ll rMax = 0;
        FOR(i, rPos, m-1) {
            ll numBox = upper_bound(all(box), pos[i]) - rBox;
            ll earn = offset[i+1] + 
                lower_bound(all(pos), pos[i]+1) - lower_bound(all(pos), pos[i]-numBox+1);
            // dbg(i, earn);
            chkmax(rMax, earn);
        }

        // dbg(rMax);

        ll lPos = rPos-1;
        FOR(i, 0, lPos) {
            if (i > 0) offset[i] = offset[i-1];
            if (*lower_bound(all(box), pos[i]) == pos[i]) 
                offset[i]++;
        }
        // dbg(offset);

        ll lMax = 0;
        ROF(i, lPos, 0) {
            ll numBox = rBox - lower_bound(all(box), pos[i]);
            
            ll earn = lower_bound(all(pos), pos[i]+numBox) - lower_bound(all(pos), pos[i]);
            if (i != 0) earn += offset[i-1];
            chkmax(lMax, earn);
        }
        // dbg(lMax);

        dbg(lMax + rMax);
        cout << lMax + rMax << endl;
    }
    return 0;
}