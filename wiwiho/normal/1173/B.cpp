#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(iter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a) bool pvaspace=false;

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 1000000000

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << max(n - n / 2, n / 2 + 1) << "\n";

    for(int i = 1; i <= n / 2; i++){
        cout << i << " 1" << "\n";
    }
    for(int i = n / 2 + 1; i <= n; i++){
        cout << (n / 2 + 1) << " " << (i - n / 2) << "\n";
    }

    
    return 0;
}