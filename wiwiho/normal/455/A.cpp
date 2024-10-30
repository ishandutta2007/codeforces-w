#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
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

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000000;

using namespace std;

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<ll> cnt(100001);
    vector<ll> dp(100001);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        cnt[t]++;
    }

    for(int i = 1; i <= 100000; i++){
        ll t1 = 0, t2 = 0;
        if(i - 1 > 0) t1 = dp[i - 1];
        if(i - 2 > 0) t2 = dp[i - 2];
        dp[i] = max(t1, t2 + i * cnt[i]);
    }

    cout << dp[100000] << "\n";

    return 0;
}