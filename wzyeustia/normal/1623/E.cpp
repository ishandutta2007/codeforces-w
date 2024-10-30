#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
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
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const ll MOD = 1e9+7;

const ll MX = 2e5+3;
ll n, k;
ll l[MX], r[MX], par[MX];
bool dup[MX], want[MX];
string s; 

stack<ll> st;
char last = '\0';
void dfs0(ll u) {
    if (l[u] != -1) par[l[u]] = u, dfs0(l[u]);
    if (last != '\0' && last != s[u]) {
        bool up = s[u] > last;
        while (!st.empty()) {
            auto pre = st.top(); st.pop();
            want[pre] = up;
        }
    } 
    last = s[u], st.em(u);
    if (r[u] != -1) par[r[u]] = u, dfs0(r[u]);
}

void update(ll u) {
    if (dup[u]) return;
    dup[u] = 1;
    if (par[u] != -1) update(par[u]);
}

ll cost = 0;
vector<char> ans;
void dfs(ll u, bool can) {
    dbg(u, can);
    if (!dup[u]) cost++;
    if (l[u] != -1) dfs(l[u], can);
    
    if (want[u] && cost <= k && can) update(u), k -= cost, cost = 0; 
    ans.eb(s[u]); if (dup[u]) ans.eb(s[u]);

    if (r[u] != -1) dfs(r[u], can && dup[u]);
    if (!dup[u]) cost--;
}



int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);      
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k;
        cin >> s;

        REP(i, n) {
            par[i] = -1;
            cin >> l[i] >> r[i];
            l[i]--, r[i]--;
        }

        dfs0(0);
        while (!st.empty()) {
            auto pre = st.top(); st.pop();
            want[pre] = false;
        }
        FILL(dup, false);

        REP(i, n) dbg(i, want[i]);

        dfs(0, 1);
        
        dbg(ans);
        for (auto c : ans) cout << c; cout << endl;
    }
}