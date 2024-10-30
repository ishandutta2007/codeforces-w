#include <bits/stdc++.h>

using namespace std;

typedef int ll;
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        ll sz = 25;
        vvl cnt(sz); vl len(sz);
        REP(i, sz) {
            len[i] = (1ll << (i+1));
            cnt[i] = vl(len[i], 0);
        }

        dbg(len);

        REP(i, n) {
            ll a; cin >> a;
            REP(j, sz) {
                cnt[j][a%len[j]]++;
            }
        }

        ll ans = 0;
        REP(bit, sz) {
            // vl pre(2*len[bit]+1, 0);
            // FOR(i, 1, 2*len[bit]) pre[i] = pre[i-1] + cnt[bit][i-1];
            // dbg(pre);
            
            ll r = 2*len[bit], l = 3*len[bit]/2;
            ll crt = 0;
            ROF(i, r-1, l) crt += cnt[bit][i%len[bit]];

            long long tot = 0;
            REP(pos, len[bit]) {
                tot += crt * cnt[bit][pos];
                r--, l--;
                crt += cnt[bit][l%len[bit]], crt -= cnt[bit][r%len[bit]];
                dbg(crt);
                if ((pos << 1) & (1 << bit) ) tot -= cnt[bit][pos];
            }

            dbg(tot);
            tot >>= 1;
            if (tot & 1) ans |= (1 << bit);
        }

        cout << ans << endl;
    }
    return 0;
}