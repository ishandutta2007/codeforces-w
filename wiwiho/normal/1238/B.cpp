//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define B back()
#define FR front()
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)
#define iceil(a) ((int)ceil(a))
#define ifloor(a) ((int)floor(a))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int q;
    cin >> q;
    while(q--){

        ll n, r;
        cin >> n >> r;
        priority_queue<ll> pq;
        for(int i = 0; i < n ;i ++){
            ll t;
            cin >> t;
            pq.push(t);
        }

        ll ans = 0;
        ll move = 0;
        while(!pq.empty() && pq.top() - move > 0){
            ans++;
            int lst = pq.top();
            while(!pq.empty() && pq.top() == lst) pq.pop();
            move += r;
        }

        cout << ans << "\n";

    }

    return 0;
}