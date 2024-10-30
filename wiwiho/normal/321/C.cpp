#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

vector<vector<int>> g;
vector<bool> no;
vector<int> sz;
vector<char> ans;

void solve(int s, int d){
    function<void(int, int)> dfs;
    dfs = [&](int now, int p){
        sz[now] = 1;
        for(int i : g[now]){
            if(i == p || no[i]) continue;
            dfs(i, now);
            sz[now] += sz[i];
        }
    };
    dfs(s, s);
    int cen = -1;
    dfs = [&](int now, int p){
        int mx = sz[s] - sz[now];
        for(int i : g[now]){
            if(i == p || no[i]) continue;
            dfs(i, now);
            mx = max(mx, sz[i]);
        }
        if(mx <= sz[s] / 2) cen = now;
    };
    dfs(s, s);
    ans[cen] = 'A' + d;

    no[cen] = true;
    for(int i : g[cen]){
        if(no[i]) continue;
        solve(i, d + 1);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;
    g.resize(n + 1);
    no.resize(n + 1);
    sz.resize(n + 1);
    ans.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    solve(1, 0);

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}