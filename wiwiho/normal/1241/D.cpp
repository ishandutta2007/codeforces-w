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

        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> l(n + 1, -1), r(n + 1, -1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(l[a[i]] == -1) l[a[i]] = i;
            r[a[i]] = i;
        }

        int now = 0;
        int ans = 1;
        int lst = 0;
        for(int i = 1; i <= n; i++){
            if(l[i] == -1){
                continue;
            }
            if(r[lst] < l[i]){
                now++;
                ans = max(now, ans);
            }
            else{
                now = 1;
            }
            lst = i;
        }
        lsort(a);

        cout << unique(iter(a)) - a.begin() - ans << "\n";

    }

    return 0;
}