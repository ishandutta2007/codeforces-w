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

#define Node seg[node]
#define LC seg[2*node]
#define RC seg[2*node+1]

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
const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;} 

ll n, q; 
string first, last;

const ll SIZE = 2e5+3;
const int ZERO = 2, ONE = 1;

// TODO: segment definition
struct Seg {
  int l, r, mid;
  ll val, lazy = 0;
} seg[SIZE*8];

void update(int l, int r, int type, int node);

// TODO: pushdown & pushup process
void pDown(int node) {
    if (Node.lazy && Node.l != Node.r) {
        update(Node.l, Node.mid, Node.lazy, node*2);
        update(Node.mid+1, Node.r, Node.lazy, node*2+1);
        Node.lazy = 0;
    }
}

void pUp(int node) {
    Node.val = LC.val + RC.val;
}

void build(int l, int r, int node = 1) {
    Node.l = l, Node.r = r, Node.mid = (l+r)>>1, Node.lazy = 0;
    if (l == r) {
        Node.val = first[l-1] == '1'; // TODO: init value
    } else {
        build(l, Node.mid, 2*node); build(Node.mid+1, r, 2*node+1);
        pUp(node);
    }
}

void update(int l, int r, int type, int node = 1) {
    if (l <= Node.l && Node.r <= r) {
        // TODO: update 
        if (type == ZERO) {
            Node.lazy = ZERO;
            Node.val = 0;}
        else {
            Node.lazy = ONE;
            Node.val = Node.r-Node.l+1;}
    } else {
        pDown(node);
        if (l <= Node.mid) update(l, r, type, 2*node); 
        if (r > Node.mid) update(l, r, type, 2*node+1);
        pUp(node);
    }
}

ll query(int l, int r, int node = 1) {
    // dbg(Node.l, Node.r, node);
    if (l <= Node.l && Node.r <= r) {
        return Node.val;
    } else {
        pDown(node);
        // TODO: combine 
        ll ret = 0;
        if (l <= Node.mid) ret += query(l, r, 2*node);
        if (r > Node.mid) ret += query(l, r, 2*node+1);
        return ret;
    }
}

void status() {
    cout << "Status: ";
    FOR(i, 1, n) {
        cout << query(i, i) << " ";
    }ln;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        cin >> n >> q; 
        cin >> last >> first;
        build(1, n);
        // status();

        vl x(q), y(q);
        REP(i, q) {cin >> x[i] >> y[i];}

        bool flag = true;
        REP(i, q) {
            int l = x[q-1-i], r = y[q-1-i];
            
            int result = query(l, r);
            // dbg(l, r, result);
            if (result*2 == r-l+1) {
                flag = false;
            }
            if (!flag) continue;

            if (result*2 < r-l+1) {
                update(l, r, ZERO);
            } else {
                update(l, r, ONE);
            }

            // status();
        }

        FOR(i, 1, n) {
            if (query(i, i) != last[i-1] - '0') {
                flag = false; break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}