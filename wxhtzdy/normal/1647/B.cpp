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
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=105;
int _,n,m,a[N][N];
char s[N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&m);
		rep(i,0,n) {
			scanf("%s", s);
			rep(j,0,m) a[i][j]=s[j]-'0';
		}
		bool ok=true;
		rep(i,0,n-1) rep(j,0,m-1) {
			int cc=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
			if (cc==3) ok=false;
		}
		puts(ok?"YES":"NO");
	}	
}