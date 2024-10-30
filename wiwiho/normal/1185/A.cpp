#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n"

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int d;
    cin >> d;
    lsort(a);

    int ans = 0;
    if(a[2] < a[1] + d){
        ans += a[1] + d - a[2];
    }
    if(a[0] > a[1] - d){
        ans += a[0] - (a[1] - d);
    }
    cout << ans << "\n";

    return 0;
}