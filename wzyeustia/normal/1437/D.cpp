#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#ifdef OI_DEBUG
template<char endch, typename T>
void log_impl(T&& val) { cout << val << endch; }
template<char endch, typename T, typename... Ts>
void log_impl(T &&val, Ts &&...vals) {
    cout << val << ' ';
    log_impl<endch>(vals...);
}
#define logs log_impl<' '>
#define logln log_impl<'\n'>
#else
template<typename... Ts> void do_nothing(Ts &&...vals) {}
#define logs do_nothing
#define logln do_nothing
#endif // OI_DEBUG

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

#define ln cout << endl;
#define show(str, x) cout << str << x; ln
#define showArr(str, arr, size) cout << str; ln; REP(test, size) {cout << arr[test] << " ";} ln

#define get(x) int x; cin >> x
#define getArr(arr, n) REP(i, n) {cin >> arr[i];}

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

// ll fastPow(ll num, ll exp) {
//     if (exp == 0) return 1;
//     if (exp == 1) return num;
//     else {
//         ll half = fastPow(num, exp/2);
//         if (exp % 2 == 1) {
//             return half * half * num;
//         }
//         else {
//             return half * half;
//         }
//     }
// }

// ll getReverse(ll y, ll modNum) {
//     return fastPow(y, modNum - 2, modNum) % modNum;
// }

// ll gcd(ll a, ll b) {
//     return (a % b == 0)? b: gcd(b, a%b);
// }

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    get(t);
    REP(I, t) {
        get(n);
        vector<int> arr(n);
        getArr(arr, n);

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        
        int height = 1;
        int num = 1;
        int next = 1;
        queue<int> childNum;
        childNum.push(-1);

        int crtSum = 1;
        while (next != n-1) {
            // cout << "next = " << next << endl;
            // cout << "num = " << num << endl;
            // cout << "crtSum = " << crtSum << endl;

            if (arr[next+1] > arr[next]) crtSum++;
            else {
                childNum.push(crtSum);
                crtSum = 1;
                // next++;
                if (num > 1) {
                    num--;
                }
                else {
                    num = childNum.front();
                    childNum.pop();
                    if (num == -1) {
                        num = childNum.front();
                        childNum.pop();
                        height++;
                        childNum.push(-1);
                    }
                }
            }
            

            next++;
        }

        cout << height << endl;
    }
    //Main program
}