#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct Dinic
{
    struct Edge
    {
        int from, to;
        const T& cap;
        T flow = 0;
        T free() { return cap - flow; }
        Edge(int u, int v, const T& cap) : from(u), to(v), cap(cap) {}
    };
    vector<Edge> edges;
    const T inf = numeric_limits<T>::max(), zero = 0;
    int n, m = 0;
    vector<vector<int>> E;
    vector<int> level, ptr;
    Dinic(int n) : n(n)
    {
        E.resize(n), level.resize(n), ptr.resize(n);
    }
    void add_edge(int u, int v, const T&& cap) = delete;
    void add_edge(int u, int v, const T& cap)
    {
        assert(cap >= 0);
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, zero);
        E[u].push_back(m++);
        E[v].push_back(m++);
    }
    bool bfs(int s, int t)
    {
        fill(all(level), 0); level[s] = 1;
        static queue<int> q; q.push(s);
        while (not q.empty())
        {
            int u = q.front(); q.pop();
            for (auto idx : E[u])
            {
                int v = edges[idx].to;
                if (level[v] != 0 || edges[idx].free() <= 0) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != 0;
    }
    T push(int u, int t, T pushed)
    {
        if (u == t || pushed == 0) return pushed;
        for (int& idx = ptr[u]; idx < size(E[u]); ++idx)
        {
            auto &edge = edges[E[u][idx]], &back = edges[E[u][idx] ^ 1];
            if (level[edge.to] != level[u] + 1 || edge.free() <= 0) continue;
            T pushing = push(edge.to, t, min(pushed, edge.free()));
            if (pushing == 0) continue;
            edge.flow += pushing, back.flow -= pushing;
            return pushing;
        }
        return 0;
    }
    T flow(int s, int t)
    {
        for (auto& edge : edges) edge.flow = 0;
        T f = 0;
        while (bfs(s, t))
        {
            fill(all(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
};

int main()
{ _
    constexpr int amax = 100;

    int n; cin >> n;

    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    Dinic<ll> dinic(n + 2);

    const ll inf = 1e15;
    const int s = n, t = n + 1;

    deque<ll> weight;

    vector<int> last(amax + 1, -1);

    for (int u = 0; u < n; ++u)
    {
        for (int d = 1; d <= a[u]; ++d)
        {
            if (a[u] % d == 0 && last[d] != -1)
                dinic.add_edge(last[d], u, inf);
        }

        ll& x = weight.emplace_back(abs(b[u]));

        if (b[u] >= 0)
        {
            dinic.add_edge(u, t, x);
        }
        else
        {
            dinic.add_edge(s, u, x);
        }

        last[a[u]] = u;
    }

    ll ans = 0;
    for (auto x : b) ans += max(0, x);

    debug(ans);

    ll flow = dinic.flow(s, t);
    ans -= flow;

    debug(flow);

    cout << ans << endl;

    exit(0);
}