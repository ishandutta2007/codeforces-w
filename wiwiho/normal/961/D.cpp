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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

pll operator-(pll a, pll b){
    return mp(a.F - b.F, a.S - b.S);
}

ll cross(pll a, pll b){
    return a.F * b.S - a.S * b.F;
}

bool line(pll a, pll b, pll c){
    return cross(b - a, c - a) == 0;
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    if(n <= 4){
        cout << "YES\n";
        return 0;
    }

    vector<pll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;

    bool ans = false;
    for(int i = 0; i < 3; i++){
        pll now = p[i];
        map<pll, vector<int>> cnt;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll x = p[j].F - now.F;
            ll y = p[j].S - now.S;
            if(y < 0) y *= -1, x *= -1;
            ll g = __gcd(x, y);
            x /= g; y /= g;
            cnt[mp(x, y)].eb(j);
        }

        pll t = mp(MAX, MAX);
        for(auto& j : cnt){
            if(j.S.size() >= 2){
                t = j.F;
                break;
            }
        }

        if(t == mp(MAX, MAX)) continue;

        bool tans = true;
        vector<pll> ps;
        for(auto& j : cnt){
            if(j.F == t) continue;
            for(int k : j.S) ps.eb(p[k]);
        }

        for(int j = 2; j < ps.size(); j++){
            if(!line(ps[0], ps[1], ps[j])){
                tans = false;
                break;
            }
        }

        if(tans) ans = true;

        break;
    }

    if(ans) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}