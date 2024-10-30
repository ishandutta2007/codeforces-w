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
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){

        int n, s, k;
        cin >> n >> s >> k;

        set<int> f;
        for(int i = 0; i < k; i++){
            int t;
            cin >> t;
            f.insert(t);
        }

        int ans = n;
        for(int i = s; i >= 1; i--){
            if(f.find(i) == f.end()){
                ans = min(ans, s - i);
                break;
            }
        }
        for(int i = s; i <= n; i++){
            if(f.find(i) == f.end()){
                ans = min(ans, i - s);
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}