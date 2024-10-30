#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 998'244'353;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        vector<int> arr(n);
        REP(i, n) {
            cin >> arr[i];
        }

        ll ans = 0, num1 = -1, num2 = -1;
        REP(i, n) {
            if (num2 == -1) {
                ans++;
                if (num1 != arr[i]) num1 = arr[i];
                else num2 = arr[i];
            }
            else {
                if (num1 == arr[i] && num2 != arr[i]) {
                    ans++;
                    num2 = arr[i];
                }
                else if (num1 != arr[i] && num2 == arr[i]) {
                    num1 = arr[i];
                    ans++;
                }
                else if (num1 != arr[i] && num2 != arr[i]) {
                    ans++;
                    if (num1 != num2) 
                        num2 = -1;
                    num1 = arr[i];
                    
                }
            }
            dbg(num1, num2);
        }

        cout << ans << endl;
    }
    return 0;
}