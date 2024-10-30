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
    
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0){
            a[i] = -a[i] - 1;
        }
    }

    if(n % 2 == 1){
        int ma = -1;
        for(int i = 0; i < n; i++){
            if((ma == -1 || a[i] < a[ma]) && a[i] != -1){
                ma = i;
            }
        }
        if(ma == -1){
            ma = 0;
        }
        a[ma] = -a[ma] - 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";

    return 0;
}