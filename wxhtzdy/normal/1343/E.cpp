#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=2010000;
int n,m,a,b,c,_,p[N],d[3][N];
ll pf[N];
VI g[N];
bool vis[N];

void bfs(int u,int* d) {
	rep(i,1,n+1) vis[i]=0;
	vis[u]=1; d[u]=0;
	deque<int> q={u};
	while (SZ(q)) {
		int x=q[0]; q.pop_front();
		for (auto v:g[x]) {
			if (!vis[v]) {
				vis[v]=1;
				q.pb(v);
				d[v]=d[x]+1;
			}
		}
	}
}

void solve() {
	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	rep(i,1,m+1) scanf("%d",p+i);
	rep(i,1,n+1) g[i].clear();
	rep(i,0,m) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	sort(p+1,p+m+1);
	rep(i,1,m+1) pf[i]=pf[i-1]+p[i];
	bfs(a,d[0]);
	bfs(b,d[1]);
	bfs(c,d[2]);
	ll ans=1e18;
	rep(i,1,n+1) {
		int x=d[0][i]+d[1][i]+d[2][i];
		if (x<=m) ans=min(ans,pf[x]+pf[d[1][i]]);
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}