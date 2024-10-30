//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

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
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<vector<int>> cnt((k + 1) / 2, vector<int>(26));
        vector<int> sum((k + 1) / 2);

        for(int i = 0; i < n; i += k){
            for(int j = 0; j < (k + 1) / 2; j++){
                cnt[j][s[i + j] - 'a']++, sum[j]++;
                if(k - 1 - j != j) cnt[j][s[i + k - 1 - j] - 'a']++, sum[j]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < (k + 1) / 2; i++){
            int tmp = 0;
            for(int j : cnt[i]) tmp = max(tmp, j);
            ans += sum[i] - tmp;
        }

        cout << ans << "\n";

    }

    return 0;
}