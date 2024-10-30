#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rtn return

#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

void solve() {
    int N; cin >> N;
    vi A(N);
    F0R(i, N) cin >> A[i];
    vi cnt(N);
    int ans = 0;
    R0F(i, N) {
        if(i == N-1 || A[i] >= A[i + 1]) cnt[i] = 1;
        else cnt[i] = cnt[i + 1] + 1;
        ans = max(ans, cnt[i] + (i != 0));
    }
    int c = 0, prv = -1;
    F0R(i, N) {
        if (A[i] > prv) c++;
        else c = 1;
        ans = max(ans, c + (i < N - 1));
        if (i < N - 2 && A[i] < A[i + 2] - 1) ans = max(ans, c + cnt[i + 2] + 1);
        prv = A[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--)
        solve();
    return 0;
}