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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

#define ln printf("\n");

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
ll pow2(ll n) {return 1ll << n;}

// const ll MAXN = 2e6+1;

// vl prime;
// bool is_composite[MAXN];

// void sieve (ll n) {
// 	std::fill (is_composite, is_composite + n, false);
// 	for (ll i = 2; i < n; ++i) {
// 		if (!is_composite[i]) prime.push_back (i);
// 		for (ll j = 0; j < prime.size () && i * prime[j] < n; ++j) {
// 			is_composite[i * prime[j]] = true;
// 			if (i % prime[j] == 0) break;
// 		}
// 	}
// }

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll x; cin >> x;
        // sieve(MAXN);

        // vl fac;
        // for (auto pr : prime) {
        //     if (sqr(pr) > x) break;
        //     if (x%pr) continue;

        //     ll num = 1;
        //     while (x%pr==0) x/=pr, num*=pr;
        //     fac.eb(num);
        // } if (x>1) fac.eb(x);

        // sort(all(fac), greater<ll>());
        // dbg(fac);

        // ll a = 1, b = 1;
        // for (auto f : fac) {
        //     if (a>b) b*=f;
        //     else a*=f;
        // }

        // cout << a << " " << b << endl;

        ll ans = 1e13, num = -1;
        FOR(i, 1, sqrt(x)) if (x%i==0 && __gcd(i, x/i)==1) {
            if (ans > i+x/i) {
                ans = i+x/i, num = i;
            } 
        }

        cout << num << " " << x/num << endl;
    }
    return 0;
}