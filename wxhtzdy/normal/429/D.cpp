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

const int N=101000;
int n;
ll x[N],y[N];

ll sq(ll x) { return x*x; }
ll dist(int i,int j) {
	return sq(x[i]-x[j])+sq(y[i]-y[j]);
}
ll gao(int l,int r) {
	if (l==r) return 1e18;
	int md=(l+r)>>1;
	ll d=min(gao(l,md),gao(md+1,r));
	VI v;
	rep(i,l,r+1) if (sq(md-i)<d) v.pb(i);
	sort(all(v),[&](int i,int j) {
		return y[i]<y[j];
	});
	rep(i,0,SZ(v)) rep(j,1,8) if (i+j<SZ(v))
		d=min(d,dist(v[i],v[i+j]));
	return d;
}

int main() {
	scanf("%d",&n);
	ll s=0;
	rep(i,1,n+1) {
		int a;
		scanf("%d",&a);
		s+=a; x[i]=i; y[i]=s;
	}
	printf("%lld",gao(1,n));
}