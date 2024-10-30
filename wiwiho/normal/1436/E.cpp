//#define NDEBUG

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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

struct Node{
    int l = -1, r = -1, v = 0;
};

vector<Node> st;
int ts = 0;

int build(int l, int r){
    int id = ts++;
    if(l == r) return id;
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    return id;
}

void modify(int x, int v, int L, int R, int id){
    if(L == R){
        st[id].v = v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, v, L, M, st[id].l);
    else modify(x, v, M + 1, R, st[id].r);
    st[id].v = min(st[st[id].l].v, st[st[id].r].v);
}

int query(int l, int r, int L, int R, int id){
    if(l == L && r == R) return st[id].v;
    int M = (L + R) / 2;
    if(r <= M) return query(l, r, L, M, st[id].l);
    else if(l > M) return query(l, r, M + 1, R, st[id].r);
    else return min(query(l, M, L, M, st[id].l), query(M + 1, r, M + 1, R, st[id].r));
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    st.resize(2 * n);
    build(1, n);

    bool n1 = false;
    vector<int> lst(n + 2);
    vector<bool> ok(n + 3);
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        if(a != 1) n1 = true;
        if(a != 1 && query(1, a - 1, 1, n, 0) > lst[a]) ok[a] = true;
        lst[a] = i;
        modify(a, i, 1, n, 0);
    }
    ok[1] = n1;
    for(int i = 2; i <= n + 1; i++){
        if(query(1, i - 1, 1, n, 0) > lst[i]) ok[i] = true;
    }

    for(int i = 1; i <= n + 2; i++){
        if(!ok[i]){
            cout << i << "\n";
            break;
        }
    }

    return 0;
}