#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=25;
int n,a[N],_;
void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	int g=a[1];
	rep(i,2,n+1) g=__gcd(g,a[i]);
	if (g==1) {
		puts("0");
	} else {
		int ans=(n<=2?n:3);
		rep(i,1,n+1) {
			g=0;
			rep(j,1,n+1) {
				if (i==j) g=__gcd(g,__gcd(a[j],j));
				else g=__gcd(g,a[j]);
			}
			if (g==1) ans=min(ans,n-i+1);
		}
		printf("%d\n",ans);
	}
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}