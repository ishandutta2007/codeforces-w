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

int lowbit(int x){
    return x & -x;
}

struct BIT{
    vector<int> bit;
    BIT(int sz){
        bit.resize(sz + 1);
    }
    void modify(int x, int v){
        for(; x < bit.size(); x += lowbit(x)) bit[x] += v;
    }
    int query(int x){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
};

void solve(){
    
    int n, k;
    cin >> n >> k;

    BIT cnt(n);
    BIT sum(n);

    vector<int> no(n + 1, 1);
    map<int, int> tot;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        tot[a]++;
        if(a < n) no[a] = 0;
    }
    vector<pii> owo;
    for(auto i : tot){
        owo.eb(mp(i.S, i.F));
    }
    lsort(owo);
    map<int, int> pos;
    for(int i = 0; i < owo.size(); i++){
        pos[owo[i].S] = i + 1;
    }

    for(int i = 1; i <= n; i++) no[i] += no[i - 1];

    for(auto i : tot){
        if(i.F <= n) continue;
        int p = pos[i.F];
        cnt.modify(p, 1);
        sum.modify(p, i.S);
    }

    int ans = n;
    for(int i = n; i >= 0; i--){ // mex

        if(tot.find(i) != tot.end()){
            int p = pos[i];
            cnt.modify(p, 1);
            sum.modify(p, tot[i]);
        }

        int tmp = i ? no[i - 1] : 0;
        if(k < tmp) continue;

        int l = 0, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(sum.query(mid) > k) r = mid - 1;
            else l = mid;
        }
        int tans = i + cnt.query(n) - cnt.query(l);
        //cerr << "test " << i << " " << l << " " << cnt.query(n) << " " << cnt.query(l) << " " << tans - i << "\n";
        ans = min(ans, tans - i);

    }
    cout << ans << "\n";

}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}