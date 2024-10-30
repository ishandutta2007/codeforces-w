// ./e-two-platforms.yml
#include "bits/stdc++.h"
using namespace std;

// Defines
#define fs first
#define sn second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
// Basic type definitions
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<long long, long long>;
// PBDS order statistic tree
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T, class comp = less<T>> using os_tree = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V, class comp = less<K>> using treemap = tree<K, V, comp, rb_tree_tag, tree_order_statistics_node_update>;
// HashSet
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };
template <typename T, class Hash> using hashset = gp_hash_table<T, null_type, Hash>;
template <typename K, typename V, class Hash> using hashmap = gp_hash_table<K, V, Hash>;
// More utilities
int SZ(string &v) { return v.length(); }
template <typename C> int SZ(C &v) { return v.size(); }
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
template <typename T, typename U> void maxa(T &a, U b) { a = max(a, b); }
template <typename T, typename U> void mina(T &a, U b) { a = min(a, b); }
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 10;
int N,
    pre[MN], suf[MN], sufV[MN];
ll K,
    X[MN];

void solve() {
    sort(X + 1, X + N + 1);
    for (auto i = 1; i <= N; i++) {
        int idx = lower_bound(X + 1, X + N + 1, X[i] - K) - X;
        // cout<<"i="<<(i)<<", "; cout<<"idx="<<(idx)<<", "; cout << endl; // db i,idx
        maxa(pre[i], max(pre[i - 1], i - idx + 1));
    }
    for (auto i = N; i >= 1; i--) {
        int idx = upper_bound(X + 1, X + N + 1, X[i] + K) - 1 - X;
        maxa(suf[i], max(suf[i + 1], sufV[i] = idx - i + 1));
    }

    // cout<<"(X+1)=["; for(int __i=0; __i<(N); __i++)cout<<(X+1)[__i]<<", "; cout<<"], ";cout<<"(pre+1)=["; for(int __i=0; __i<(N); __i++)cout<<(pre+1)[__i]<<", "; cout<<"], ";cout<<"(suf+1)=["; for(int __i=0; __i<(N); __i++)cout<<(suf+1)[__i]<<", "; cout<<"], ";cout << endl; // db A:N:(X+1),A:N:(pre+1),A:N:(suf+1)

    int ans = 0;
    for (auto i = 1; i <= N; i++) maxa(ans, max(pre[i] + suf[i + 1], pre[i] + sufV[i] - 1));
    cout << (ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        cin >> (N) >> (K);
        ll tmp;
        for (auto i = 1; i <= N; i++)
            cin >> (X[i]);
        for (auto i = 1; i <= N; i++)
            cin >> (tmp);
        
        solve();

        // Reset
        fill(pre, pre + N + 2, 0);
        fill(suf, suf + N + 2, 0);
        fill(sufV, sufV + N + 2, 0);
    }
}