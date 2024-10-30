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
#define chkmax(a, b) a = max((long long) a, (long long) b)

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

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

ll fastPow(ll num, ll exp, ll modNum) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2, modNum) % modNum;
        if (exp % 2 == 1) {
            return (((half * half) % modNum) * num) % modNum;
        }
        else {
            return (half * half) % modNum;
        }
    }
}

ll fastPow(ll num, ll exp) {
    if (exp == 0) return 1;
    if (exp == 1) return num;
    else {
        ll half = fastPow(num, exp/2);
        if (exp % 2 == 1) {
            return (((half * half)) * num);
        }
        else {
            return (half * half);
        }
    }
}
 
ll getReverse(ll y, ll modNum) {
    return fastPow(y, modNum - 2, modNum) % modNum;
}
 
ll gcd(ll a, ll b) {
    return (a % b == 0)? b: gcd(b, a%b);
}



bool solve(ll k, ll l, ll r, ll t, ll x, ll y, unordered_set<ll> &visited) {
    // cout << "checking " << k << " " << l << " " << r << " " << t << " " << x << " " << y << endl;
    if (visited.count(k)) return true;
    else visited.emplace(k);

    if (k < l || k > r) return false;

    if (k + y > r) {
        ll T0 = max((k+y-r) / x, 1ll);
        // cout << "T0 = " << T0 << endl;

        if (T0 >= t) {
            long double last = (long double) k - ((long double) x) * t;
            if (last >= l) return true;
            else return false;
        }
        else {
            return solve(k-x*T0, l, r, t-T0, x, y, visited);
        }
    }
    else {
        if (y <= x) {
            long double last = (long double) k - ((long double)t) * (x - y);
            if (last >= l) return true;
            else return false;
        }
        else {
            ll T0 = max((r-(y+k)) / (y-x) , 1ll);
            // cout << "T0 = " << T0 << endl;

            if (T0 >= t) {
                return true;
            }
            else {
                return solve(k+(y-x)*T0, l, r, t-T0, x, y, visited);
            }
        }
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> results(n, vector<ll>(m, 0));
        REP(i, n) {
            string str;
            cin >> str;
            
            int cnt = 0;
            REP(j, m) {
                if (str[j] == '*') {
                    cnt++;
                    int len = 0;
                    while (len*2+1 <= cnt && len <= i) {
                        if (results[i-len][j-len] == len) {
                            results[i-len][j-len]++;
                        }
                        len++;
                    }
                }
                else {
                    cnt = 0;
                }
            }
        }

        ll ans = 0;
        REP(i, n) {
            REP(j, m) {
                ans += results[i][j];
            }
        }

        cout << ans << endl;
    }

}