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

int lowbit(int num) {return num & (-num);}

void init(vector<int> &arr, int n, vector<int> &BIT) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

int query(int k, vector<int> &BIT) {
    int sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, int delta, vector<int> &BIT) {
    if (l > r) return;

    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
    }
}

int search(int key, vector<int> &BIT) {
    int temp = BIT.size()-1, k = 1;
    while (temp > 0) {k <<= 1; temp >>= 1;}
    k >>= 1;
    // cout << "k = " << k << endl;

    int pos = 0, current = 0;
    for (; k>0; k>>=1) {
        if (pos+k>=BIT.size()) continue;
        // cout << "checking pos " << pos + k << " with value " << current+BIT[pos+k] << endl; 
        if (current + BIT[pos+k] >= key) {
            current += BIT[pos+k]; pos += k; 
            // cout << "current: " << current << endl; 
        }
    }

    // cout << "find in pos: " << pos << " with value " << current << endl;
    return pos;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        int n, q; cin >> n >> q;
        vector<int> arr(n+1), BIT(n+1, 0), ans(q, -1);
        vector<vector<int>> endAt(n+1);
        FOR(i, 1, n) {int temp; cin >> temp; arr[i] = i - temp;}

        vector<pii> queries;
        REP(i, q) {
            int x, y; cin >> x >> y; 
            queries.eb(x+1, n-y);
            endAt[n-y].eb(i);
        }
        
        FOR(i, 1, n) {
            if (arr[i] >= 0) {
                int pos = search(arr[i], BIT);
                update(1, min(pos, i), 1, BIT);
            }
            // cout << "BIT after " << i << endl; 
            // FOR(i, 1, n) {
            //     cout << query(i, BIT) << " ";
            // }ln;

            // cout << "i = " << i << endl;
            for (auto idx : endAt[i]) {
                // cout << "processing query " << idx << endl;
                pii pa = queries[idx];
                ans[idx] = query(pa.first, BIT);
            }
        }

        REP(i, q) {cout << ans[i] << endl;}

    }
    return 0;
}